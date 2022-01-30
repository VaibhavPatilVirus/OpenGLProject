#include "VendorAPIsPCH.h"
#include "MainWindow.h"

MainWindow::MainWindow(const int& width, const int& height) : IWindow(width, height)
{

}

bool MainWindow::init()
{
	return __super::init();
}

void MainWindow::processEvents()
{
}

bool MainWindow::show()
{
	render();
	return true;
}

MainWindow::~MainWindow()
{

}
