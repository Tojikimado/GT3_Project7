#pragma once
#include <string>
#include <list>
#include "Transform.h"
#include "BoundingSphere.h"
#include "Camera.h"

using namespace std;

class GameObject
{
public:
	string m_name;

	GameObject();
	~GameObject();

	Transform GetTransform();
	

	void SetCamera(Camera* _camera);

	bool Init();
	void Update(float dt);
	void Render();

protected:
	
	Transform m_transform;

	Camera* m_camera = nullptr;
};

