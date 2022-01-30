#pragma once
#include "Camera.h"

class IWindow
{
private:
    GLFWwindow* mpWindow;
    Camera* mpCamera;
    unsigned int mId;

    void generateWindowId();

protected:
    IWindow(const int& width, const int& height);

    virtual ~IWindow();

    IWindow* getUserWindowPointer();

    bool setUserWindowPointer();

    bool init();

    void render();

    static void callbackCursorPos(GLFWwindow* window, double xpos, double ypos);

public:
    int mWidth = 800;
    int mHeight = 800;

    unsigned int getWindowId();

    virtual Camera* getCamera();

    void setCursorPos(const double& xpos, const double& ypos);

    static IWindow* getUserWindowPointer(GLFWwindow* win);
};
