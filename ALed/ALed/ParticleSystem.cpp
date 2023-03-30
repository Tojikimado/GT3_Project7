#include "ParticleSystem.h"


ParticleSystem::ParticleSystem()
{
}

ParticleSystem::~ParticleSystem()
{
}

HRESULT ParticleSystem::Init(IDirect3DDevice9* device, int maxParticles)
{
	m_renderTarget = device;
	m_maxParticles = maxParticles;
	m_particlePool.resize(maxParticles);
	m_poolIndex = m_particlePool.size() - 1;

	int buffer_size = m_maxParticles * sizeof(PARTICLE_FVF);

	if (FAILED(m_renderTarget->CreateVertexBuffer(buffer_size, 0, PARTICLE_FVF, D3DPOOL_DEFAULT, &m_points, NULL)))
	{
		return E_FAIL; /*Return if the vertex buffer culd not be created.*/
	}
}

void ParticleSystem::Update(float dt)
{
	for (auto& particle : m_particlePool)
	{
		if (!particle.isActive)
			continue;

		if (particle.lifeRemaining <= 0.0f)
		{
			particle.isActive = false;
			continue;
		}

		particle.lifeRemaining -= dt;
		particle.transform.SetPosition(particle.transform.m_position += particle.velocity * dt);
		//particle.Rotation += 0.01f * dt;
		//particle.transform.SetRotation()
	}
}

void ParticleSystem::Render()
{
	for (auto& particle : m_particlePool)
	{
		if (particle.isActive == false)
			continue;

		// Fade away particles
		float life = particle.lifeRemaining / particle.lifetime;
		D3DXCOLOR color;

		D3DXColorLerp(&color, &particle.colourEnd, &particle.colourBegin, life);
		color.a *= life;
		float size = Lerp(particle.sizeEnd, particle.sizeBegin, life);

		particle.transform.SetPosition(particle.transform.m_position);
		particle.transform.SetScale(D3DXVECTOR3(size, size, size));

		// Render

		m_renderTarget->SetFVF(PARTICLE_FVF);
		D3DXMATRIX particleTransform = m_particlePool[particle.id].transform.GetWorld();

		m_renderTarget->SetTransform(D3DTS_WORLD, &(particleTransform));

		D3DMATERIAL9 mat;
		mat.Diffuse = color;
		mat.Emissive = color;

		m_renderTarget->SetMaterial(&mat);
		m_renderTarget->SetTexture(0, NULL);
		mesh->DrawSubset(0);
	}
}

void ParticleSystem::Emit(const ParticleProps& particleProps)
{
	Particle& particle = m_particlePool[m_poolIndex];

	particle.id = m_poolIndex;
	particle.isActive = true;
	particle.transform.m_position = particleProps.transform.m_position;
	/*particle.Rotation = Random::Float() * 2.0f * glm::pi<float>();*/

	// Velocity
	particle.velocity = particleProps.velocity;
	particle.velocity.x += particleProps.velocityVariation.x * (Random::Float() - 0.5f);
	particle.velocity.y += particleProps.velocityVariation.y * (Random::Float() - 0.5f);

	// Color
	particle.colourBegin = particleProps.colourBegin;
	particle.colourEnd = particleProps.colourEnd;

	particle.lifetime = particleProps.lifetime;
	particle.lifeRemaining = particleProps.lifetime;
	particle.sizeBegin = particleProps.sizeBegin + particleProps.sizeVariation * (Random::Float() - 0.5f);
	particle.sizeEnd = particleProps.sizeEnd;

	m_poolIndex = --m_poolIndex % m_particlePool.size();
}


