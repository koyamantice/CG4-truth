﻿#include "Framework.h"
#include "FbxLoader.h"
//#include "FPSManager.h"
void Framework::Run() {
	
	//初期化
	Initialize(dxcommon);
	while (true)//ゲームループ
	{
		if (FPSManager::GetInstance()->Run()) {

			//毎フレーム更新
			Update(dxcommon);

			//終了リクエストが来たら抜ける
			if (IsEndRequst()) {
				break;
			}

			//描画
			Draw(dxcommon);
		}
	}
	//ゲームの終了
	Finalize();

}

void Framework::Initialize(DirectXCommon* dxCommon) {
	winApp = new WinApp();
	winApp->Initialize();
	dxcommon = new DirectXCommon();
	dxcommon->Initialize(winApp);
	// 入力の初期化
	input = Input::GetInstance();
	input->Initialize(winApp);

	audio = Audio::GetInstance();
	audio->Initialize();	
	
	fps = FPSManager::GetInstance();
	fps->Init();
	//スプライト関係
	// スプライト静的初期化
	Sprite::StaticInitialize(dxcommon->GetDev(), dxcommon->GetCmdList(),WinApp::window_width, WinApp::window_height);

	Sprite::LoadTexture(100, L"Resources/2d/white1x1.png");

	postEffect = new PostEffect();
	postEffect->Initialize();


	const int debugTextTexNumber = 0;
	// デバッグテキスト用テクスチャ読み込み
	if (!Sprite::LoadTexture(debugTextTexNumber, L"Resources/2d/debugfont.png")) {
		assert(0);
		return;
	}
	// デバッグテキスト初期化
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);

	// ライト静的初期化
	LightGroup::StaticInitialize(dxcommon->GetDev());
	//テクスチャ初期化
	Texture::StaticInitialize(dxcommon->GetDev(), dxcommon->GetCmdList(), WinApp::window_width, WinApp::window_height);
	Object3d::StaticInitialize(dxcommon->GetDev(), dxcommon->GetCmdList(), WinApp::window_width, WinApp::window_height);
	// マウスカーソルの非表示
	ShowCursor(TRUE);
	//XorShiftの初期化
	xorShift = XorShift::GetInstance();
	XorShift::GetInstance()->initrand((unsigned int)time(NULL));
	//シーンマネージャー
	// FBX関連静的初期化
	FbxLoader::GetInstance()->Initialize(dxcommon->GetDev());
	// パーティクルマネージャ初期化
	//ParticleManager::GetInstance()->Initialize(dxcommon->GetDev());
	Texture::LoadTexture(0, L"Resources/2d/enemy.png");
	Texture::LoadTexture(1, L"Resources/2d/shadow.png");
	Texture::LoadTexture(2, L"Resources/2d/Resporn.png");
	Texture::LoadTexture(3, L"Resources/2d/effect2.png");
	Texture::LoadTexture(4, L"Resources/2d/PlayerHP.png");
	Texture::LoadTexture(5, L"Resources/2d/magic2.png");
	Texture::LoadTexture(6, L"Resources/2d/Resporn.png");
	ModelManager::GetIns()->Initialize();
}

void Framework::Finalize() {
	delete sceneFactory_;
	delete postEffect;
	winApp->Finalize();
	delete winApp;
}

void Framework::Update(DirectXCommon* dxCommon) {
	input->Update(winApp);
	XorShift::GetInstance()->initrand((unsigned int)time(NULL));
	XorShift::GetInstance()->init_xor128((unsigned long)time(NULL));
	if (winApp->ProcessMessage() || input->TriggerKey(DIK_ESCAPE)) {
		endResquest_ = true;
		return;
	}
	if (input->TriggerKey(DIK_P)) {
		if (post) { post = false; }else{ post = true; }
	}
	SceneManager::GetInstance()->Update(dxCommon);
}

void Framework::Draw(DirectXCommon* dxCommon) {
	if (post) {
		postEffect->PreDrawScene(dxCommon->GetCmdList());
		SceneManager::GetInstance()->Draw(dxCommon);
		postEffect->PostDrawScene(dxCommon->GetCmdList());

		dxCommon->PreDraw();
		postEffect->Draw(dxCommon->GetCmdList());
		debugText->DrawAll();
		dxCommon->PostDraw();
	} else {
		postEffect->PreDrawScene(dxCommon->GetCmdList());
		//SceneManager::GetInstance()->Draw(dxCommon);
		postEffect->PostDrawScene(dxCommon->GetCmdList());

		dxCommon->PreDraw();
		SceneManager::GetInstance()->Draw(dxCommon);
		debugText->DrawAll();
		dxCommon->PostDraw();
	}
}
