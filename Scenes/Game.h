#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game : public BaseScene
{
private:
	Player*					player;
	std::vector<Enemy*>		enemies;
	std::vector<Bullet*>*	pBullets;
	Transform				tPlayer;
	Size					sPlayer;

	Size					sBullet;


	int					deathEnemyCount;	// 死んだ敵数
	int					currentFrame;		// 現在のフレーム数
public:
	Game();
	~Game();

	void	Update() override;
	void	Draw() override;

	int		GetCurrentFrame() { return currentFrame; };
};