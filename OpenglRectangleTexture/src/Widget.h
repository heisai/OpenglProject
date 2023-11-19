#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include"Shader.h"
class GraphicsEngine;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Widget
{
public:

    Widget(const std::string& title = "opengl",int width = 800, int height = 600 );
    /*!
    @Description : 设置颜色
    @Author      : HeiSai
    @Parameter   : 参数说明
    @Return      : 返回值说明
    @Date        : 2023-04-03 23:22:01
*/
    void SetBackGround(GLfloat red,GLfloat green,GLfloat blue);
    void SetShader(const std::shared_ptr<Shader> &shader_value);
    void SetGraphics(const std::shared_ptr<GraphicsEngine> &graphics_value);
    /*!
    @Description : 事件循环展示
    @Author      : HeiSai
    @Parameter   : 参数说明
    @Return      : 返回值说明
    @Date        : 2023-04-03 23:22:45
*/
	void Show();
	void SetWindowTitle(const std::string& title);
private:
    /*!
    @Description : 初始化Glfw
    @Author      : HeiSai
    @Parameter   : 参数说明
    @Return      : 返回值说明
    @Date        : 2023-04-03 22:53:47
*/
	void InitWidget();
    /*!
    @Description : GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD
    @Author      : HeiSai
    @Parameter   : 参数说明
    @Return      : 返回值说明
    @Date        : 2023-04-03 22:55:39
*/
    int  LoadGlad();
    /*!
    @Description : 事件输入
    @Author      : HeiSai
    @Parameter   : 参数说明
    @Return      : 返回值说明
    @Date        : 2023-04-03 23:01:31
*/
    void ProcessInput();
    void DrawGraphics();

private:
    std::string title_text; // 标题
    int m_witdh ;
    int m_height;
    GLFWwindow* window;     // 窗体
    GLfloat m_red;          // 颜色
    GLfloat m_green;
    GLfloat m_blue;

    std::shared_ptr<Shader>m_Shader;
    std::shared_ptr<GraphicsEngine>m_RectData;


};
