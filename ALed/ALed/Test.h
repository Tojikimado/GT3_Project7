#pragma once
#define _USE_MATH_DEFINES

#include "D3DApp.h"
#include "Camera.h"

#include "ColoredRectangle.h"
#include "ColoredCube.h"
#include "TexturedGameObject.h"
#include "ColoredSlopeMesh.h"

#include <string>
#include <cmath>
#include <math.h>
#include "PlayerTrack.h"

class Camera; 

class Test : public D3DApp
{
public:
	Test(HINSTANCE hInstance);

	~Test();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;

	Camera* pCamera = nullptr;
	PlayerTrack* pTrack = nullptr;

private: 

};

