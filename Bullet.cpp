#include "Bullet.h"
#include "Useful/PhilliaFunction/Phill.h"
#include "Useful/ResourceManager.h"

void Bullet::LoadFromJSON()
{
	data = JSON_Manager::GetJSON("bullet");

	size.width	= atoi((*data)["width"].c_str());
	size.height = atoi((*data)["height"].c_str());
	moveSpeed	= atoi((*data)["moveSpeed"].c_str());

}

Bullet::Bullet(Transform _pos)
{
	LoadFromJSON();
	position = _pos;
	bulletHandle = ResourceManager::Handle("white");
}

void Bullet::Update()
{
	position.x += moveSpeed;
}

void Bullet::Draw()
{
	Phill::DrawQuadPlus(
		position.x, position.y,
		size.width, size.height,
		1.0f, 1.0f,
		0.0f,
		0, 0,
		1, 1,
		bulletHandle,
		0xffffffff,
		DrawMode_Center
	);
}
