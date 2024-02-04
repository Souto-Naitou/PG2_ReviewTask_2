#pragma once
#include "Scenes/BaseScene.h"
#include "Defines.h"
#include "Useful/JSON-Loader/JSON-Manager.h"

class Enemy : public BaseScene
{
private:
	JsonL*		data;

	int			enemyHandle;

	Transform	position;
	Size		size;
	int			moveSpeed;

	int			isAbleDelete;

	void		LoadFromJSON();
public:
	Enemy(Transform _pos);

	void	Update() override;
	void	Draw() override;
	int		AbleDelete() { return isAbleDelete; };

	Transform	GetPosition() { return position; };
	Size		GetSize() { return size; };
};
