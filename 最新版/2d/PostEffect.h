#pragma once
#include "Sprite.h"
class PostEffect :
    public Sprite {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PostEffect();

    void Draw(ID3D12GraphicsCommandList* cmdList);

};

