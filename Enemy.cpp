#include "Enemy.h"

void Enemy::LoadFromJSON()
{

	data = JSON_Manager::GetJSON("enemy");

	size.width = atoi((*data)["width"].c_str());
	size.height = atoi((*data)["height"].c_str());
	moveSpeed = atoi((*data)["moveSpeed"].c_str());
}

Enemy::Enemy()
{

	LoadFromJSON();
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}
