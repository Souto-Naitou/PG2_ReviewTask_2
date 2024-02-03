#include <Novice.h>
#include "SceneManager.h"
#include "Useful/CursorManager.h"
#include "Useful/KeyManager.h"
#include "Useful/ResourceManager.h"
#include "Useful/JSON-Loader/JSON-Manager.h"


const char kWindowTitle[] = "LC1A_17_ナイトウ_ソウト_タイトル";

void	ResourceRegist();
void	Load_JSON();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// リソース登録
	ResourceRegist();
	// JSONファイル読み込み
	Load_JSON();

	
	SceneManager::Init();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		CursorManager::UpdateCursorStatus();
		KeyManager::GetKeyState();

		///
		/// ↓更新処理ここから
		///

		SceneManager::Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		SceneManager::Draw();

		///
		/// ↑描画処理ここまで
		///

		SceneManager::SceneChange();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

void	ResourceRegist()
{
	ResourceManager::Regist("title", "./Resource/img/title.png");
}

void Load_JSON()
{
	JSON_Manager::LoadJSON("title", "./Resource/data/title.json");
}
