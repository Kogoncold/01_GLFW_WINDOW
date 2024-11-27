#pragma once
#include <iostream>

#define app Application::getInstance()
class Application 
{
public:
	//用于访问实例的静态函数
	static Application* getInstance();
	void test() 
	{
		std::cout << "test" << "\n";
	}
	~Application();
private:
	//全局唯一的静态变量实例
	static Application* mInstance;
	Application();
};