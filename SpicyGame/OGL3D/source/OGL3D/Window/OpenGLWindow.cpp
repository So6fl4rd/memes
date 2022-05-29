#include <OGL3D/Window/OpenGLWindow.h>
#include <Windows.h>
#include <assert.h>

OpenGLWindow::OpenGLWindow() {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = (LPCTSTR) "OpenGLWindow";
    wc.lpfnWndProc = DefWindowProc;

    assert(RegisterClassEx(&wc));

    RECT rc = {0, 0, 1024, 768};
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

    m_handle = CreateWindowEx(0, L"OpenGLWindow", L"Da spicy game window",WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, rc.right-rc.left,rc.bottom-rc.top, NULL, NULL, NULL, NULL);

    assert(m_handle);

    ShowWindow((HWND)m_handle, SW_SHOW);
    UpdateWindow((HWND)m_handle);

}

OpenGLWindow::~OpenGLWindow() {
    DestroyWindow((HWND)m_handle);
}