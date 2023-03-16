#include "Transform.h"

Transform::Transform()
{
	m_position = D3DXVECTOR3(0.f,0.f,0.f);
	m_scale = D3DXVECTOR3(1.f, 1.f, 1.f);
	m_rotation.vector3 = D3DXVECTOR3(0.f, 0.f, 0.f);
	roll = 0.0f;
	pitch = 0.0f;
	yaw = 0.0f;
}

Transform::Transform(D3DXVECTOR3 position, D3DXVECTOR3 rotation, D3DXVECTOR3 scale)
{
	Transform::SetPosition(position);
	Transform::SetRotation(rotation);
	Transform::SetScale(scale);
}

Transform::~Transform()
{

}

void Transform::SetPosition(D3DXVECTOR3 _newPosition)
{
	m_position = _newPosition;
}

D3DXVECTOR3 Transform::GetPosition()
{
	return m_position;
}

void Transform::SetScale(D3DXVECTOR3 _newScale)
{
	m_scale = _newScale;
}

D3DXVECTOR3 Transform::GetScale()
{
	return m_scale;
}

void Transform::SetRotation(D3DXVECTOR3 _newRotation)
{
	m_rotation.vector3 = _newRotation;
}

D3DXVECTOR3 Transform::GetRotation()
{
	return m_rotation.vector3;
}

D3DXMATRIX* Transform::GetWorld()
{
	D3DXMATRIX Scale, Rx, Ry, Rz, Translate;
	D3DXMatrixScaling(&Scale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixRotationX(&Rx, m_rotation.vector3.x);
	D3DXMatrixRotationY(&Ry, m_rotation.vector3.y);
	D3DXMatrixRotationZ(&Rz, m_rotation.vector3.z);
	D3DXMatrixTranslation(&Translate, m_position.x, m_position.y, m_position.z);
	m_world = new D3DXMATRIX(Scale * Rx * Ry * Rz * Translate);
	return m_world;
}

D3DXQUATERNION Transform::GetQuaternion()
{
	D3DXQUATERNION quat;
	D3DXQuaternionRotationAxis(&quat, &m_direction, roll);
	m_rotation.quaternion *= quat;
	D3DXQuaternionRotationAxis(&quat, &m_right, pitch);
	m_rotation.quaternion *= quat;
	D3DXQuaternionRotationAxis(&quat, &m_up, yaw);
	m_rotation.quaternion *= quat;

	return m_rotation.quaternion;
}

