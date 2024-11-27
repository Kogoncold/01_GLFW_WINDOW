#include "Application.h"

//初始化Application的静态变量
Application* Application::mInstance = nullptr;
Application* Application::getInstance() 
{
	//如果mInstance已将实例化（new出来了），就直接返回
	//否则，就需要先new出来，再返回
	if (mInstance == nullptr) {
		mInstance = new Application();
	}
	return mInstance;
}
Application::Application() 
{

}
Application::~Application()
{

}