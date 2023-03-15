#pragma once
#include <windows.h> 
#include <d3d9.h>
#include <d3dx9.h>

struct Rotation
{
	D3DXVECTOR3 vector3;
	D3DXQUATERNION quaternion;
};

struct Transform
{
public :

	D3DXVECTOR3 SetPosition(D3DXVECTOR3 _newPosition)
	{
		m_position = _newPosition;
	}

	D3DXVECTOR3 GetPosition()
	{
		return m_position;
	}

	D3DXVECTOR3 SetScale(D3DXVECTOR3 _newScale)
	{
		m_scale = _newScale;
	}

	D3DXVECTOR3 GetScale()
	{
		return m_scale;
	}

	D3DXVECTOR3 SetRotation(D3DXVECTOR3 _newRotation)
	{
		m_scale = _newRotation;
	}

	D3DXVECTOR3 GetRotation()
	{
		return m_rotation.vector3;
	}


private : 
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_direction;
	D3DXVECTOR3 m_right, m_up;
	D3DXMATRIX m_world;

	Rotation m_rotation;

	float roll, pitch, yaw;
	
protected : 
	D3DXMATRIX GetWorld();

	D3DXQUATERNION GetQuaternion();

};

