#include <OGL3D/Game/OpenGLGame.h>
#include <OGL3D/Window/OpenGLWindow.h>
#include <Windows.h>

OpenGLGame::OpenGLGame() {
    m_display = new OpenGLWindow();
}

OpenGLGame::~OpenGLGame() {
    delete m_display;
}

void OpenGLGame::run() {
    MSG msg;
    while (m_isRunning) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Sleep(1);
    }
}

void OpenGLGame::quit() {
    m_isRunning = false;
}