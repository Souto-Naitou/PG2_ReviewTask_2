#include "Player.h"
#include "Useful/PhilliaFunction/Phill.h"
#include "Useful/ResourceManager.h"
#include "Useful/KeyManager.h"
#include <Novice.h>
#include "Scenes/Game.h"

#define	KM KeyManager

int	currentFrame;
int	bufferFrame;

void Player::LoadFromJSON()
{
	data				= JSON_Manager::GetJSON("player");
	position.x			= atoi((*data)["x"].c_str());
	position.y			= atoi((*data)["y"].c_str());
	size.width			= atoi((*data)["width"].c_str());
	size.height			= atoi((*data)["height"].c_str());
	moveSpeed			= atoi((*data)["moveSpeed"].c_str());
	bulletMaxCount		= atoi((*data)["bulletMaxCount"].c_str());
	bulletShotInterval	= atoi((*data)["bulletShotInterval"].c_str());
}

void Player::MoveWithKeyboard()
{
	// 移動
	if (KM::GetKeys(DIK_W) || KM::GetKeys(DIK_UPARROW))
	{
		position.y -= moveSpeed;
	}
	if (KM::GetKeys(DIK_S) || KM::GetKeys(DIK_DOWNARROW))
	{
		position.y += moveSpeed;
	}
	if (KM::GetKeys(DIK_A) || KM::GetKeys(DIK_LEFTARROW))
	{
		position.x -= moveSpeed;
	}
	if (KM::GetKeys(DIK_D) || KM::GetKeys(DIK_RIGHTARROW))
	{
		position.x += moveSpeed;
	}

	// 発射
	if (KM::GetKeys(DIK_SPACE) || KM::GetKeys(DIK_RETURN))
	{
		isShot = 1;
	}
	else isShot = 0;
}

void Player::Shot()
{
	if (isShot)
	{
		if (bufferFrame == 0)
		{
			bufferFrame = currentFrame;
			bullets.push_back(new Bullet(position));
			return;
		}
		if (currentFrame - bufferFrame > bulletShotInterval)
		{
			bufferFrame = currentFrame;
			bullets.push_back(new Bullet(position));
		}
	}
}

Player::Player()
{
	playerHandle = ResourceManager::Handle("white");
	LoadFromJSON();
	currentFrame	= 0;
	bufferFrame		= 0;
}

Player::~Player()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		delete bullets[i];
	}
	bullets.clear();
}

void Player::Update()
{
	MoveWithKeyboard();
	Shot();
	currentFrame++;

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update();
		if (bullets[i]->ableDelete())
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Player::Draw()
{
	for (Bullet* obj : bullets)
	{
		obj->Draw();
	}

	Phill::DrawQuadPlus(
		position.x, position.y,
		size.width, size.height,
		1.0f, 1.0f,
		0.0f,
		0, 0,
		1, 1,
		playerHandle,
		0xffffffff,
		DrawMode_Center
	);
}
