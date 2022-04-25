#pragma once
#include "Sprite.h"
class PostEffect :
    public Sprite {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    PostEffect();
    void Initialize();
    void Draw(ID3D12GraphicsCommandList* cmdList);
public:
    ComPtr<ID3D12Resource> texBuff;

    ComPtr<ID3D12DescriptorHeap> descHeapSRV;

};

