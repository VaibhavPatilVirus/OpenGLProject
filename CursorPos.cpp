#include "VendorAPIsPCH.h"
#include "CursorPos.h"

CursorPos::CursorPos(GLFWwindow* window, const float& xPos, const float& yPos) :mpWindow(window), mXPos(xPos), mYPos(yPos) {}

const GLFWwindow* CursorPos::getOwnerWindow() { return mpWindow; }

float CursorPos::getX() { return mXPos; }

float CursorPos::getY() { return mYPos; }

void CursorPos::setOwnerWindow(GLFWwindow* win) { mpWindow = win; }

void CursorPos::setX(float xpos) { mXPos = xpos; }

void CursorPos::setY(float ypos) { mYPos = ypos; }
