#pragma once
#include"Object3d.h"
#include"Model.h"
#include <DirectXMath.h>
#include <Input.h>
#include"CollisionPrimitive.h"
#include "Sprite.h"
#include "Texture.h"
#include "BossEnemy.h"

class Effect {
public:
	Effect();

	void Initialize();
	void Finalize();
	void Update(BossEnemy* bossenemy);
	void Draw();
private:
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;
public:
	
	/// <summary>
/// ���W�̎擾
/// </summary>
/// <returns>���W</returns>
	//const XMFLOAT3& GetPosition() { return  object3d->GetPosition(); }

	//const XMFLOAT3& GetRotation() { return object3d->GetRotation(); }

	/// <summary>
	/// ���W�̐ݒ�
	/// </summary>
	/// <param name="position">���W</param>
	//void SetPosition(XMFLOAT3 position) { object3d->SetPosition(position); }

	//void SetRotation(XMFLOAT3 rotation) { object3d->SetRotation(rotation); }

	//void SetEffectAlive(bool effectAlive) { this->effectAlive = effectAlive; }

	void SetEffectPosition(XMFLOAT3 effectpos) { this->effectpos = effectpos; }

	void EffectMove();

private:
	/*Object3d* Armobj;
	Object3d* object3d;
	Model* model;
	Model* Armmodel;*/
	XMFLOAT3 pos = { 0,0,-10 };
	
	//�G�t�F�N�g�֌W
	Texture* effecttexture = nullptr;
	XMFLOAT3 effectpos = { 0.0f,0.0f,0.0f };
	XMFLOAT4 effectcolor = { 0.0f,0.0f,0.0f,1.0f };
	XMFLOAT3 effectscale = { 0.4f,0.4f,0.4f };
	XMFLOAT3 boundpower = { 0.0f,0.0f,0.0f };
	bool effectAlive = 0;
	int randColor = 0;
public:
	Sphere collider;
};