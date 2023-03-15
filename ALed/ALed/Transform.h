#pragma once
#include <windows.h> 
#include <d3d9.h>
#include <d3dx9.h>

struct Transform
{
	//Attributes
	D3DXVECTOR3 vScale;
	D3DXVECTOR3 vDirection;
	D3DXVECTOR3 vRight;
	D3DXVECTOR3 vUp;
	D3DXQUATERNION qRotation;
	D3DXMATRIX mRotation;
	D3DXVECTOR3 vPosition;
	D3DXMATRIX matrix;

	//Methods
	void Identity();
	void FromMatrix(D3DXMATRIX matrix);
	void UpdateRotationFromVectors();
	void UpdateRotationFromQuaternion();
	void UpdateRotationFromMatrix();
	void UpdateMatrix();
	void Rotate(float yaw, float pitch, float roll);
	void RotateYaw(float angle);
	void RotatePitch(float angle);
	void RotateRoll(float angle);
	void RotateWorld(D3DXMATRIX matrix);
	void RotateWorldX(float angle);
	void RotateWorldY(float angle);
	void RotateWorldZ(float angle);
};
