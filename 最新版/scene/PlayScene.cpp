#include "PlayScene.h"
#include "Audio.h"
#include "DebugText.h"
#include "TitleScene.h"
#include "FbxLoader.h"
#include "Collision.h"
#include "TouchableObject.h"
#include "MeshCollider.h"
#include "SphereCollider.h"
#include "CollisionManager.h"
#include <XorShift.h>
void PlayScene::Initialize(DirectXCommon* dxCommon) {
	// カメラ生成
	camera = new DebugCamera(WinApp::window_width, WinApp::window_height);
	camera->SetTarget({0,2.5f,0});
	camera->SetDistance(1.0f);
	// ライト生成
	lightGroup = LightGroup::Create();

	Texture::SetCamera(camera);
	// 3Dオブジェクトにカメラをセット
	Object3d::SetCamera(camera);
	// 3Dオブエクトにライトをセット
	Object3d::SetLightGroup(lightGroup);
	//背景スプライト生成
	Sprite::LoadTexture(0, L"Resources/2d/background.png");
	BG=Sprite::Create(0, {0,0});
	// モデル読み込み
	Audio::GetInstance()->LoadSound(1, "Resources/BGM/NewWorld.wav");
	model1 = FbxLoader::GetInstance()->LoadModelFromFile("boneTest");
	// デバイスをセット
	FBXObject3d::SetDevice(dxCommon->GetDev());
	// カメラをセット
	FBXObject3d::SetCamera(camera);
	// グラフィックスパイプライン生成
	FBXObject3d::CreateGraphicsPipeline();
	object1 = new FBXObject3d;
	object1->Initialize();
	object1->SetModel(model1);
	object1->SetRotation({0,90,0});
}

void PlayScene::Finalize() {
	delete camera;
	delete object1;
}

void PlayScene::Update(DirectXCommon* dxCommon) {
	camera->Update();
	object1->Update();
	if (input->TriggerKey(DIK_SPACE)) {
		object1->PlayAnimation();
	}
}

void PlayScene::Draw(DirectXCommon* dxCommon) {
	//ImGui::Begin("test");
	//if (ImGui::TreeNode("Debug"))
	//{
	//	if (ImGui::TreeNode("Field"))
	//	{
	//		float a = (float)XorShift::GetInstance()->xor128();
	//		ImGui::SliderFloat("a", &a, 100, 0);
	//		//ImGui::SliderFloat("b", &distanceZ, 50, -50);
	//		ImGui::Unindent();
	//		ImGui::TreePop();
	//	}
	//	ImGui::TreePop();
	//}
	//ImGui::End();
	Sprite::PreDraw();
	BG->Draw();
	Object3d::PreDraw();
	object1->Draw(dxCommon->GetCmdList());

}