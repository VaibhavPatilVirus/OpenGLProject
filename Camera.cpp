#include "VendorAPIsPCH.h"
#include "Camera.h"
#include "CursorPos.h"

Camera::Camera(const int& width, const int& height, const glm::vec3& position) : mWidth(width), mHeight(height)
{
	mView[3] = glm::vec4(position, 1.0);
	mProjection = glm::perspective(glm::radians(45.0f), (float)(mWidth / mHeight), 0.1f, 100.f);
}

Camera::~Camera()
{
}

void Camera::matrix(const Shader& shader, const char* uniform)
{
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(mProjection * mView));
}

void Camera::moveForwardOrBackward(const double& offset)
{
	mView[3] += glm::vec4(0.0f, 0.0f, 1.0f, 0.0f) * (float)offset;
}

void Camera::moveRightOrLeft(const double& offset)
{
	mView[3] += glm::vec4(1.0f, 0.0f, 0.0f, 0.0f) * (float)offset;
}

void Camera::moveUpOrDown(const double& offset)
{
	mView[3] += glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * (float)offset;
}

//void Camera::inputs(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//		moveForward();
//
//	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//		moveBackward();
//
//	//if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//	//	mView = glm::rotate(mView, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//	//
//	//if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//	//	mView = glm::rotate(mView, glm::radians(-1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//
//	CursorPos pos(/* nullptr, */ 0.0f, 0.0f); //TODO: Get cursor pos
//								  //glm::vec3 dirVec(mHeight / 2 - pos.mYPos , pos.mXPos - mWidth / 2, 0.0f);
//	glm::vec3 dirVec(-((mWidth / 2) - pos.getX()), (mHeight / 2) - pos.getY(), 0.0f);
//	float vecLength = glm::length(dirVec);
//	dirVec = glm::normalize(dirVec);
//	if (vecLength > 200)
//		mView = glm::rotate(mView, glm::radians(0.0001f) * vecLength, glm::vec3(-dirVec.y, dirVec.x, 0.0));
//
//	//std::cout << "Relative Pos = (" << dirVec.x << "," << dirVec.y << ") Vector length = " << vecLength <<std::endl;
//
//	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//		moveRight();
//
//	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//		moveLeft();
//}
