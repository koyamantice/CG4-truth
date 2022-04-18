#pragma once
#include"Sprite.h"
#include"Player.h"
#include"Rice.h"
#include"BossEnemy.h"

class UI {
public:
	UI(Player* player, BossEnemy* boss = nullptr);
	void Update();
	const void Draw();
private:
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;
private:
	Player* player = nullptr;
	BossEnemy* boss = nullptr;

	Sprite* BossHp = nullptr;
	Sprite* PlaHp = nullptr;
	Sprite* Life = nullptr;
	Sprite* Arrow = nullptr;
	Sprite* Vignette = nullptr;

	XMFLOAT2 bossPos{};
	XMFLOAT2 plaPos{};
	XMFLOAT2 ArrowPos{};
	XMFLOAT2 AfterPos[2]{};

	const float PI = 3.145265f;
	float speed = 0;
	float radius = 0;
	float scale = 150;
	double a;
	double b;
	XMFLOAT2 basePos = { 1280 / 2,720 / 2 };
	XMFLOAT2 circle{};
	XMFLOAT3 pos{};
	double posR;
	float Check;
	float Check2;
	int invisible = false;
private:
	void SeachBoss();
};

