#pragma once
#include <iostream>

#define app Application::getInstance()
class Application 
{
public:
	//���ڷ���ʵ���ľ�̬����
	static Application* getInstance();
	void test() 
	{
		std::cout << "test" << "\n";
	}
	~Application();
private:
	//ȫ��Ψһ�ľ�̬����ʵ��
	static Application* mInstance;
	Application();
};