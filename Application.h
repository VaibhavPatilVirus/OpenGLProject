#pragma once
#include "VendorAPIsPCH.h"
#include "ApplicationSettings.h"
#include "MainWindow.h"
/**
 * @brief Individual application instance.
*/
class Application
{
private:
	ApplicationSettigs mAppSettings;
	std::shared_ptr<MainWindow> mWindow;
public:
	Application();
	virtual ~Application();
	/*Application(const Application& other)
	{
		mAppSettings = other.mAppSettings;
		mWindow = std::move(other.mWindow);
	}*/
	bool window1();

	bool start();
};


