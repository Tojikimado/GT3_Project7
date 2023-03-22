#include "Transform.h"

Transform::Transform()
{
	Identity();
}

Transform::Transform(D3DXVECTOR3 position, D3DXVECTOR3 rotation, D3DXVECTOR3 scale)
{
	Identity();

	m_position = position;
	m_scale = scale;
	Rotate(rotation.y, rotation.x, rotation.z);
}

Transform::~Transform()
{

}

void Transform::Identity()
{
	m_position = D3DXVECTOR3(0.f, 0.f, 0.f);
	m_scale = D3DXVECTOR3(1.f, 1.f, 1.f);

	m_direction = D3DXVECTOR3(0.f, 0.f, 1.f);
	m_up = D3DXVECTOR3(0.f, 1.f, 0.f);
	m_right = D3DXVECTOR3(1.f, 0.f, 0.f);

	D3DXQuaternionIdentity(&m_quat);
	D3DXMatrixIdentity(&m_rot);
	D3DXMatrixIdentity(&m_world);

}

void Transform::SetPosition(D3DXVECTOR3 _newPosition)
{
	m_position = _newPosition;
	UpdateMatrix();
}


void Transform::SetScale(D3DXVECTOR3 _newScale)
{
	m_scale = _newScale;
	UpdateMatrix();
}

D3DXVECTOR3 Transform::GetScale()
{
	return m_scale;
}

//void Transform::SetRotation(D3DXVECTOR3 _newRotation)
//{
//	m_rotation.vector3 = _newRotation;
//	UpdateMatrix();
//}

D3DXMATRIX& Transform::GetRotation()
{
	return m_rot; /*m_rotation.vector3;*/
}

D3DXMATRIX& Transform::GetWorld()
{
	return m_world;
	//D3DXMATRIX Scale, Rx, Ry, Rz, Translate;
	//D3DXMatrixScaling(&Scale, m_scale.x, m_scale.y, m_scale.z);
	//D3DXMatrixRotationX(&Rx, m_rotation.vector3.x);
	//D3DXMatrixRotationY(&Ry, m_rotation.vector3.y);
	//D3DXMatrixRotationZ(&Rz, m_rotation.vector3.z);
	//D3DXMatrixTranslation(&Translate, m_position.x, m_position.y, m_position.z);
	//m_world = new D3DXMATRIX(Scale * Rx * Ry * Rz * Translate);
	//return m_world;
}

void Transform::Rotate(float yaw, float pitch, float roll)
{
	D3DXQUATERNION quatAll;
	D3DXQUATERNION quat;

	D3DXQuaternionIdentity(&quatAll);

	if (yaw != 0)
	{
		D3DXQuaternionRotationAxis(&quat, &m_up, yaw);
		quatAll *= quat;
	}

	if (pitch != 0)
	{
		D3DXQuaternionRotationAxis(&quat, &m_right, pitch);
		quatAll *= quat;
	}

	if (roll != 0)
	{
		D3DXQuaternionRotationAxis(&quat, &m_direction, roll);
		quatAll *= quat;
	}

	m_quat *= quatAll;

	D3DXMatrixRotationQuaternion(&m_rot, &m_quat);

	m_right.x = m_rot._11;
	m_right.y = m_rot._12;
	m_right.z = m_rot._13;
	m_up.x = m_rot._21;
	m_up.y = m_rot._22;
	m_up.z = m_rot._23;
	m_direction.x = m_rot._31;
	m_direction.y = m_rot._32;
	m_direction.z = m_rot._33;

	UpdateMatrix();
}

void Transform::UpdateMatrix()
{
	D3DXMatrixScaling(&m_world, m_scale.x, m_scale.y, m_scale.z);
	m_world *= m_rot;
	m_world._41 = m_position.x;
	m_world._42 = m_position.y;
	m_world._43 = m_position.z;
}
