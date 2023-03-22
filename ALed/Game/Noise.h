#pragma once
class Noise
{

private : 
	float* p_NoiseSeed1D;
	float* p_PerlinNoise1D;

public: 
	int OutputSize = 256;

	Noise(float seed);

	float* PerlinNoise1D(int count,int octaves);
};

