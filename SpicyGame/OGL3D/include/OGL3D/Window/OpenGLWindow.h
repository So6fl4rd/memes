#pragma once

class OpenGLWindow {
public:
    OpenGLWindow();
    ~OpenGLWindow();

    void onDestroy();
    bool isClosed();
    
private:
    void* m_handle = nullptr;
};