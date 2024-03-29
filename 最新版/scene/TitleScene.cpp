#include "TitleScene.h"
#include"SceneManager.h"
#include "Audio.h"
#include "input.h"
#include "DebugText.h"

void TitleScene::Initialize(DirectXCommon* dxCommon) {
	// テクスチャ読み込み
	Sprite::LoadTexture(1, L"Resources/2d/title.png");

	//背景スプライト生成
	sprite = Sprite::Create(1, { 0.0f,0.0f });
	//スプライト生成


}

void TitleScene::Finalize() {
	//３ｄのモデルのデリート
	delete sprite;
}

void TitleScene::Update(DirectXCommon* dxCommon) {
	Input* input = Input::GetInstance();
	if (input->PushKey(DIK_RETURN) || input->TriggerButton(input->Button_A)) {
		Audio::GetInstance()->PlayWave("Resources/Sound/Button.wav", 0.4f);
		SceneManager::GetInstance()->ChangeScene("PlayScene");
	}
	//DebugText::GetInstance()->Print("Button_A to STARTMAP!!", 100, 100, 1.5f);
	//DebugText::GetInstance()->Print("SPACE to BOSS!!", 100, 130, 1.5f);

}

void TitleScene::Draw(DirectXCommon* dxCommon) {
	sprite->PreDraw();
	//背景用
	sprite->Draw();

	//前面用

}

