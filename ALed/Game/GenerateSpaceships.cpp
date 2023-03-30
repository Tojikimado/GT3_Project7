#include "GenerateSpaceships.h"

GenerateSpaceships::GenerateSpaceships(Camera* camera, ColoredMeshRenderer* meshR)
{
    pCamera = camera;
    sMeshR = meshR;
}

GenerateSpaceships::~GenerateSpaceships()
{
}

Spaceship* GenerateSpaceships::CreateSpaceShip()
{
    int xPos = rand() % 19 - 9;
    int yPos = rand() % 15 - 7;
    Transform sTransform = pCamera->GetTransform();
    sTransform.SetPosition(D3DXVECTOR3(sTransform.m_position.x + xPos, sTransform.m_position.y + yPos, sTransform.m_position.z + 50));
    sTransform.SetScale(D3DXVECTOR3(0.003f, 0.004f, 0.003f));
    return new Spaceship(sTransform, sMeshR);
}

Spaceship* GenerateSpaceships::Update(float dt)
{
    currentCooldown += dt;
    if (currentCooldown >= generationCooldown) {
        currentCooldown = 0.f;
        return CreateSpaceShip();
    }
    else {
        return nullptr;
    }
}
