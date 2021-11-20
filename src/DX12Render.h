#pragma once
#include "DXSample.h"

class DX12Render : public DXSample {
public:
    DX12Render(UINT width, UINT height, std::wstring name):
        DXSample(width, height, name)
    {
        mWidth = width;
        mHeight = height;
    };

    virtual void OnInit() override;
    virtual void OnUpdate() override;
    virtual void OnRender() override;
    virtual void OnDestroy() override;

private:
    void LoadPipeline();
    void LoadAssets();

private:
    static const UINT FrameCount = 3;

    UINT mWidth = 1;
    UINT mHeight = 1;

    UINT mFrameIndex = 0;

    ComPtr<ID3D12Device>       mDevice;
    ComPtr<ID3D12CommandQueue> mCommandQueue;
    ComPtr<IDXGISwapChain3>    mSwapChain;
    ComPtr<ID3D12CommandList>  mCommandList;
};