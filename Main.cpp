#include"VendorAPIsPCH.h"
#include "Session.h"
#include "Application.h"



//enum Axis
//{
//	XAxis,
//	YAxis,
//	ZAxis,
//};
//
//class AxisRotationContext
//{
//public :
//	Axis mAxis = Axis::XAxis;
//};
//
//AxisRotationContext axisRotationConxt;

//class IListener
//{
//public:
//	virtual ~IListener(){}
//};
//
//class IBroadcaster
//{
//protected:
//	void attachListener(IListener* listener)
//	{
//		mListeners.push_back(listener);
//	}
//
//	void dettachListener(IListener* listener)
//	{
//		for (auto listnerPos = mListeners.begin(); listnerPos != mListeners.end(); listnerPos++)
//		{
//			if (*listnerPos._Ptr == listener)
//				mListeners.erase(listnerPos);
//		}
//	}
//	std::vector<IListener*> mListeners;
//};

//class Cursor
//{
//
//public:
//
//	static CursorPos getCursorPos() { return Cursor::curentCursorPos; }
//	/*static void setCursorPos(const double& xpos, const double& ypos)
//	{
//	}*/
//
//	static void callbackCursorPos(GLFWwindow* window, double xpos, double ypos)
//	{
//		Cursor::curentCursorPos.setOwnerWindow(window);
//		Cursor::curentCursorPos.setX(xpos);
//		Cursor::curentCursorPos.setY(ypos);
//		//std::cout << "Mouse Pos = (" << xpos << "," << ypos << ")" << std::endl;
//	}
//};


//typedef std::vector<Plane> PlaneListVec;
//typedef PlaneListVec FaceListVec;
//
//#define NUMBER_OF_CUBE_FACES 6






int main()
{

	Session session;
	Application App;
	Application App1;
	Application App2;
	session.addApplication(App);
	session.addApplication(App1);
	session.addApplication(App2);
	session.start();
	session.shutdown();


	return 0;
}