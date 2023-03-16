#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include "Transform.h"

class Camera
{

public:

    /*Camera(int width, int height, float angle, D3DXVECTOR3 scaleFactors);*/    
    Camera(int width, int height, Transform camTransform);
    ~Camera();

    void Update(IDirect3DDevice9* device);

    void SetTransform(IDirect3DDevice9* device) const;

    Transform transform;

private:

    D3DXMATRIX _matIdentity;
    D3DXMATRIX _matProjection;
    D3DXMATRIX _matView;
    D3DXMATRIX _matLook;

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

