#include "Landscape.h"
#include <corecrt_math_defines.h>

Landscape::Landscape(LandscapeGenerator* land, LandscapeGenerator* sky)
{
	for (int i = 0; i < 4; i++) {
		m_land[i] = new ColoredGameObject(
			Transform(
				D3DXVECTOR3(200 * (i % 2), -10.f, 200 * (i / 2)),
				D3DXVECTOR3(M_PI_2, 0.f, 0.f),
				D3DXVECTOR3(1.f, 1.f, 1.f)),
			new ColoredMeshRenderer(land));
		m_sky[i] = new ColoredGameObject(
			Transform(
				D3DXVECTOR3(200 * (i % 2), 50.f, 200 * (i / 2)),
				D3DXVECTOR3(-M_PI_2, 0.f, 0.f),
				D3DXVECTOR3(1.f, 1.f, 1.f)),
			new ColoredMeshRenderer(sky));
	}
}

Landscape::~Landscape()
{
}



ColoredGameObject** Landscape::GetLand()
{
	return m_land;
}

ColoredGameObject** Landscape::GetSky()
{
	return m_sky;
}

void Landscape::Update(Camera* camera)
{
	int xGridCam = camera->GetTransform().m_position.x / 200;
	if (camera->GetTransform().m_position.x < 0) {
		xGridCam = xGridCam - 1;
	}
	int zGridCam = camera->GetTransform().m_position.z / 200;

	int xGrid = m_land[0]->GetTransform().m_position.x / 200;
	int zGrid = m_land[0]->GetTransform().m_position.z / 200;

	if((xGridCam != xGrid)||(zGridCam != zGrid)) MoveTerrain(xGridCam, zGridCam);
}

void Landscape::MoveTerrain(int x, int z)
{
	for (int i = 0; i < 4; i++) {
		float newX = 200 * ((i % 2) + x);
		float newZ = 200 * ((i / 2) + z);
		Transform newLT = m_land[i]->GetTransform();
		newLT.SetPosition(D3DXVECTOR3(newX, -10.f, newZ));
		Transform newST = m_sky[i]->GetTransform();
		newST.SetPosition(D3DXVECTOR3(newX, 50.f, newZ));
		/*m_land[i]->GetTransform().SetPosition(D3DXVECTOR3(newX, -10.f, newZ));
		m_sky[i]->GetTransform().SetPosition(D3DXVECTOR3(newX, 50.f, newZ));*/
		m_land[i]->SetTransform(newLT);
		m_sky[i]->SetTransform(newST);
	}
}
