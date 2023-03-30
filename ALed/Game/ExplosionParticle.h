#pragma once
#include <ParticleSystem.h>
class ExplosionParticle : public ParticleSystem
{
public: 
	ExplosionParticle(IDirect3DDevice9* device, LPDIRECT3DTEXTURE9 texture, Transform startPos, int maxParticles, int maxLifetime,
					float maxSize, float startInterval, float startSpeed, float duration, bool isLooping);

	~ExplosionParticle();

	virtual void Update();
	virtual void Render();

private:

	D3DXCOLOR m_baseColour;

	

};

