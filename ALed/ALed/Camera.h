#pragma once
#include<d3d9.h>
#include<d3dx9.h>



class Camera
{

public:

    /*Camera(int width, int height, float angle, D3DXVECTOR3 scaleFactors);*/    
    Camera(int width, int height, D3DXVECTOR3 position, D3DXVECTOR3 target);


    ~Camera();

    void Update();

    void Follow(); // GameObject
    void Unfollow();

    void SetTransform(IDirect3DDevice9* device) const;
protected:


private:
    D3DXMATRIX matIdentity;
    D3DXMATRIX matProjection;
    D3DXMATRIX matView;

    D3DXVECTOR3 vPosition;

    int width;
    int height;
    float fov;
    float zNear;
    float zFar;


    //float angle;
    //D3DXVECTOR3 scaleFactors;

    //GameObject *following

    // à ajouter dans Test::Init();
    
};

