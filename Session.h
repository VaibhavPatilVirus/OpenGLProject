#pragma once
#include "Application.h"
#include "SessionSettings.h"
/**
 * @brief Common session for a group of application.
*/
class Session
{
private:
	std::vector<Application> mApps;
	SessionSettings mSessionSettings;
public:
	Session();
	virtual ~Session();

	void addApplication(Application& app);

	bool start();

	void shutdown();

};
