#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(IDirect3DDevice9* device, Transform startTransform, int maxParticles, int maxLifetime, float maxSize, float startInterval, float startSpeed, float duration)
{

	m_renderTarget = device;
	m_transform = startTransform;
	m_maxParticles = maxParticles;
	m_maxLifetime = maxLifetime;
	m_maxSize = maxSize;
	m_startInterval = startInterval;

	m_transform.m_scale = D3DXVECTOR3(maxSize, maxSize, maxSize);

	
	Particle p;

	reset_particle(p);
	m_particles.resize(m_maxParticles, p);

	int buffer_size = m_maxParticles * sizeof(POINTVERTEX);

	// The data in the buffer doesn't exist at this point, but the memory space
	// is allocated and the pointer to it (g_pPointBuffer) also exists.
	if (FAILED(device->CreateVertexBuffer(buffer_size, 0, D3DFVF_POINTVERTEX, D3DPOOL_DEFAULT, &m_points, NULL)))
	{
		/*return E_FAIL;*/ // Return if the vertex buffer culd not be created.
	}
}

ParticleSystem::~ParticleSystem()
{
	SAFE_RELEASE(m_points)
}

void ParticleSystem::Update()
{
}

void ParticleSystem::Render()
{

	m_renderTarget->SetRenderState(D3DRS_POINTSPRITEENABLE, true);
	m_renderTarget->SetRenderState(D3DRS_POINTSCALEENABLE, true);

	// Disable z buffer while rendering the particles. Makes rendering quicker and
	// stops any visual (alpha) 'artefacts' on screen while rendering.
	m_renderTarget->SetRenderState(D3DRS_ZENABLE, false);

	// Scale the points according to distance...
	m_renderTarget->SetRenderState(D3DRS_POINTSIZE, FtoDW(m_maxSize));
	m_renderTarget->SetRenderState(D3DRS_POINTSIZE_MIN, FtoDW(0.00f));
	m_renderTarget->SetRenderState(D3DRS_POINTSCALE_A, FtoDW(0.00f));
	m_renderTarget->SetRenderState(D3DRS_POINTSCALE_B, FtoDW(0.00f));
	m_renderTarget->SetRenderState(D3DRS_POINTSCALE_C, FtoDW(1.00f));

	// Now select the texture for the points...
	// Use texture colour and alpha components.
	m_renderTarget->SetTexture(0, m_particleTex);
	m_renderTarget->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	m_renderTarget->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_renderTarget->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	m_renderTarget->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_renderTarget->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);

	m_renderTarget->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_renderTarget->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

	// Render the contents of the vertex buffer.
	m_renderTarget->SetStreamSource(0, m_points, 0, sizeof(POINTVERTEX));
	m_renderTarget->SetFVF(D3DFVF_POINTVERTEX);
	m_renderTarget->DrawPrimitive(D3DPT_POINTLIST, 0, m_particlesAlive);

	// Reset the render states.
	m_renderTarget->SetRenderState(D3DRS_POINTSPRITEENABLE, false);
	m_renderTarget->SetRenderState(D3DRS_POINTSCALEENABLE, false);
	m_renderTarget->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	m_renderTarget->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
	m_renderTarget->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
}

std::vector<Particle>::iterator ParticleSystem::FindNextDeadParticle()
{
	m_deadParticles = std::find_if(m_particles.begin(), m_particles.end(), IsParticleDead());
	return m_deadParticles;
}
	

void ParticleSystem::StartParticles()
{
	// Only start a new particle when the time is right and there are enough dead (inactive) particles.
	if (m_startTimer == 0 && m_particlesAlive < m_maxParticles)
	{
		// Number of particles to start in this batch...
		for (int i(0); i < m_startParticles; ++i)
		{
			if (m_particlesAlive < m_maxParticles)
			{
				FindNextDeadParticle();
				StartSingleParticle(m_deadParticles);
			}
		}

		// Reset the start timer for the next batch of particles.
		m_startTimer = m_startInterval;
	}
	else
	{
		// Otherwise decrease the start timer.
		--m_startTimer;
	}
}

void ParticleSystem::StartSingleParticle(std::vector<Particle>::iterator& p)
{
	if (p == m_particles.end()) return;

	p->id = 0;

	p->position = m_origin;

	p->lifetime = random_number(0, m_maxLifetime);

	++m_particlesAlive;
}

float ParticleSystem::random_number(unsigned int a, unsigned int b)
{
	// prevent division by zero as part of modulus calculation below
	if (b == a)
		return 0;

	return a + (rand() % (b - a));
}
