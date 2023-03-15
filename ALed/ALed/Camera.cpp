#include "Camera.h"


Camera::Camera(int width, int height, D3DXVECTOR3 position, D3DXVECTOR3 target)
{
    this->width = width;
    this->height = height;
    this->position = position;
    this->fov = D3DX_PI / 4;
    this->zNear = 1.0f;
    this->zFar = 1000.f;

    //this->angle = angle;
    //this->scaleFactors = scaleFactors;

    D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

    /*D3DXMatrixOrthoLH(&matProjection, width, height, 1.0f, 1.0f);*/
    D3DXMatrixPerspectiveFovLH(&matProjection, fov, static_cast<float>(width) / static_cast<float>(height), zNear, zFar);
    D3DXMatrixLookAtLH(&matView, &position, &target, &up);
    D3DXMatrixIdentity(&matIdentity);
}

Camera::~Camera()
{

}

void Camera::Update()
{
    int cameraX = this->width / 2;
    int cameraY = this->height / 2;

    /* if (this->following && this->following->IsInitialized())
    {
        cameraX = this->following->position.x
        cameraY = this->following->position.y
    }
    */


    /*this->matView = D3DXMATRIX(scaleFactors.x * cos(angle), scaleFactors.x * sin(angle), 0, 0,
        -scaleFactors.y * sin(angle), scaleFactors.y * cos(angle), 0, 0,
        0, 0, scaleFactors.z, 0,
        -cameraX * scaleFactors.x * cos(angle) + cameraY * scaleFactors.y * sin(angle), -cameraX * scaleFactors.y * sin(angle) - cameraY * scaleFactors.y * cos(angle), 0, 1);*/
}

void Camera::SetTransform(IDirect3DDevice9* device) const
{
    device->SetTransform(D3DTS_PROJECTION, &matProjection);
    device->SetTransform(D3DTS_WORLD, &matIdentity);
    device->SetTransform(D3DTS_VIEW, &matView);
}


void Camera::Follow()
{

}

void Camera::Unfollow()
{

}
