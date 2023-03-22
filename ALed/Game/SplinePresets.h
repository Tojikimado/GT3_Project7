#pragma once
#include <Spline.h>
namespace PlayerSplines 
{
	struct StraightSpline
	{
		StraightSpline(float lenght = 1.f)
		{
			sPoints[0] = { Transform() };
			sPoints[1] = { Transform(D3DXVECTOR3(0.f, 0.f, 1.f) * lenght, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[2] = { Transform(D3DXVECTOR3(0.f, 0.f, 2.f) * lenght, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[3] = { Transform(D3DXVECTOR3(0.f, 0.f, 3.f) * lenght, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			sPoints[4] = { Transform(D3DXVECTOR3(0.f, 0.f, 4.f) * lenght, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.f, 1.f, 1.f)) };
			spline = new Spline(sPoints, 5);
		}
		SplinePoint* sPoints = new SplinePoint[5];

		Spline* spline;
	};
}

namespace EnemiesSplines {

}