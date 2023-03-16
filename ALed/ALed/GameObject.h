#pragma once
#include <string>
#include <list>
#include "Transform.h"
#include "BoundingSphere.h"
#include "Camera.h"
#include "ColoredMeshRenderer.h"

using namespace std;

class GameObject
{
public:
	string m_name;

	GameObject();
	~GameObject();

	Transform GetTransform();
	
	void SetColoredMeshRenderer(ColoredMeshRenderer* _meshRenderer);

	void SetCamera(Camera* _camera);

private:
	
	Transform m_transform;

	ColoredMeshRenderer* m_meshRenderer = nullptr;

	Camera* m_camera = nullptr;
};

