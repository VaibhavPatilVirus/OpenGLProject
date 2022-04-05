#pragma once
#include "Camera.h"
#include "ScrollOffset.h"
#include "MouseEvent.h"
#include <Circle.h>
#include <Cube.h>
#include <Plane.h>


struct WindowSize
{
    int mWidth;
    int mHeight;

    WindowSize(const int& width, const int& height) : mWidth(width), mHeight(height) {}
};

struct WindowData
{
    WindowSize size = WindowSize(0, 0);
    std::string mTitle = "";
};

struct ViewPortDimensions
{
    glm::vec2 mTopLeftCorner = glm::vec2(0, 0);
    glm::vec2 mBottomLeftCorner = glm::vec2(0, 0);

    ViewPortDimensions(const float& x1, const float& y1, const float& x2, const float& y2)
        :mTopLeftCorner(glm::vec2(x1, y1)), mBottomLeftCorner(glm::vec2(x2, y2)) {}
};

class IWindow
{
private:
    GLFWwindow* mpWindow;
    Camera* mpCamera;
    unsigned int mId;
    CursorPos mCursorPos;

    void generateWindowId();

protected:
    IWindow(const int& width, const int& height);

    virtual ~IWindow();

    IWindow* getUserWindowPointer();

    bool setUserWindowPointer();

    bool init();

    void render();


    static void callbackMouseButton(GLFWwindow* window, int button, int action, int mods);
    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
    static void callbackScroll(GLFWwindow* window, double xoffset, double yoffset);

public:
    int mWidth = 800;
    int mHeight = 800;

    unsigned int getWindowId();

    virtual Camera* getCamera();


    void setCursorPos(const double& xpos, const double& ypos);
    void notifyScroll(ScrollOffset& offset);
    //void notifyMouseButtonEvent(const MouseEvent& mouseEvent);

    static IWindow* getUserWindowPointer(GLFWwindow* win);
};

class Window
{
    GLFWwindow* mGLFWwindow;
    Camera* mpCamera;
    unsigned int mId = 0;

    void generateWindowId()
    {
        if (mId == 0)
        {
            static unsigned int nextId = 1;
            mId = nextId;
            ++nextId;
        }
    }

    Window() = delete;
    //void callbackMouseButton(GLFWwindow* window, int button, int action, int mods)
    //{
    //    //if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    //    MouseButtonEvent mouseEvent(button, action);
    //    IWindow* win = IWindow::getUserWindowPointer(window);
    //    if (win)
    //        win->notifyMouseButtonEvent(mouseEvent);

    //}

    static void callbackScroll(GLFWwindow* window, double xoffset, double yoffset);

    static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

    Window(GLFWwindow* GLFWwindow)
    {
        if (GLFWwindow == nullptr)
            std::exception("GLFWwindow pointer cannot be null");

        mGLFWwindow = GLFWwindow;
        generateWindowId();
        glfwSetWindowUserPointer(mGLFWwindow, this);
        makeCurrentContext();
        gladLoadGL();
        //glfwSetMouseButtonCallback(mpWindow, IWindow::callbackMouseButton);
        glfwSetCursorPosCallback(mGLFWwindow, Window::cursorPosCallback);
        glfwSetScrollCallback(mGLFWwindow, Window::callbackScroll);
        WindowSize size = getSize();
        mpCamera = new Camera(size.mWidth, size.mHeight, glm::vec3(0.0f, 0.0f, -2.0f));
        setViewport(ViewPortDimensions(0, 0, size.mWidth, size.mHeight));
    }



public:


    virtual ~Window()
    {
        if (mGLFWwindow)
            glfwDestroyWindow(mGLFWwindow);//Delete the window before terminating the program

        if (mpCamera)
            delete mpCamera;
    }

    void clearColor()
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    }

    void clearBufferBits()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void enableDepthTest()
    {
        glEnable(GL_DEPTH_TEST);
    }

    bool isRunning()
    {
        return !glfwWindowShouldClose(mGLFWwindow);
    }

    void draw()
    {
        
        clearColor();
        clearBufferBits();
        Shader shaderProgram("Default.vert", "default.frag");
        shaderProgram.Activate();
        mpCamera->matrix(shaderProgram, "camMatrix");
        Circle circle(1);
        Cube cube(1.0f);
        Plane plane(1, 2);
        Plane plane2(1, 2);
        circle.createMesh();
        plane.createMesh();
        plane2.createMesh();
        plane2.rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        cube.draw();
        plane.draw();
        plane2.draw();
        circle.draw();
        swapBuffers();
        pollEvents();
    }

    void swapBuffers()
    {
        glfwSwapBuffers(mGLFWwindow);
    }

    void pollEvents()
    {
        glfwPollEvents(); //Take care of all GLFW events
    }

    WindowSize getSize() {
        int width, height;
        glfwGetWindowSize(mGLFWwindow, &width, &height);
        return WindowSize(width, height);
    }

    void makeCurrentContext()
    {
        glfwMakeContextCurrent(mGLFWwindow); //Set created window for use.
    }

    void setViewport(const ViewPortDimensions& viewport)
    {
        glViewport(viewport.mTopLeftCorner.x, viewport.mTopLeftCorner.y,
            viewport.mBottomLeftCorner.x, viewport.mBottomLeftCorner.y);
    }

    static Window* createWindow(const WindowData& data)
    {
        //Little data validation.
        if (data.size.mWidth < 1 || data.size.mHeight < 1)
            std::exception("Invalid window size.");
        if (data.mTitle.empty())
            std::exception("Window title cannot be empty.");

        std::mutex m;
        std::lock_guard<std::mutex> lock(m);
        const char* title = data.mTitle.c_str();
        GLFWwindow* window = nullptr;
        window = glfwCreateWindow(data.size.mWidth, data.size.mHeight, title, nullptr, nullptr);
        if (window != nullptr) //Error check if  the window fails to create
        {
            Window* windowObject = new Window(window);
            TRACE("Window intialized successfully.")
                return windowObject;
        }
        else
            ERROR("Failed to create window.")

            return nullptr;
    }

};

class CreateWindow
{

};