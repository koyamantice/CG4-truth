#pragma once
#include"InterEnemy.h"
#include"Rice.h"
#include"ModelManager.h"

class BossEnemy :public InterEnemy {
public:
	BossEnemy();

	void Initialize() override;
	void Finalize() override;
	void Update()override;
	void Draw() override;
private:
	bool collidePlayer() override;
	bool collideAttackArm() override;
	void Fork();
public:
	void SetPlayer(Player* player) { this->player = player; }
	const float& GetHP() { return BossHP; }
	const bool& GetHit() { return BossHit; }
	const bool& GetEffect() { return Effect; }
	void SetHP(float BossHP) { this->BossHP = BossHP; }
	void SetEffect(bool Effect) { this->Effect = Effect; }
private:
	float Afterrot = 90;//��������
	//
	float BossHP = 40;
	bool BossHit = false;
	bool Effect = false;
	//
	int AttackCount = 0;
	bool already = false;
	//
	bool active = false;//�s���J�n
	int action = 0;//�U���̎��
	int pat = 0;//�p�^�[��
	int aiming = 0;//�G�Ǐ]
	int coolT = 0;//�N�[���^�C��
	int AttackC = 0;//����U��������
	bool finish = false;//�t�B�j�b�V��

};