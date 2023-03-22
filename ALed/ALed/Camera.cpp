#include "Camera.h"
#include "STimer.h"


Camera::Camera(int width, int height, Transform camTransform)
{
    _width = width;
    _height = height;
    transform = camTransform;
    _fov = D3DX_PI / 2;
    _zNear = 1.0f;
    _zFar = 100.f;

    _pitch = D3DXToRadian(transform.GetRotation().x);
    _yaw = D3DXToRadian(transform.GetRotation().y);
    _roll = D3DXToRadian(transform.GetRotation().z);

    _vUp = D3DXVECTOR3(0.f, 1.f, 0.f);
    _vForward = D3DXVECTOR3(0.f, 0.f, 1.f);

    D3DXVECTOR3 tempPos = transform.GetPosition();
    D3DXMatrixPerspectiveFovLH(&_matProjection, _fov, FLOAT(width) / FLOAT(height), _zNear, _zFar);
    D3DXMatrixLookAtLH(&_matView, &tempPos, &_vForward, &_vUp);
    D3DXMatrixIdentity(&_matIdentity);

}

Camera::Camera(int width, int height, Transform camTransform, float fov, float zNear, float zFar)
{
    _width = width;
    _height = height;
    transform = camTransform;
    _fov = fov;
    _zNear = zNear;
    _zFar = zFar;

    _pitch = D3DXToRadian(transform.GetRotation().x);
    _yaw = D3DXToRadian(transform.GetRotation().y);
    _roll = D3DXToRadian(transform.GetRotation().z);

    _vUp = D3DXVECTOR3(0.f, 1.f, 0.f);
    _vForward = D3DXVECTOR3(0.f, 0.f, 1.f);

    D3DXVECTOR3 tempPos = transform.GetPosition();
    D3DXMatrixPerspectiveFovLH(&_matProjection, _fov, FLOAT(width) / FLOAT(height), _zNear, _zFar);
    D3DXMatrixLookAtLH(&_matView, &tempPos, &_vForward, &_vUp);
    D3DXMatrixIdentity(&_matIdentity);

}

Camera::~Camera()
{

}

void Camera::Update(IDirect3DDevice9* device)
{

    _pitch = D3DXToRadian(transform.GetRotation().x);
    _yaw = D3DXToRadian(transform.GetRotation().y);
    _roll = D3DXToRadian(transform.GetRotation().z);

    //_pitch += D3DXToRadian(5.f) * STimer::s_deltaTime;

    transform.SetRotation(D3DXVECTOR3(_pitch, _yaw, _roll));

    // Rotation matrix
    D3DXMatrixRotationYawPitchRoll(&_matLook, _pitch, _yaw, _roll);
    D3DXVec3TransformCoord(&_vForward, &_vForward, &_matLook);

    D3DXVECTOR3 pos = transform.GetPosition();
    D3DXVECTOR3 at;
    at = pos + _vForward;

    // Update projection matrix of the camera
    D3DXMatrixPerspectiveFovLH(&_matProjection, _fov, FLOAT(_width) / FLOAT(_height), _zNear, _zFar);
    // Update where the camera look at matrix
    D3DXMatrixLookAtLH(&_matView, &pos, &at, &_vUp);

    SetTransform(device);
}

void Camera::SetTransform(IDirect3DDevice9* device) const
{
    device->SetTransform(D3DTS_PROJECTION, &_matProjection);
    device->SetTransform(D3DTS_WORLD, &_matIdentity);
    device->SetTransform(D3DTS_VIEW, &_matView);
}
