#include "Application.h"

//��ʼ��Application�ľ�̬����
Application* Application::mInstance = nullptr;
Application* Application::getInstance() 
{
	//���mInstance�ѽ�ʵ������new�����ˣ�����ֱ�ӷ���
	//���򣬾���Ҫ��new�������ٷ���
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