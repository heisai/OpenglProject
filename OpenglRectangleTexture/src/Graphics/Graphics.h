#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<filesystem>
#include<vector>

/*
    1: 图形引擎基类
    2: Draw: 采用多态机制 运行时绑定
*/
class GraphicsEngine
{
public:
    GraphicsEngine();
    virtual void Draw();



public:
     unsigned int m_VBO, m_VAO, m_EBO;
     unsigned int m_Texture, m_Texture1;
};
#endif //GRAPHICSENGINE_H
