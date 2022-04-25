#pragma once
#include "Sprite.h"
class PostEffect :
    public Sprite {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PostEffect();

    void Draw(ID3D12GraphicsCommandList* cmdList);

};

