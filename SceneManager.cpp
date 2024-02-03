#include "SceneManager.h"

Scene		SceneManager::scene_current;
Scene		SceneManager::scene_next;
int			SceneManager::existRequest;
BaseScene*	SceneManager::bsInstance;

void SceneManager::Init()
{
	scene_current	= Scene::SC_Title;
	scene_next		= scene_current;
	existRequest	= 0;
	bsInstance		= nullptr;
}

void SceneManager::Update()
{
	bsInstance->Update();
}

void SceneManager::Draw()
{
	bsInstance->Draw();
}
void SceneManager::SceneChange()
{
	if (existRequest)
	{
		delete bsInstance;
		switch (scene_next)
		{
		case SC_Title:
			//bsInstance = new Title();
			break;
		case SC_Game:
			//bsInstance = new Game();
			break;
		case SC_Result:
			//bsInstance = new Result;
			break;
		default:
			break;
		}
	}
}

void SceneManager::ChangeRequest(Scene _next)
{
	existRequest = 1;
	scene_next = _next;
}
