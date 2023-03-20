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

namespace d3dCollision 
{
	struct WidhtHeightDepth
	{
		WidhtHeightDepth(float _maxW, float _maxH, float _maxD, float _minW, float _minH, float _minD)
		{
			maxX = _maxW;
			maxY = _maxH;
			maxZ = _maxD;
			minX = _minW;
			minY = _minH;
			minZ = _minD;
		}

		WidhtHeightDepth()
		{
			maxX = 0.f;
			maxY = 0.f;
			maxZ = 0.f;
			minX = 0.f;
			minY = 0.f;
			minZ = 0.f;
		}

		float maxX, maxY, maxZ;
		float minX, minY, minZ;
	};
}