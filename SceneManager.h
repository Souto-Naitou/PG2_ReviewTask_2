#pragma once
#include "./Scenes/BaseScene.h"

enum Scene
{
	SC_Title,
	SC_Game,
	SC_Result,
	SC_COUNT	// Sceneの数
};

class SceneManager
{
private:
	static	Scene	scene_current;
	static	Scene	scene_next;
	static	int		existRequest;

	static	BaseScene* bsInstance;
public:
	static	void	Init();
	static	void	Update();
	static	void	Draw();
	static	void	SceneChange();
	static	void	ChangeRequest(Scene _next);
};