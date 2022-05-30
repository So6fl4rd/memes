#pragma once
#include <memory>

class OpenGLWindow;

class OpenGLGame {
public:
    OpenGLGame();
    ~OpenGLGame();

    void run();
    void quit();

protected:
    bool m_isRunning = true;
    std::unique_ptr<OpenGLWindow> m_display;
};