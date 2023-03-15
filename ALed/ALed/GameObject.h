#pragma once
#include <string>
#include <list>
#include "Transform.h"
#include "Component.h"

using namespace std;

class GameObject
{
public:
	string m_name;

	GameObject();
	~GameObject();

private:
	Transform m_transform;
	list<Component> m_components;

protected:


};