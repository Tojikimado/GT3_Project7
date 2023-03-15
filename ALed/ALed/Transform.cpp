#include "Transform.h"

void Transform::Identity()
{
	D3DXMatrixIdentity(&mRotation);
	D3DXMatrixIdentity(&matrix);
	D3DXQuaternionIdentity(&qRotation);
	
}

void Transform::FromMatrix(D3DXMATRIX matrix)
{

}

void Transform::UpdateRotationFromVectors()
{

}

void Transform::UpdateRotationFromQuaternion()
{

}

void Transform::UpdateRotationFromMatrix()
{

}

void Transform::UpdateMatrix()
{

}

void Transform::Rotate(float yaw, float pitch, float roll)
{

}

void Transform::RotateYaw(float angle)
{
	D3DXQUATERNION quat;
	D3DXQuaternionRotationAxis(&quat, &vUp, angle);
	qRotation *= quat;
}

void Transform::RotatePitch(float angle)
{
	D3DXQUATERNION quat;
	D3DXQuaternionRotationAxis(&quat, &vRight, angle);
	qRotation *= quat;
}

void Transform::RotateRoll(float angle)
{
	D3DXQUATERNION quat;
	D3DXQuaternionRotationAxis(&quat, &vDirection, angle);
	qRotation *= quat;
}

void Transform::RotateWorld(D3DXMATRIX matrix)
{

}

void Transform::RotateWorldX(float angle)
{

}

void Transform::RotateWorldY(float angle)
{

}

void Transform::RotateWorldZ(float angle)
{

}

