#pragma once
#include <Spline.h>
#include <corecrt_math_defines.h>
namespace PlayerSplines 
{
	struct StraightSpline
	{
		StraightSpline(float length = 1.f)
		{
			sPoints[0] = { Transform() };
			sPoints[1] = { Transform(D3DXVECTOR3(0.f, 0.f, 1.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[2] = { Transform(D3DXVECTOR3(0.f, 0.f, 2.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(0.f, 0.f, 3.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(0.f, 0.f, 4.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 5);
		}
		SplinePoint* sPoints = new SplinePoint[5];

		Spline* spline;
	}; 
	struct StraightSpinSpline
	{
		StraightSpinSpline(float length = 1.f)
		{
			sPoints[0] = { Transform() };
			sPoints[1] = { Transform(D3DXVECTOR3(0.f, 0.f, 1.f) * length, D3DXVECTOR3(0, 0, M_PI_2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[2] = { Transform(D3DXVECTOR3(0.f, 0.f, 2.f) * length, D3DXVECTOR3(0, 0, M_PI), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(0.f, 0.f, 3.f) * length, D3DXVECTOR3(0, 0, 3*M_PI_2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(0.f, 0.f, 4.f) * length, D3DXVECTOR3(0, 0, 2*M_PI), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 5);
		}
		SplinePoint* sPoints = new SplinePoint[5];

		Spline* spline;
	};

	struct RightStrafSpline
	{
		RightStrafSpline(float length = 1.f)
		{
			sPoints[0] = { Transform() };
			sPoints[1] = { Transform(D3DXVECTOR3(0.f, 0.f, 1.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[2] = { Transform(D3DXVECTOR3(1.322875656f, 0.f, 1.5f) * length, D3DXVECTOR3(- M_PI_4 / 2, M_PI_4 / 2, -M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(2.436698586f, 0.f, 1.75f) * length, D3DXVECTOR3(-M_PI_4, M_PI_4, -M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(3.464101615f, 0.f, 2.f) * length, D3DXVECTOR3(-(3 * M_PI_4) / 2, (3* M_PI_4) / 2, -M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[5] = { Transform(D3DXVECTOR3(4.582575695f, 0.f, 2.f) * length, D3DXVECTOR3(-M_PI_2, M_PI_2, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[6] = { Transform(D3DXVECTOR3(5.562148865f, 0.f, 2.25f) * length, D3DXVECTOR3((3 * M_PI_4) / 2, (3 * M_PI_4) / 2, M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[7] = { Transform(D3DXVECTOR3(6.538348415f, 0.f, 2.5f) * length, D3DXVECTOR3(M_PI_4, M_PI_4, M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[8] = { Transform(D3DXVECTOR3(7.416198487f, 0.f, 3.f) * length, D3DXVECTOR3(M_PI_4/2, M_PI_4 / 2, M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[9] = { Transform(D3DXVECTOR3(8.062257748f, 0.f, 4.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 10);
		}
		SplinePoint* sPoints = new SplinePoint[10];

		Spline* spline;
	};
	struct LeftStrafSpline
	{
		LeftStrafSpline(float length = 1.f)
		{
			sPoints[0] = { Transform() };
			sPoints[1] = { Transform(D3DXVECTOR3(0.f, 0.f, 1.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[2] = { Transform(D3DXVECTOR3(-1.322875656f, 0.f, 1.5f) * length, D3DXVECTOR3(-M_PI_4 / 2, -M_PI_4 / 2, M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(-2.436698586f, 0.f, 1.75f) * length, D3DXVECTOR3(-M_PI_4, -M_PI_4, M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(-3.464101615f, 0.f, 2.f) * length, D3DXVECTOR3(-(3 * M_PI_4) / 2, -(3 * M_PI_4) / 2, M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[5] = { Transform(D3DXVECTOR3(-4.582575695f, 0.f, 2.f) * length, D3DXVECTOR3(-M_PI_2, -M_PI_2, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[6] = { Transform(D3DXVECTOR3(-5.562148865f, 0.f, 2.25f) * length, D3DXVECTOR3((3 * M_PI_4) / 2, -(3 * M_PI_4) / 2, -M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[7] = { Transform(D3DXVECTOR3(-6.538348415f, 0.f, 2.5f) * length, D3DXVECTOR3(M_PI_4, -M_PI_4, -M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[8] = { Transform(D3DXVECTOR3(-7.416198487f, 0.f, 3.f) * length, D3DXVECTOR3(M_PI_4/2, -M_PI_4 / 2, -M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[9] = { Transform(D3DXVECTOR3(-8.062257748f, 0.f, 4.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 10);
		}
		SplinePoint* sPoints = new SplinePoint[10];

		Spline* spline;
	};
	struct LoopingSpline
	{
		LoopingSpline(float length = 1.f)
		{
			sPoints[0] = { Transform() };
			sPoints[1] = { Transform(D3DXVECTOR3(0.f, 0.f, 2.f) * length, D3DXVECTOR3(-M_PI_4 / 4, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[2] = { Transform(D3DXVECTOR3(0.f, 0.5f, 4.f) * length, D3DXVECTOR3(-M_PI_4 / 2, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(0.f, 1.f, 5.f) * length, D3DXVECTOR3(-M_PI_4, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(0.f, 2.5f, 5.25f) * length, D3DXVECTOR3(-M_PI_2, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[5] = { Transform(D3DXVECTOR3(0.f, 3.f, 5.f) * length, D3DXVECTOR3(-(M_PI_2 + M_PI_4 / 2), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f))};
			sPoints[6] = { Transform(D3DXVECTOR3(0.f, 3.5f, 4.75f) * length, D3DXVECTOR3(-(M_PI_2 + M_PI_4), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[7] = { Transform(D3DXVECTOR3(0.f, 3.75f, 4.25f) * length, D3DXVECTOR3(-(M_PI_2 + 3 * M_PI_4 / 2), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[8] = { Transform(D3DXVECTOR3(0.f, 4.f, 4.f) * length, D3DXVECTOR3(-M_PI, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f))};
			sPoints[9] = { Transform(D3DXVECTOR3(0.f, 4.f, 3.5f) * length, D3DXVECTOR3(-(M_PI + M_PI_4), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f))};
			sPoints[10] = { Transform(D3DXVECTOR3(0.f, 3.75f, 2.5f) * length, D3DXVECTOR3(-(M_PI + M_PI_2), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[11] = { Transform(D3DXVECTOR3(0.f, 3.f, 2.f) * length, D3DXVECTOR3(-(M_PI + M_PI_2 + M_PI_4 / 2), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[12] = { Transform(D3DXVECTOR3(0.f, 1.f, 2.5f) * length, D3DXVECTOR3(-(M_PI + M_PI_2 + M_PI_4), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[13] = { Transform(D3DXVECTOR3(0.f, 0.f, 4.f) * length, D3DXVECTOR3(-(M_PI + M_PI_2 + 3*M_PI_4 / 2), 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[14] = { Transform(D3DXVECTOR3(0.f, 0.f, 6.f) * length, D3DXVECTOR3(-2* M_PI, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 15);
		}
		SplinePoint* sPoints = new SplinePoint[15];

		Spline* spline;
	};
}

namespace EnemiesSplines {

}