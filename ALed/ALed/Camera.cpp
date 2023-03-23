#include "Camera.h"
#include "STimer.h"


Camera::Camera(IDirect3DDevice9* device, int width, int height, Transform camTransform)
{
    _device = device;
    _width = width;
    _height = height;
    m_transform = camTransform;
    _fov = D3DX_PI / 2;
    _zNear = 1.0f;
    _zFar = 100.f;

    D3DXVECTOR3 tempPos = m_transform.m_position;
    D3DXMatrixPerspectiveFovLH(&_matProjection, _fov, FLOAT(width) / FLOAT(height), _zNear, _zFar);
    D3DXMatrixLookAtLH(&_matView, &tempPos, &m_transform.m_direction, &m_transform.m_up);
    D3DXMatrixIdentity(&_matIdentity);

    SetTransform(_device);

}

Camera::Camera(IDirect3DDevice9* device, int width, int height, Transform camTransform, float fov, float zNear, float zFar)
{

    _device = device;
    _width = width;
    _height = height;
    m_transform = camTransform;
    _fov = fov;
    _zNear = zNear;
    _zFar = zFar;

    D3DXVECTOR3 tempPos = m_transform.m_position;
    D3DXMatrixPerspectiveFovLH(&_matProjection, _fov, FLOAT(width) / FLOAT(height), _zNear, _zFar);
    D3DXMatrixLookAtLH(&_matView, &tempPos, &m_transform.m_direction, &m_transform.m_up);
    D3DXMatrixIdentity(&_matIdentity);

    SetTransform(_device);

}

Camera::~Camera()
{

}

void Camera::Update(float dt)
{
    /*m_transform.Rotate( D3DX_PI / 2 * dt, 0.f, 0.f);*/

    D3DXVECTOR3 pos = m_transform.m_position;
    D3DXVECTOR3 at;
    at = pos + m_transform.m_direction;

    // Update projection matrix of the camera
    // � appeler seulement si le fov change
    /*D3DXMatrixPerspectiveFovLH(&_matProjection, _fov, FLOAT(_width) / FLOAT(_height), _zNear, _zFar);*/

    // Update matView Matrix
    D3DXMatrixLookAtLH(&_matView, &pos, &at, &m_transform.m_up);

    SetTransform(_device);
}

void Camera::SetTransform(IDirect3DDevice9* device) const
{
    device->SetTransform(D3DTS_PROJECTION, &_matProjection);
    //device->SetTransform(D3DTS_WORLD, &_matIdentity);
    device->SetTransform(D3DTS_VIEW, &_matView);
}
