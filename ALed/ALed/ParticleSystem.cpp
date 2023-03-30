#include "ParticleSystem.h"


ParticleSystem::ParticleSystem(IDirect3DDevice9* device, LPDIRECT3DTEXTURE9 texture, Transform startTransform, int maxParticles, int maxLifetime, float maxSize, float startInterval, float startSpeed, float duration, bool isLooping_)
{
	
	m_renderTarget = device;
	m_particleTex = texture;
	m_transform = startTransform;
	m_maxParticles = maxParticles;
	m_maxLifetime = maxLifetime;
	m_maxSize = maxSize;
	m_startInterval = startInterval;
	isLooping = isLooping_;

	m_transform.m_scale = D3DXVECTOR3(maxSize, maxSize, maxSize);
	m_particlesAlive = 0;
	m_startParticles = 0;
	m_startTimer = 0;

	
	Particle p;

	reset_particle(p);
	//m_particles.resize(m_maxParticles, p);

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


void ParticleSystem::RemoveDeadParticles()
{
	for (std::vector<Particle*>::reverse_iterator it = m_particles.rbegin(); it != m_particles.rend(); )
	{
		if ((*it)->lifetime <= 0)
		{
			delete* it;
			//it = m_particles.erase(it);
		}
	}

	for (int i = m_particles.size() - 1; i != 0; i--)
	{
		/*
		if (m_particles[i].lifetime <= 0)
		{
			m_particles.erase(std::next(m_particles.begin() + i));
		}
		*/
	}

	for (Particle* particle : m_particles)
	{

	}
}
	

void ParticleSystem::StartParticles()
{
	if (m_startTimer <= 0 && m_particlesAlive < m_maxParticles)
	{
		// Only spawn missing particles
		/*m_startParticles = m_maxParticles - m_particlesAlive;*/

		// Number of particles to start in this batch...
		for (int i(0); i < m_maxParticles; ++i)
		{
			if (m_particlesAlive < m_maxParticles)
			{
				RemoveDeadParticles();
				StartSingleParticle();
			}
		}

		// Reset the start timer for the next batch of particles.
		m_startTimer = m_startInterval;
	}
	else
	{
		// Otherwise decrease the start timer.
		--m_startTimer -= STimer::s_deltaTime;
	}
}

void ParticleSystem::StartSingleParticle()
{
	Particle* p = new Particle();

	p->mesh = new ColoredMesh();
	p->transform.SetPosition(m_origin);
	p->lifetime = random_number(0, m_maxLifetime);

	m_particles.push_back(p);
	++m_particlesAlive;
}





float ParticleSystem::random_number(unsigned int a, unsigned int b)
{
	// prevent division by zero as part of modulus calculation below
	if (b == a)
		return 0;

	return a + (rand() % (b - a));
}

