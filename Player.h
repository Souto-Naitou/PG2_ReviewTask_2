#pragma once
#include "BaseObject.h"
#include "Useful/JSON-Loader/JSON-Manager.h"
#include "Defines.h"
#include "Bullet.h"
#include <vector>

class Player : public BaseObject
{
private:

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

	void	Update() override;
	void	Draw() override;
};