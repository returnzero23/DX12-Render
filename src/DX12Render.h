#pragma once
#include "DXSample.h"

class DX12Render : public DXSample {
public:
    DX12Render(UINT width, UINT height, std::wstring name):
        DXSample(width, height, name)
    {};

    virtual void OnInit() override;
    virtual void OnUpdate() override;
    virtual void OnRender() override;
    virtual void OnDestroy() override;
};