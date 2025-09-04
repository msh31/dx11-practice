#include <Windows.h>

// this is the entry point for a win32 applicatiion
// the callback modifier tells C++ to use a diff convention (stdcall) | will need to dig into thisi more
// the HINSTANCE's are pointers to structures that hold information about our program, like where it's loaded into memory. 2nd param is always NULL
// lpCmdLine is the command line, for instance when you pass custom paramters to the program 
// nCmdShow controls how the window is shown
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// register window class
	const auto pClassName = L"marcod3d";

	WNDCLASSEX windowClass = { 0 };
	windowClass.cbSize = sizeof(windowClass);
	windowClass.style = CS_OWNDC;
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = nullptr;
	windowClass.hCursor = nullptr;
	windowClass.hbrBackground = nullptr;
	windowClass.lpszMenuName = nullptr;
	windowClass.lpszClassName = pClassName;
	windowClass.hIconSm = nullptr;

	RegisterClassEx(&windowClass);

	// create window instance
	int windowWidth = 480;
	int windowHeight = 640;

	HWND hWnd = CreateWindowEx(0, pClassName, L"Marco D3D", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 500, 500, windowWidth, windowHeight, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(hWnd, SW_SHOW);

	while (true);
	return 0;
}