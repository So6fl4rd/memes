#pragma once

class OpenGLWindow {
public:
    OpenGLWindow();
    ~OpenGLWindow();
private:
    void* m_handle = nullptr;
};