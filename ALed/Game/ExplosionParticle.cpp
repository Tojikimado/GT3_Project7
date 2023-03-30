#include "ExplosionParticle.h"

ExplosionParticle::ExplosionParticle(IDirect3DDevice9* device, LPDIRECT3DTEXTURE9 texture, Transform startPos, int maxParticles, int maxLifetime,
									float maxSize, float startInterval, float startSpeed, float duration, bool isLooping) :
ParticleSystem(device, texture, startPos, maxParticles, maxLifetime, maxSize, startInterval, startSpeed, duration, isLooping)
	/*baseColour_(1.0f, 1.0f, 1.0f, 1.0f),
	fadeOutTime_(0),
	maxColourDivergence_(0, 0, 0),
	maxLifetimeDivergence_(0),
	maxSizeDivergence_(0),
	maxVelocityDivergence_(0),
	launchvelocity(0)*/
{
}

ExplosionParticle::~ExplosionParticle()
{
}

void ExplosionParticle::Update()
{
	// Start particles, if necessary...
	StartParticles();
	int speed = 20;
	// Update the particles that are still alive...
	//for (std::vector<Particle>::iterator p(m_particles.begin()); p != m_particles.end(); ++p)
	//{
	//	if (p->lifetime > 0)	// Update only if this particle is alive.
	//	{

	//		p->lifetime -= STimer::s_deltaTime;
	//		// Calculate the new position of the particle...

	//		p->transform.SetPosition(D3DXVECTOR3(p->transform.m_position.x += speed * STimer::s_deltaTime,
	//								p->transform.m_position.y += speed * STimer::s_deltaTime,
	//								p->transform.m_position.z += speed * STimer::s_deltaTime));

	//		/*p->time += m_timeIncrement;*/
	//		//// update alpha value
	//		//if (p->lifetime < fadeOutTime)
	//		//{
	//		//	p->colour.a -= static_cast<float>(1) / fadeOutTime_;
	//		//}

	//		if (p->lifetime == 0)	// Has this particle come to the end of it's life?
	//		{
	//			--m_particlesAlive;		// If so, terminate it.
	//		}
	//	}
	//}

	// Create a pointer to the first vertex in the buffer
	// Also lock it, so nothing else can touch it while the values are being inserted.
	POINTVERTEX* points;
	m_points->Lock(0, 0, (void**)&points, 0);

	// Fill the vertex buffers with data...
	int P(0);

	// Now update the vertex buffer - after the update has been
	// performed, just in case this particle has died in the process.

	/*for (std::vector<Particle>::iterator p(m_particles.begin()); p != m_particles.end(); ++p)
	{
		if (p->lifetime > 0)
		{
			points[P].position.y = p->transform.m_position.y;
			points[P].position.x = p->transform.m_position.x;
			points[P].position.z = p->transform.m_position.z;

			points[P].color = p->colour;
			++P;
		}
	}*/

	m_points->Unlock();
}

void ExplosionParticle::Render()
{
	// Enable point sprites, and set the size of the point.
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

	// use the diffuse color of the particle
	m_renderTarget->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
	m_renderTarget->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);

	// modulate the alpha values of the particle and the texture 
	m_renderTarget->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_renderTarget->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	m_renderTarget->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	// Render the contents of the vertex buffer.
	m_renderTarget->SetStreamSource(0, m_points, 0, sizeof(POINTVERTEX));
	m_renderTarget->SetFVF(D3DFVF_POINTVERTEX);

	//for (unsigned int i = 0; i < m_particles.size(); ++i)
	//{
	//	if (m_particles[i].lifetime > 0)
	//	{
	//		// render the particle in its specific size
	//		m_renderTarget->SetRenderState(D3DRS_POINTSIZE, FtoDW(m_particles[i].size));
	//		m_renderTarget->DrawPrimitive(D3DPT_POINTLIST, i, 1);
	//	}
	//}

	// Reset the render states.
	m_renderTarget->SetRenderState(D3DRS_POINTSPRITEENABLE, false);
	m_renderTarget->SetRenderState(D3DRS_POINTSCALEENABLE, false);
	m_renderTarget->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	m_renderTarget->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);

	m_renderTarget->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
}



