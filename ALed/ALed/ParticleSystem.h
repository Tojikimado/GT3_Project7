#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <algorithm>

#include "Random.h"
#include "Transform.h"
#include "ColoredMesh.h"
#include "STimer.h"


struct ParticleProps
{
	Transform transform;
	D3DXVECTOR3 velocity, velocityVariation;
	D3DXCOLOR colourBegin, colourEnd;
	float sizeBegin, sizeEnd, sizeVariation;
	float lifetime;

};

#define PARTICLE_FVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

class ParticleSystem
{

public:
	LPD3DXMESH mesh = nullptr;


	ParticleSystem();
	~ParticleSystem();

	HRESULT Init(IDirect3DDevice9* device, int maxParticles);

	virtual void Update(float dt);
	virtual void Render();

	void Emit(const ParticleProps& particle);

protected:

	Transform m_transform;

	struct Particle
	{
		int id = 0;
		Transform transform;
		D3DXVECTOR3 velocity;
		D3DXCOLOR colourBegin, colourEnd;
		float lifetime = 1.0f;
		float lifeRemaining = 0.0f;
		float sizeBegin, sizeEnd;

		bool isActive = false;
	};

	std::vector<Particle>	m_particlePool;
	uint32_t m_poolIndex;


	LPDIRECT3DVERTEXBUFFER9 m_points;
	IDirect3DDevice9*		m_renderTarget;

	ParticleProps m_particleProps;

	float m_maxSize;

	static inline float Lerp(float a, float b, float alpha) { return a + alpha * (b - a); }
	
private:
	
	
	int m_maxParticles;

};



