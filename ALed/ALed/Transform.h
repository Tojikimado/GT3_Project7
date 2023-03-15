#pragma once
#include <windows.h> 
#include <d3d9.h>
#include <d3dx9.h>
#include "Component.h"

struct Rotation
{
	D3DXVECTOR3 vector3;
	D3DXQUATERNION quaternion;
};

class Transform : Component
{
public:

	void SetPosition(D3DXVECTOR3 _newPosition);

	D3DXVECTOR3 GetPosition();

	void SetScale(D3DXVECTOR3 _newScale);

	D3DXVECTOR3 GetScale();

	void SetRotation(D3DXVECTOR3 _newRotation);

	D3DXVECTOR3 GetRotation();


private:
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_direction;
	D3DXVECTOR3 m_right, m_up;
	D3DXMATRIX m_world;

	Rotation m_rotation;

	float roll, pitch, yaw;

protected:
	D3DXMATRIX GetWorld();

	D3DXQUATERNION GetQuaternion();
};



