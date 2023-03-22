#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include "GameObject.h"

class Camera : public GameObject
{

public:
  
    Camera(IDirect3DDevice9* device, int width, int height, Transform camTransform);
    Camera(IDirect3DDevice9* device, int width, int height, Transform camTransform, float fov, float zNear, float zFar);
    ~Camera();

    void Update();

    void SetTransform(IDirect3DDevice9* device) const;

    inline void SetFOV(float fov) { _fov = fov; };
    inline float GetFOV() { return _fov; };

    inline void SetZNear(float zNear) { _zNear = zNear; };
    inline float GetZNear() { return _zNear; };

    inline void SetZFar(float zFar) { _zFar = zFar; };
    inline float GetZFar() { return _zFar; };

private:

    IDirect3DDevice9* _device;

    D3DXMATRIX _matIdentity;
    D3DXMATRIX _matProjection;
    D3DXMATRIX _matView;

    D3DXVECTOR3 _vUp;
    D3DXVECTOR3 _vForward;

    int _width;
    int _height;
    float _fov;
    float _zNear;
    float _zFar;

    float _pitch;
    float _yaw;
    float _roll;
    
};

