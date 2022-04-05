#pragma once
#include "VendorAPIsPCH.h"
#include "ApplicationSettings.h"
#include "IWindow.h"
/**
 * @brief Individual application instance.
*/
class Application
{
private:
	ApplicationSettigs mAppSettings;
	std::shared_ptr<Window> mWindow;
	bool doRun;
public:
	Application();
	Application(const Application& app)
	{
		mAppSettings = app.mAppSettings;
		mWindow = app.mWindow;
	};
	virtual ~Application();
	/*Application(const Application& other)
	{
		mAppSettings = other.mAppSettings;
		mWindow = std::move(other.mWindow);
	}*/

	bool start();
	void terminate();
	void Init();
};


