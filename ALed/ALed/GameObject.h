#pragma once
#include <string>
#include <list>
#include "transform.h"

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

protected:


};