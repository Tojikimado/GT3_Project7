#include "ExplosionParticle.h"

ExplosionParticle::ExplosionParticle(IDirect3DDevice9* device, Transform startPos, int maxParticles, int maxLifetime, float maxSize, float startInterval, float startSpeed, float duration) :
	ParticleSystem(device, startPos, maxParticles, maxLifetime, maxSize, startInterval, startSpeed, duration)
{
}
