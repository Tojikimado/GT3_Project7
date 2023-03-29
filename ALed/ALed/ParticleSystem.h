#pragma once
#include <vector>
#include <algorithm> 
#include "ParticleData.h"
#include "STimer.h"

#define D3DFVF_POINTVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)


class ParticleSystem
{
public:

	ParticleSystem(IDirect3DDevice9* device, LPDIRECT3DTEXTURE9 texture, Transform startPos, int maxParticles, int maxLifetime, float maxSize, float startInterval, float startSpeed, float duration, bool isLooping);
	~ParticleSystem();

	virtual void Update();
	virtual void Render();

	bool isLooping = false;

protected:

	Transform m_transform;

	std::vector<Particle*>	m_particles;
	int m_particlesAlive;
	LPDIRECT3DVERTEXBUFFER9 m_points;
	IDirect3DDevice9*		m_renderTarget;

	float m_maxSize;
	LPDIRECT3DTEXTURE9 m_particleTex;
	
	void RemoveDeadParticles();
	virtual void StartParticles();

	virtual void StartSingleParticle();

	static float random_number(unsigned int a, unsigned int b);

	static inline DWORD FtoDW(float f)
	{
		return *((DWORD*)&f);
	}
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

	D3DXVECTOR3 m_origin;

	float m_startTimer;
	float m_startInterval;


	int m_maxParticles;
	int m_startParticles;

	int m_maxLifetime;

	D3DXVECTOR3 m_startPos;

	std::vector<Particle>::iterator m_deadParticles;


	

};

