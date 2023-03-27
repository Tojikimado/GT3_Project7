#include "GenerateSpaceships.h"

GenerateSpaceships::GenerateSpaceships(Camera* camera, ColoredMesh* mesh)
{
    pCamera = camera;
    sMesh = mesh;
}

Spaceship* GenerateSpaceships::CreateSpaceShip()
{
    int xPos = rand() % 19 - 9;
    int yPos = rand() % 15 - 7;
    Transform sTransform = pCamera->GetTransform();
    sTransform.SetPosition(D3DXVECTOR3(sTransform.m_position.x + xPos, sTransform.m_position.y + yPos, sTransform.m_position.z + 20));
    return new Spaceship(sTransform, sMesh);
}
