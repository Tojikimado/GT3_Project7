#include <Windows.h>
#include "Test.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,_In_ int nCmdShow)
{
	Test* tApp = new Test(hInstance);

	if (tApp->Init() == false)
	{
		return 1;
	}

	return tApp->Run();
}


