#pragma once
#include <cmath>
#include<d3d9.h>
#include<d3dx9.h>

namespace d3dColors
{
	const D3DCOLOR Red = D3DCOLOR_ARGB(255,255,0,0);
	const D3DCOLOR Green = D3DCOLOR_ARGB(255,0,255,0);
	const D3DCOLOR Blue = D3DCOLOR_ARGB(255,0,0,255);
	const D3DCOLOR CornFlowerBlue = D3DCOLOR_ARGB(255, 100, 149, 237);
	const D3DCOLOR Black = D3DCOLOR_ARGB(255, 0, 0, 0);
	const D3DCOLOR DeepPink = D3DCOLOR_ARGB(255, 219, 112, 147);
	const D3DCOLOR Yellow = D3DCOLOR_ARGB(255, 255, 255, 0);
}

namespace d3dVertex
{
	struct VertexPositionColor
	{
		VertexPositionColor()
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
			color = d3dColors::DeepPink;
		}
		VertexPositionColor(float _x, float _y, float _z, D3DCOLOR _c)
		{
			x = _x;
			y = _y;
			z = _z;
			color = _c;
		}

		float x, y, z; //position
		D3DCOLOR color; //color

		static const DWORD FVF;
	};

	struct VertexPositionTexture
	{
		VertexPositionTexture()
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
			u = 0.f;
			v = 0.f;
		}

		VertexPositionTexture(float _x, float _y, float _z, float _u, float _v)
		{
			x = _x;
			y = _y;
			z = _z;
			u = _u;
			v = _v;
		}

		float x, y, z;
		float u, v;

		static const DWORD FVF;
	};
}

namespace d3Distance
{
	float Distance(D3DXVECTOR3 _A, D3DXVECTOR3 _B)
	{
		return sqrt(pow((_B.x - _A.x), 2) + pow((_B.y - _A.y), 2) + pow((_B.z - _A.z),2));
	}
}