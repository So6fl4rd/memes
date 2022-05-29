#pragma once

class OpenGLWindow;

class OpenGLGame {
public:
    OpenGLGame();
    ~OpenGLGame();

    void run();
    void quit();

protected:
    bool m_isRunning = true;
    OpenGLWindow* m_display = nullptr;
};