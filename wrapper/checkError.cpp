#include <glad/glad.h>
#include <iostream>
#include <string>
#include <assert.h>//����
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
            break;//��Чö��
        case GL_INVALID_VALUE:
            error = "GL_INVALID_VALUE";
            break;//��Чֵ
        case GL_INVALID_OPERATION:
            error = "Gl_INVALID_OPERATION";
            break;//�Ƿ�����
        case GL_OUT_OF_MEMORY:
            error = "GL_OUT_OF_MEMORY";
            break;//�ڴ治��
        default:
            error = "δ֪����";
            break;
        }
        std::cout << "OpenGL����:" << error << "\n";
        assert(false);//assert����ݴ����boolֵ�����Ƿ���ֹ����
    };
}