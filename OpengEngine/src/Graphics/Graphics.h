#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
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
    GraphicsEngine(std::shared_ptr<Shader> shader = nullptr);
    virtual void Draw() = 0;
    virtual void InitBufferData() = 0;
    virtual void Drawwind(GLFWwindow* window);

    /*virtual ~ GraphicsEngine();*/
public:
     unsigned int m_VBO, m_VAO, m_EBO;
     unsigned int m_Texture, m_Texture1;
     std::shared_ptr<Shader>m_shader;
};
#endif //GRAPHICSENGINE_H
