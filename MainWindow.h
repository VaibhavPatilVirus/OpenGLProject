#pragma once
#include "IWindow.h"

class MainWindow : public IWindow
{
private:


public:
	MainWindow(const int& width, const int& height);

	bool init();

	void processEvents();

	bool show();

	virtual ~MainWindow();
};


