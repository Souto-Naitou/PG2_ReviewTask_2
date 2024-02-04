#include "SceneManager.h"
#include "Scenes/Title.h"
#include "Scenes/Game.h"
#include "Useful/KeyManager.h"
#include <Novice.h>

Scene		SceneManager::scene_current;
Scene		SceneManager::scene_next;
int			SceneManager::existRequest;
BaseScene*	SceneManager::bsInstance;

void SceneManager::Init()
{
	scene_current	= Scene::SC_Title;
	scene_next		= scene_current;
	existRequest	= 0;
	bsInstance		= new Title();
}

void SceneManager::Update()
{
	if (KeyManager::GetKeys(DIK_R) && KeyManager::GetPreKeys(DIK_R))
	{
		SceneManager::ChangeRequest(Scene::SC_Title);
	}
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
			bsInstance = new Title();
			break;
		case SC_Game:
			bsInstance = new Game();
			break;
		case SC_Result:
			//bsInstance = new Result;
			break;
		default:
			break;
		}

		existRequest = 0;
	}
}

void SceneManager::ChangeRequest(Scene _next)
{
	existRequest = 1;
	scene_next = _next;
}
