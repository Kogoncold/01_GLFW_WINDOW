#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>
#include <assert.h>//����
#include "head.h"
#include "wrapper/checkError.h"
#include "application/Application.h"

//������ʵ��һ����Ӧ���ڴ�С�仯�ĺ���
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    std::cout << "�������´�С:" << width << "x" << height << "\n";
    GL_CALL(glViewport(0, 0, width, height));
}
//������ʵ��һ��������Ϣ�ص�����
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "������:" << key << "\n";
    std::cout << "action:" << action << "\n";
    std::cout << "mods:" << mods << "\n";
}
int main()
{
    app->test();
    //��ʼ��GLFW��������
    glfwInit();
    //����OpenGL���汾�š��ΰ汾��
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //����OpenGL���ú���ģʽ(��������Ⱦģʽ��
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //�����������
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    //�����û��Ƿ���Ե��������С
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "LearnOpenGL", nullptr, nullptr);
    //����Ƿ񴴽��ɹ�
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << "\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    //���õ�ǰ�������ΪOpenGL�Ļ�����̨
    glfwMakeContextCurrent(window);
    //���ü��������������С�仯����Ϣ
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    //���ü���������������Ϣ
    glfwSetKeyCallback(window, keyCallBack);
    //ʹ��glad�������е�ǰ�汾��OpenGL����
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << "\n";
        return EXIT_FAILURE;
    }
    //����opengl�ӿڼ�������ɫ
    GL_CALL(glViewport(0, 0, 1920, 1080));
    GL_CALL(glClearColor(0, 0, 255, 1.0f));
    //ִ�д���ѭ��
    while (!glfwWindowShouldClose(window)) {
        //���ղ��ַ�������Ϣ
        //�����Ϣ�����Ƿ�����Ҫ����������̵���Ϣ
        //����еĻ��ͽ���Ϣ����������ն���
        glfwPollEvents();
        //ִ��opengl�����������
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
        
        //��Ⱦ����
        //�л�˫����
        glfwSwapBuffers(window);
    }
    //�˳�����ǰ���������
    glfwTerminate();
    //system("pause");
    return EXIT_SUCCESS;
}