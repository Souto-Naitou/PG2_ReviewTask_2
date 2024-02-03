#pragma once
#include "BaseScene.h"

class Title : public BaseScene
{
private:
	int		titleHandle;

public:
	Title();

	void	Update();
	void	Draw();
};
