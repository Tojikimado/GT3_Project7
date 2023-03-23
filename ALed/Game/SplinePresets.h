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
			sPoints[2] = { Transform(D3DXVECTOR3(0.25f, 0.f, 1.5f) * length, D3DXVECTOR3(- M_PI_4 / 2, M_PI_4 / 2, -M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(0.75f, 0.f, 1.75f) * length, D3DXVECTOR3(-M_PI_4, M_PI_4, -M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(1.75f, 0.f, 2.f) * length, D3DXVECTOR3(-(3 * M_PI_4) / 2, (3* M_PI_4) / 2, -M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[5] = { Transform(D3DXVECTOR3(2.75f, 0.f, 2.f) * length, D3DXVECTOR3(0, M_PI_2, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[6] = { Transform(D3DXVECTOR3(3.5f, 0.f, 2.25f) * length, D3DXVECTOR3(0, (3 * M_PI_4) / 2, M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[7] = { Transform(D3DXVECTOR3(4.f, 0.f, 2.5f) * length, D3DXVECTOR3(0, M_PI_4, M_PI_4), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[8] = { Transform(D3DXVECTOR3(4.25f, 0.f, 3.f) * length, D3DXVECTOR3(0, M_PI_4 / 2, M_PI_4 / 2), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[9] = { Transform(D3DXVECTOR3(4.25f, 0.f, 4.f) * length, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 10);
		}
		SplinePoint* sPoints = new SplinePoint[10];

		Spline* spline;
	};
}

namespace EnemiesSplines {

}