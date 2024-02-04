#include "Enemy.h"
#include <stdlib.h>
#include "Useful/PhilliaFunction/Phill.h"
#include "Useful/ResourceManager.h"

void Enemy::LoadFromJSON()
{

	data = JSON_Manager::GetJSON("enemy");

	size.width = atoi((*data)["width"].c_str());
	size.height = atoi((*data)["height"].c_str());
	moveSpeed = atoi((*data)["moveSpeed"].c_str());
}

Enemy::Enemy(Transform _pos)
{
	enemyHandle = ResourceManager::Handle("white");
	position.x = SCREEN_WIDTH + size.width;
	position.y = _pos.y + (rand() % 360 - 180);
	isAbleDelete = 0;
	LoadFromJSON();
}

void Enemy::Update()
{
	position.x -= moveSpeed;

	if (position.x < -size.width)
	{
		isAbleDelete = 1;
	}
}

void Enemy::Draw()
{
	Phill::DrawQuadPlus(
		position.x, position.y,
		size.width, size.height,
		1.0f, 1.0f,
		0.0f,
		0, 0,
		1, 1,
		enemyHandle,
		0xcc4444ff,
		DrawMode_Center
	);
}
