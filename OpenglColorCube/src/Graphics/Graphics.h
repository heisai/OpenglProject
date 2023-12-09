#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<filesystem>
#include<vector>
#include<memory>
#include"../Shader.h"

/*
    1: 图形引擎基类
    2: Draw: 采用多态机制 运行时绑定
*/
class GraphicsEngine
{
public:
    GraphicsEngine();
    virtual void Draw() = 0;
    virtual void InitBufferData() = 0;
public:
     unsigned int m_VBO, m_VAO, m_EBO;
     unsigned int m_Texture, m_Texture1;
};
#endif //GRAPHICSENGINE_H
