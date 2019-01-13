// StartWechat.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "StartWachat.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
		
	HMODULE hModule = NULL;
	FARPROC fpStartWachat = NULL;
	_TCHAR tzModuleFilePath[MAX_PATH + 1] = { 0 };
	::GetModuleFileName(hInstance, tzModuleFilePath, sizeof(tzModuleFilePath) / sizeof(_TCHAR));
	_stprintf(_tcsrchr(tzModuleFilePath, _T('\\')) + sizeof(CHAR), _T("%s\0"), _T("WeChatWin.dll"));
	hModule = ::LoadLibrary(tzModuleFilePath);
	if (hModule)
	{
		fpStartWachat = ::GetProcAddress(hModule, ("StartWachat"));
		if (fpStartWachat)
		{
			((int(__cdecl *)(HINSTANCE, LPSTR))fpStartWachat)(hInstance, (""));
		}
		FreeLibrary(hModule);
		hModule = NULL;
	}
	return 0;
}
