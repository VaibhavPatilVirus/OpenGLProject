#pragma once
#include "Camera.h"

class ViewPort
{
private:
	int mWidth;
	int mHeight;
	Camera mCamera;
public:
	ViewPort(const int& width, const int& height);
};

