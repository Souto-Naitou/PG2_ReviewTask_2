#include "Game.h"
#include "Player.h"
#include <Novice.h>
#include <SceneManager.h>

Game::Game()
{
	// TODO: [Game:Game] 自機のインスタンス生成
	player = new Player();
	pBullets = player->GetBullets();
	deathEnemyCount = 0;
	currentFrame = 0;
	sBullet.width = 4;
	sBullet.height = 4;
}

Game::~Game()
{
	if (player) delete player;
	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
		enemies.erase(enemies.begin() + i);
	}
}

void Game::Update()
{
	// TODO: [Game:Update] 自機の更新処理
	if (player)
	{
		player->Update();
		tPlayer = player->GetPosition();
		sPlayer = player->GetSize();
	}

	if (currentFrame % 15 == 0) enemies.push_back(new Enemy(tPlayer));

	// TODO: [Game:Update] 敵機の更新処理
	for (int i = 0; i < enemies.size(); i++)
	{
		int isDead = 0;
		enemies[i]->Update();
		Transform tE = enemies[i]->GetPosition();
		Size sE = enemies[i]->GetSize();
		// 当たり判定
		if (player) {
			if (tPlayer.x + sPlayer.width / 2 > tE.x - sE.width / 2 &&
				tPlayer.x - sPlayer.width / 2 < tE.x + sE.width / 2 &&
				tPlayer.y + sPlayer.height / 2 > tE.y - sE.height / 2 &&
				tPlayer.y - sPlayer.height / 2 < tE.y + sE.height / 2)
			{
				delete player;
				player = nullptr;
				SceneManager::ChangeRequest(Scene::SC_Title);
			}
		}

		for (int j = 0; j < pBullets->size(); j++)
		{
			Transform tB = (*pBullets)[j]->GetPosition();
			if (tB.x + sBullet.width / 2 > tE.x - sE.width / 2 &&
				tB.x - sBullet.width / 2 < tE.x + sE.width / 2 &&
				tB.y + sBullet.height / 2 > tE.y - sE.height / 2 &&
				tB.y - sBullet.height / 2 < tE.y + sE.height / 2)
			{
				delete enemies[i];
				enemies.erase(enemies.begin() + i);
				delete (*pBullets)[j];
				(*pBullets).erase((*pBullets).begin() + j);
				deathEnemyCount++;
				isDead = 1;
				break;
			}
				
		}
		if (isDead) continue;
		
		if (enemies[i]->AbleDelete())
		{
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
		}
	}

	// TODO: [Game:Update] 自機が死んだらGameOverシーンへ遷移

	// TODO: [Game:Update] 敵機全滅でClearシーンへ遷移


	currentFrame++;
}

void Game::Draw()
{
	// 背景の描画
	Novice::DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0xaaaaaaff, kFillModeSolid);
	// TODO: [Game:Draw] 敵機の数だけ描画(拡張for文でできそう?)
	for (auto enemy : enemies)
	{
		enemy->Draw();
	}

	Novice::ScreenPrintf(15, 15, "%d", deathEnemyCount);

	// TODO: [Game:Draw] 自機の描画
	if (player)	player->Draw();
}
