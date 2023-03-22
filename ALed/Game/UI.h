#pragma once
#include <ColoredGameObject.h>
#include <Camera.h>
class UI : public ColoredGameObject
{
public:
	UI();
	UI(Camera* camera);
	~UI();
};

