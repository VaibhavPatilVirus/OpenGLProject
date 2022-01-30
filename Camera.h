#pragma once
#include "ShaderClass.h"
#include "CursorPos.h"

class Camera
{
public:
	int mWidth;
	int mHeight;

	//float mSpeed = 0.001f;
	//float mSensitivity = 100.0f;

	glm::mat4 mView = glm::mat4(1.0f);
	glm::mat4 mProjection = glm::mat4(1.0f);

	//float rot = 0;

	Camera(const int& width, const int& height, const glm::vec3& position);
	virtual ~Camera();
	void matrix(const Shader& shader, const char* uniform);

	void moveForwardOrBackward(const double& offset);
	void moveRightOrLeft(const double& offset);
	void moveUpOrDown(const double& offset);

	//void inputs(GLFWwindow* window);
};

