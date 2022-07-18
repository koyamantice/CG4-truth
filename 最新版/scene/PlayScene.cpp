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



	model2 = Model::CreateFromOBJ("skydome");

	object2 = new Object3d;
	object2->Initialize();
	object2->SetModel(model2);
	object2->SetPosition({ 3,0,0 });
	object2->SetRotation({ 0,0,0 });
	object2->SetScale({ 3,3,3 });

	model = Model::CreateFromOBJ("dragon");

	object = new Object3d;
	object->Initialize();
	object->SetModel(model);
	object->SetPosition({5,0,-8});
	object->SetRotation({ 0,0,0 });
	object->SetScale({ 3,3,3 });

	//model3 = Model::CreateFromOBJ("ball");

	//object3 = new Object3d;
	//object3->Initialize();
	//object3->SetModel(model3);
	//object3->SetPosition({ -5,0,-8 });
	//object3->SetRotation({ 0,0,0 });
	//object3->SetScale({ 3,3,3 });

}

void PlayScene::Finalize() {
	delete camera;
	delete object1;
}

void PlayScene::Update(DirectXCommon* dxCommon) {
	camera->Update();
	//fbx
	object1->Update();
	//obj
	object->Update();
	object->SetColor(color);
	object2->Update();
	//object3->Update();

	if (input->TriggerKey(DIK_SPACE)) {
		object1->PlayAnimation();
	}
}

void PlayScene::Draw(DirectXCommon* dxCommon) {
	ImGuiDraw();
	//Sprite::PreDraw();
	//BG->Draw();

	Object3d::PreDraw();
	object2->Draw();
	object->Draw();
	//object3->Draw();
	object1->Draw(dxCommon->GetCmdList());

}

void PlayScene::ImGuiDraw() {
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

}
