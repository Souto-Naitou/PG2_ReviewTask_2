#pragma once
#include "BaseObject.h"
#include "Defines.h"
#include "Useful/JSON-Loader/JSON-Manager.h"

class Bullet : public BaseObject
{
private:
	JsonL*		data;

	int			bulletHandle;

	Transform	position;
	Size		size;
	int			moveSpeed;

	void		LoadFromJSON();
public:
	Bullet(Transform _pos);

	void	Update() override;
	void	Draw() override;
};
