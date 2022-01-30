#include "VendorAPIsPCH.h"
#include "IWindow.h"
#include "Circle.h"
#include "Plane.h"
#include "Cube.h"
#include "CursorPos.h"

void IWindow::generateWindowId()
{
	static unsigned int nextId = 1;
	mId = nextId;
	++nextId;
}

IWindow::IWindow(const int& width, const int& height)
{
	mId = 0;
	mWidth = width;
	mHeight = height;
	mpWindow = nullptr;
	mpCamera = nullptr;
}

IWindow::~IWindow()
{
	if (mpCamera)
		delete mpCamera;

	if (mpWindow)
		glfwDestroyWindow(mpWindow);//Delete the window before terminating the program
}

IWindow* IWindow::getUserWindowPointer()
{
	return IWindow::getUserWindowPointer(mpWindow);
}

bool IWindow::setUserWindowPointer()
{
	bool es = false;

	if (mpWindow)
	{
		glfwSetWindowUserPointer(mpWindow, this);
		es = true;
	}

	return es;
}

bool IWindow::init()
{
	bool es = false;
	std::mutex m;
	std::lock_guard<std::mutex> lock(m);
	//const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	//mWidth = mode->width;
	//mHeight = mode->height;
	mpWindow = glfwCreateWindow(mWidth, mHeight, "YoutubeOpenGL", nullptr, nullptr);
	if (mpWindow != nullptr) //Error check if  the window fails to create
	{
		//Window is created sucessfully
		generateWindowId(); //Generate unique window Id for this window.
		setUserWindowPointer();
		glfwMakeContextCurrent(mpWindow); //Set created window for use.
		gladLoadGL(); //Load GLAD.
		glViewport(0, 0, mWidth, mHeight); //Specify the viewport of OpenGL in window
		es = true;
		TRACE("Window intialized successfully.")
	}
	else
	{
		ERROR("Failed to create window.")
	}

	return true;
}

void IWindow::render()
{
	Shader shaderProgram("default.vert", "default.frag");

	//Texture
	//int widthImg, heightImg, numColCh;
	//stbi_set_flip_vertically_on_load(true);
	//unsigned char* bytes = stbi_load("pop_cat.png", &widthImg, &heightImg, &numColCh, 0);

	//GLuint texture;
	//glGenTextures(1, &texture);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texture);
	//
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	//glGenerateMipmap(GL_TEXTURE_2D);
	//stbi_image_free(bytes);
	//glBindTexture(GL_TEXTURE_2D, 0);

	//GLuint tex0Uni = glGetUniformLocation(shaderProgram.ID, "tex0");
	//shaderProgram.Activate();
	//glUniform1i(tex0Uni, 0);

	glEnable(GL_DEPTH_TEST);

	mpCamera = new Camera(mWidth, mHeight, glm::vec3(0.0f, 0.0f, -2.0f));
	glfwSetCursorPosCallback(mpWindow, IWindow::callbackCursorPos);
	//Main while loop
	GLfloat rot = 0;
	Circle circle(1);
	Cube cube(1.0f);
	Plane plane(1, 2);
	Plane plane2(1, 2);
	circle.createMesh();
	plane.createMesh();
	plane2.createMesh();
	plane2.rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	while (!glfwWindowShouldClose(mpWindow))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderProgram.Activate();

		mpCamera->matrix(shaderProgram, "camMatrix");
		mpCamera->inputs(mpWindow);

		//glUniform1f(uniId, 3.0f);
		//glBindTexture(GL_TEXTURE_2D, texture);

		//circle.draw();
		//plane.draw();
		//plane2.draw();
		cube.draw();

		glfwSwapBuffers(mpWindow);
		glfwPollEvents(); //Take care of all GLFW events
	}
	shaderProgram.Delete();
	//glDeleteTextures(1, &texture);
}

void IWindow::callbackCursorPos(GLFWwindow* window, double xpos, double ypos)
{
	CursorPos curentCursorPos(window, xpos, ypos);
	IWindow* win = IWindow::getUserWindowPointer(window);
	if (win)
		win->setCursorPos(xpos, ypos);
}

unsigned int IWindow::getWindowId() { return mId; }

Camera* IWindow::getCamera() { return nullptr; }

void IWindow::setCursorPos(const double& xpos, const double& ypos)
{

}

IWindow* IWindow::getUserWindowPointer(GLFWwindow* win)
{
	IWindow* iWin = nullptr;
	if (win)
		iWin = (IWindow*)glfwGetWindowUserPointer(win);

	return iWin;
}
