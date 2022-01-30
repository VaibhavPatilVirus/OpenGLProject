#include "VendorAPIsPCH.h"
#include "ViewPort.h"

ViewPort::ViewPort(const int& width, const int& height) : mWidth(width), mHeight(height), mCamera(Camera(width, height, glm::vec3(0.0f, 0.0f, -2.0f))) {}
