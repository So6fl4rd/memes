#include <OGL3D/Game/OpenGLGame.h>
#include <OGL3D/Window/OpenGLWindow.h>
#include <Windows.h>

OpenGLGame::OpenGLGame() {
    m_display = std::make_unique<OpenGLWindow>();
}

OpenGLGame::~OpenGLGame() {
}

void OpenGLGame::run() {
    MSG msg;
/*    while (m_isRunning && !m_display->isClosed()) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Sleep(1);
    }*/

    while (m_isRunning)	{
		MSG msg = {};
		if (PeekMessage(&msg, HWND(), 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				m_isRunning = false;
				continue;
			} else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		} else {
			Sleep(1);
		}
	}
}

void OpenGLGame::quit() {
    m_isRunning = false;
}