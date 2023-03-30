#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "Transform.h"
#include "ColoredMesh.h"

// data structure for a particle
struct Particle
{
	int			lifetime;
	Transform	transform;
	ColoredMesh* mesh;
	D3DXVECTOR3 origin;
	D3DXVECTOR3 velocity;
	D3DXCOLOR	colour;
	float		time;
	float		size;
};

// A structure for point sprites.
struct POINTVERTEX
{
	D3DXVECTOR3 position;		
	DWORD color;				
};

// The structure of a vertex in our vertex buffer
#define D3DFVF_POINTVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)

#define SAFE_DELETE(p)       {if(p) {delete (p);     (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[] (p);   (p)=NULL;}}
#define SAFE_RELEASE(p)      {if(p) {(p)->Release(); (p)=NULL;}}

#define reset_particle(p) SecureZeroMemory(&p, sizeof(Particle));