#pragma once
#include "BaseObject.h"
#include "Useful/JSON-Loader/JSON-Manager.h"
#include "Defines.h"
#include "Bullet.h"
#include <vector>

class Player : public BaseObject
{
private:

	// 包含？
	std::vector<Bullet*> bullets;
	
	JsonL*		data;
	int			playerHandle;

	Transform	position;
	Size		size;
	int			moveSpeed;
	int			bulletMaxCount;
	int			bulletShotInterval;
	int			isShot;

	void		LoadFromJSON();
	void		MoveWithKeyboard();
	void		Shot();
public:
	Player();
	~Player();

	void		Update() override;
	void		Draw() override;

	Transform	GetPosition() { return position; };
	Size		GetSize() { return size; };
	std::vector<Bullet*>* GetBullets() { return &bullets; };
};