#pragma once
#include "D3DApp.h"

class Test : public D3DApp
{
public:
	Test(HINSTANCE hInstance);

	~Test();

	bool Init() override;
	void Update(float dt) override;
	void Render() override;
};
