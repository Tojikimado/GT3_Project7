#pragma once
#include <string>
#include <list>
#include "Transform.h"
#include "Component.h"
#include "Collider.h"

using namespace std;

class GameObject
{
public:
	string m_name;

	GameObject();
	~GameObject();

	Transform GetTransform();

private:
	Transform m_transform;
	Collider* _collider = nullptr;

	list<Component> m_components;

protected:


};