#pragma once
#include "BaseScene.h"
#include "BaseObject.h"

class Game : public BaseScene
{
private:
	BaseObject*		player;
	BaseObject*		enemy;

	int				currentFrame;	// 現在のフレーム数
public:
	Game();
	~Game();

	void	Update() override;
	void	Draw() override;

	int		GetCurrentFrame() { return currentFrame; };
};