#pragma once
#include <vector>
#include <algorithm> 
#include "ParticleData.h"
#include "Transform.h"

#define D3DFVF_POINTVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)


class ParticleSystem
{
public:

	ParticleSystem(IDirect3DDevice9* device, Transform startPos, int maxParticles, int maxLifetime, float maxSize, float startInterval, float startSpeed, float duration);
	~ParticleSystem();

	virtual void Update();
	virtual void Render();

protected:

	Transform m_transform;

	std::vector<Particle>	m_particles;
	LPDIRECT3DVERTEXBUFFER9 m_points;
	IDirect3DDevice9*		m_renderTarget;

	std::vector<Particle>::iterator FindNextDeadParticle();
	virtual void StartParticles();

	virtual void StartSingleParticle(std::vector<Particle>::iterator& p);

	static float random_number(unsigned int a, unsigned int b);

private:


	class IsParticleDead			// This is a private class, only available inside 'PARTICLE_SYSTEM_BASE' - functor to determine if a particle is alive or dead.
	{
	public:
		bool operator()(const Particle& p)
		{
			return p.lifetime == 0;
		}
	};


	/*inline bool IsParticleDead(const Particle &p) { return p.lifetime == 0; }*/

	LPDIRECT3DTEXTURE9 m_particleTex;
	D3DXVECTOR3 m_origin;

	float m_startTimer;
	float m_startInterval;

	int m_maxParticles;
	int m_startParticles;

	int m_particlesAlive;
	int m_maxLifetime;

	float m_maxSize;

	D3DXVECTOR3 m_startPos;

	std::vector<Particle>::iterator m_deadParticles;


	static inline DWORD FtoDW(float f)
	{
		return *((DWORD*)&f);
	}

};

