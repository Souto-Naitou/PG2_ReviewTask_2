#pragma once
#include "Scenes/BaseScene.h"
#include "Defines.h"
#include "Useful/JSON-Loader/JSON-Manager.h"

class Enemy : public BaseScene
{
private:
	JsonL*		data;

	Transform	position;
	Size		size;
	int			moveSpeed;

	void		LoadFromJSON();
public:
	Enemy();

	void	Update() override;
	void	Draw() override;

};
