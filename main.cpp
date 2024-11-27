#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>
#include <assert.h>//断言
#include "head.h"
#include "wrapper/checkError.h"
#include "application/Application.h"

//声明且实现一个响应窗口大小变化的函数
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    std::cout << "窗体最新大小:" << width << "x" << height << "\n";
    GL_CALL(glViewport(0, 0, width, height));
}
//声明且实现一个键盘消息回调函数
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "触发了:" << key << "\n";
    std::cout << "action:" << action << "\n";
    std::cout << "mods:" << mods << "\n";
}
int main()
{
    app->test();
    //初始化GLFW基本环境
    glfwInit();
    //设置OpenGL主版本号、次版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //设置OpenGL启用核心模式(非立即渲染模式）
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //创建窗体对象
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    //决定用户是否可以调整窗体大小
    GLFWwindow* window = glfwCreateWindow(1920, 1080, "LearnOpenGL", nullptr, nullptr);
    //检查是否创建成功
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << "\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }
    //设置当前窗体对象为OpenGL的绘制舞台
    glfwMakeContextCurrent(window);
    //设置监听，监听窗体大小变化的消息
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    //设置监听，监听键盘消息
    glfwSetKeyCallback(window, keyCallBack);
    //使用glad加载所有当前版本的OpenGL函数
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << "\n";
        return EXIT_FAILURE;
    }
    //设置opengl视口及清理颜色
    GL_CALL(glViewport(0, 0, 1920, 1080));
    GL_CALL(glClearColor(0, 0, 255, 1.0f));
    //执行窗体循环
    while (!glfwWindowShouldClose(window)) {
        //接收并分发窗体消息
        //检查消息队列是否有需要处理的鼠标键盘等消息
        //如果有的话就将消息批量处理，清空队列
        glfwPollEvents();
        //执行opengl画布清理操作
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
        
        //渲染操作
        //切换双缓存
        glfwSwapBuffers(window);
    }
    //退出程序前做相关清理
    glfwTerminate();
    //system("pause");
    return EXIT_SUCCESS;
}