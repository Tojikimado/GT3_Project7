#pragma once
#include <ParticleSystem.h>
class ExplosionParticle : public ParticleSystem
{
public: 
	ExplosionParticle(IDirect3DDevice9* device, Transform startPos, int maxParticles, int maxLifetime, float maxSize, float startInterval, float startSpeed, float duration);


private:
};

