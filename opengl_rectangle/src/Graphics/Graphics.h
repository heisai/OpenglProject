#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<filesystem>
#include<vector>
/*
    1: ͼ���������
    2: Draw: ���ö�̬���� ����ʱ��
*/
class GraphicsEngine
{
public:
    GraphicsEngine();
    virtual void Draw();

protected:
     unsigned int m_VBO, m_VAO, m_EBO;
     unsigned int m_Texture;
};
#endif //GRAPHICSENGINE_H
