#pragma once
#include <windows.h> 
#include <d3d9.h>
#include <d3dx9.h>

//struct Rotation
//{
//	//D3DXVECTOR3 vector3;
//
//};

class Transform
{
public:
	Transform();
	Transform(D3DXVECTOR3 position, D3DXVECTOR3 rotation, D3DXVECTOR3 scale);
	~Transform();

	void Identity();

	void SetPosition(D3DXVECTOR3 _newPosition);

	//D3DXVECTOR3 m_position;

	void SetScale(D3DXVECTOR3 _newScale);

	D3DXVECTOR3 GetScale();

	//void SetRotation(D3DXVECTOR3 _newRotation);
	void Rotate(float yaw, float pitch, float roll);

	D3DXMATRIX& GetRotation();

	D3DXMATRIX& GetWorld();

	//D3DXQUATERNION GetQuaternion();

	void UpdateMatrix();


	D3DXVECTOR3 m_position;

	D3DXVECTOR3 m_scale;

	D3DXVECTOR3 m_direction;
	D3DXVECTOR3 m_right, m_up;
	D3DXQUATERNION m_quat;
	D3DXMATRIX m_rot;

	D3DXMATRIX m_world;

	//float roll, pitch, yaw;
};



