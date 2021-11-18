#include <iostream>
#include <Windows.h>

#include "DX12Render.h"

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow){
	DX12Render sample(1080,720,L"DX12-Render");
	int result = Win32Application::Run(&sample, hInstance, nCmdShow);
	return 0;
}