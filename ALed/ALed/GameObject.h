#pragma once
#include <string>
#include <list>
#include "Transform.h"
#include "BoundingSphere.h"

using namespace std;

class GameObject
{
public:
	string m_name;

	GameObject();
	virtual ~GameObject();

	Transform GetTransform();
	void SetTransform(Transform transform);

	bool Init();
	void Update(float dt);
	void Render();

	bool b_isActive = true;

protected:
	
	Transform m_transform;

};

