#include <OGL3D/Window/OpenGLWindow.h>
#include <OGL3D/Game/OpenGLGame.h>
#include <Windows.h>
#include <assert.h>
#include <iostream>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		OpenGLWindow* window = (OpenGLWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
        std::cout << "DESTROY MSG" << std::endl;
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
        std::cout << "CLOSE MSG" << std::endl;
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


OpenGLWindow::OpenGLWindow()
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"OGL3DWindow";
	wc.lpfnWndProc = &WndProc;

	auto classId = RegisterClassEx(&wc);
	assert(classId);

	RECT rc = { 0,0,1024,768 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

    m_handle = CreateWindowEx(0, MAKEINTATOM(classId), L"Da Spicy Game Window", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

	assert(m_handle);

	SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow((HWND)m_handle, SW_SHOW);
	UpdateWindow((HWND)m_handle);
}

OpenGLWindow::~OpenGLWindow() {
	DestroyWindow(HWND(m_handle));
}
