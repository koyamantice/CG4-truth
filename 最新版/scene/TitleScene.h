#pragma once
#include "SceneManager.h"
/// <summary>
/// �^�C�g���V�[��
/// </summary>

class TitleScene : public BaseScene {
	public:

		/// <summary>
		/// ������
		/// </summary>
		void Initialize(DirectXCommon* dxCommon) override;
		/// <summary>
		/// �I��
		/// </summary>
		void Finalize() override;

		/// <summary>
		/// ���t���[���X�V
		/// </summary>
		void Update(DirectXCommon* dxCommon) override;
		/// <summary>
		/// �`��
		/// </summary>
		void Draw(DirectXCommon* dxCommon) override;

	private:
		Sprite* sprite = { nullptr };
};

