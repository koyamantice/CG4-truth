#pragma once
#include "BaseScene.h"
#include <array>       // ヘッダファイルインクルード
using namespace std;         //  名前空間指定
class CollisionManager;
class TouchableObject;
/// <summary>
/// ゲームプレイシーン
/// </summary>
const int StartEnemyMax = 10;
const int Spawn = 3;
const int BlockMax = 4;
class PlayScene : public BaseScene {

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(DirectXCommon* dxCommon) override;
	/// <summary>
	/// 終了
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update(DirectXCommon* dxCommon) override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw(DirectXCommon* dxCommon) override;
	void ImGuiDraw() override;

private:
	XMFLOAT3 cameraPos = { 0.0f,20.0f,0.0f };

	XMFLOAT4 color = { 1,1,0,1 };

	FBXModel* model1 = nullptr;
	FBXObject3d* object1 = nullptr;
	Model* model = nullptr;
	
	Object3d* object = nullptr;
	
	Model* model2 = nullptr;

	Object3d* object2 = nullptr;
	Model* model3 = nullptr;

	Object3d* object3 = nullptr;


	DebugCamera* camera = { nullptr };
	Sprite* BG = nullptr;
};

