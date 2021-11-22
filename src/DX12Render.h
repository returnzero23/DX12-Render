#pragma once
#include "DXSample.h"
#include "DirectXMath.h"
#include "d3dx12.h"
using namespace DirectX;

class DX12Render : public DXSample {
public:
    DX12Render(UINT width, UINT height, std::wstring name):
        DXSample(width, height, name),
        mViewport(0.0f, 0.0f, static_cast<float>(width), static_cast<float>(height)),
        mScissorRect(0, 0, static_cast<LONG>(width), static_cast<LONG>(height))
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

    std::vector<UINT8> GenerateTextureData();

    void PopulateCommandList();

    void WaitForPreviousFrame();

private:
    static const UINT FrameCount = 2;
    static const UINT TextureWidth = 256;
    static const UINT TextureHeight = 256;
    static const UINT TexturePixelSize = 4;    // The number of bytes used to represent a pixel in the texture.

    struct Vertex
    {
        XMFLOAT3 position;
        XMFLOAT4 color;
        XMFLOAT2 coord;
    };

    UINT mWidth = 1;
    UINT mHeight = 1;

    UINT mFrameIndex = 0;

    UINT mRtvDescriptorSize = 0;

    // Pipeline objects.
    CD3DX12_VIEWPORT mViewport;
    CD3DX12_RECT mScissorRect;

    ComPtr<ID3D12Device>       mDevice;
    ComPtr<ID3D12CommandQueue> mCommandQueue;
    ComPtr<IDXGISwapChain3>    mSwapChain;
    ComPtr<ID3D12GraphicsCommandList>  mCommandList;
    ComPtr<ID3D12CommandAllocator> mCommandAllocator;
    ComPtr<ID3D12RootSignature> mSignature;
    ComPtr<ID3D12PipelineState> mPipelineState;

    ComPtr<ID3D12DescriptorHeap> mRtvHeap;
    ComPtr<ID3D12DescriptorHeap> mSrvHeap;

    ComPtr<ID3D12Resource> mRenderTargets[FrameCount];
    ComPtr<ID3D12Resource> mVertexBuffer;
    ComPtr<ID3D12Resource> mTexture;
    D3D12_VERTEX_BUFFER_VIEW mVertexBufferView;

    // Synchronization objects.
    HANDLE mFenceEvent = 0;
    ComPtr<ID3D12Fence> mFence;
    UINT64 mFenceValue = 0;
};