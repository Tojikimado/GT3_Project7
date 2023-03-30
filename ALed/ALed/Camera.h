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

    void Update(float dt);

    void SetTransform(IDirect3DDevice9* device) const;

    void SetUI(GameObject* ui);
    GameObject* GetUI();

    void GetCursorRay(D3DXVECTOR3* pOrg, D3DXVECTOR3* pDir, FLOAT x, FLOAT y);

    inline void SetFOV(float fov) { _fov = fov; };
    inline float GetFOV() { return _fov; };

    inline void SetZNear(float zNear) { _zNear = zNear; };
    inline float GetZNear() { return _zNear; };

    inline void SetZFar(float zFar) { _zFar = zFar; };
    inline float GetZFar() { return _zFar; };

    inline float GetWidth() { return _width; };
    inline float GetHeight() { return _height; };

    inline D3DXMATRIX GetProj() { return _matProjection; };

    inline D3DXMATRIX GetView() { return _matView; };

private:
    IDirect3DDevice9* _device;

    GameObject* pUI;

    D3DXMATRIX _matIdentity;
    D3DXMATRIX _matProjection;
    D3DXMATRIX _matView;

    int _width;
    int _height;
    float _fov;
    float _zNear;
    float _zFar;

};

