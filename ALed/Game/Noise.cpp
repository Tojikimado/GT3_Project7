#include "Noise.h"

Noise::Noise(float seed) : p_PerlinNoise1D(&seed)
{
}

float* Noise::PerlinNoise1D(int count,int octaves)
{
	float* output = new float[count];
	float f_noise = 0.0f;
	float f_scale = 1.0f;
	float f_scaleAcc = 0.0f;

	for (int x = 0; x < count; x++)
	{
		for (int o = 0; o < octaves; o++)
		{
			int n_pitch = count >> o;
			int n_sample1 = (x / n_pitch) * n_pitch;
			int n_sample2 = (n_sample1 + n_pitch) % count;

			float f_blend = (float)(x - n_sample1) / (float)n_pitch;
			float f_sample = (1.0f - f_blend) * p_NoiseSeed1D[n_sample1] + f_blend * p_NoiseSeed1D[n_sample2];
			f_noise += f_sample * f_scale;
			f_scaleAcc += f_scale;
			f_scale = f_scale / 2.0f;
		}

		output[x] = f_noise / f_scaleAcc;
	}

	return output;
}
