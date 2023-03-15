#include "Transform.h"

D3DXMATRIX Transform::GetWorld()
{
	D3DXMATRIX Scale, Rx, Ry, Rz, Translate;
	D3DXMatrixScaling(&Scale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixRotationX(&Rx, m_rotation.vector3.x);
	D3DXMatrixRotationY(&Ry, m_rotation.vector3.y);
	D3DXMatrixRotationZ(&Rz, m_rotation.vector3.z);
	D3DXMatrixTranslation(&Translate, m_position.x, m_position.y, m_position.z);
	m_world = Scale * Rx * Ry * Rz * Translate;
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


