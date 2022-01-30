#pragma once
/**
 * @brief Cursor position in an window.
*/
class CursorPos
{
public:
    CursorPos(GLFWwindow* window, const float& xPos, const float& yPos);

    const GLFWwindow* getOwnerWindow();
    float getX();
    void setX(float xpos);
    float getY();
    void setY(float ypos);

    void setOwnerWindow(GLFWwindow* win);

private:
    GLFWwindow* mpWindow;
    float mXPos;
    float mYPos;
};
