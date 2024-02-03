#include "Title.h"
#include "Useful/ResourceManager.h"
#include "Useful/PhilliaFunction/Phill.h"
#include "Useful/KeyManager.h"
#include "SceneManager.h"
#include <Novice.h>

void Title::LoadFromJSON()
{
	titleData				= JSON_Manager::GetJSON("title");
	titlePos.x				= atoi((*titleData)["screenTitleX"].c_str());
	titlePos.y				= atoi((*titleData)["screenTitleY"].c_str());
	titleSize.width			= atoi((*titleData)["screenTitleWidth"].c_str());
	titleSize.height		= atoi((*titleData)["screenTitleHeight"].c_str());
	titlePos_src.x			= atoi((*titleData)["srcTitleX"].c_str());
	titlePos_src.y			= atoi((*titleData)["srcTitleY"].c_str());
	titleSize_src.width		= atoi((*titleData)["srcTitleWidth"].c_str());
	titleSize_src.height	= atoi((*titleData)["srcTitleHeight"].c_str());
}

Title::Title()
{
	titleHandle	= ResourceManager::Handle("title");
	LoadFromJSON();
}

void Title::Update()
{
	// TODO: [Title:Update] キー入力でゲームシーンへ
	if (KeyManager::GetKeys(DIK_RETURN) && !KeyManager::GetPreKeys(DIK_RETURN))
	{
		SceneManager::ChangeRequest(Scene::SC_Game);
	}
}

void Title::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffffffff, kFillModeSolid);
	// タイトルを表示
	Phill::DrawQuadPlus(
		titlePos.x, titlePos.y,
		titleSize.width, titleSize.height,
		1.0f, 1.0f,
		0.0f,
		titlePos_src.x, titlePos_src.y,
		titleSize_src.width, titleSize_src.height,
		titleHandle,
		0xffffffff,
		DrawMode_Center
	);
}
