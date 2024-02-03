#include "Game.h"
#include "Player.h"
#include <Novice.h>

Game::Game()
{
	// TODO: [Game:Game] 自機のインスタンス生成
	player = new Player();
	// TODO: [Game:Game] 敵機のインスタンス生成(数と頻度はターゲット定数に従う)
	enemy = nullptr;

	currentFrame = 0;
}

Game::~Game()
{
	if (player) delete player;
	if (enemy)	delete enemy;
}

void Game::Update()
{
	// TODO: [Game:Update] 自機の更新処理
	player->Update();
	// TODO: [Game:Update] 敵機の更新処理

	// TODO: [Game:Update] 自機が死んだらGameOverシーンへ遷移

	// TODO: [Game:Update] 敵機全滅でClearシーンへ遷移

	currentFrame++;
}

void Game::Draw()
{
	// 背景の描画
	Novice::DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0xaaaaaaff, kFillModeSolid);
	// TODO: [Game:Draw] 敵機の数だけ描画(拡張for文でできそう?)

	// TODO: [Game:Draw] 自機の描画
	player->Draw();
}
