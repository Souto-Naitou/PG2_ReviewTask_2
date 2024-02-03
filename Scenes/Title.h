#pragma once

#include "BaseScene.h"
#include "Useful/JSON-Loader/JSON-Manager.h"
#include "Defines.h"

class Title : public BaseScene
{
private:
	JsonL*		titleData;
	int			titleHandle;

	Transform	titlePos;
	Size		titleSize;
	Transform	titlePos_src;
	Size		titleSize_src;


	void	LoadFromJSON();
public:
	Title();

	void	Update() override;
	void	Draw() override;
};
