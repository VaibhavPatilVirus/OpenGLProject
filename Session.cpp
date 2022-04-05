#include "VendorAPIsPCH.h"
#include "Session.h"


Session::Session()
{
	//Initilize GLFW library for use
	glfwInit();
	//Tell GLFW what version of OpenGL we are using (OpenGL 3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Session::~Session()
{
	//Terminate GLFW before ending program
	glfwTerminate();
}

void Session::addApplication(Application& app)
{
	mApps.push_back(app);
}

bool Session::start()
{
	bool es = false;
	std::vector<std::thread> appThreads;
	for (Application& app : mApps)
	{
		std::thread appThread(&Application::start, &app);
		appThreads.push_back(std::move(appThread));
	}
	for (std::thread& th : appThreads)
	{
		// If thread Object is Joinable then Join that thread.
		if (th.joinable())
			th.join();
	}
	return es;
}

void Session::shutdown() {}
