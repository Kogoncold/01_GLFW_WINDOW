#include <glad/glad.h>
#include <iostream>
#include <string>
#include <assert.h>//断言
#include "checkError.h"
typedef std::string errorPrint;

void checkError()
{
    GLenum errorCode = glGetError();
    errorPrint error = "";
    if (errorCode != GL_NO_ERROR) {
        switch (errorCode)
        {
        case GL_INVALID_ENUM:
            error = "GL_INVALID_ENUM";
            break;//无效枚举
        case GL_INVALID_VALUE:
            error = "GL_INVALID_VALUE";
            break;//无效值
        case GL_INVALID_OPERATION:
            error = "Gl_INVALID_OPERATION";
            break;//非法操作
        case GL_OUT_OF_MEMORY:
            error = "GL_OUT_OF_MEMORY";
            break;//内存不足
        default:
            error = "未知错误";
            break;
        }
        std::cout << "OpenGL错误:" << error << "\n";
        assert(false);//assert会根据传入的bool值决定是否终止程序
    };
}