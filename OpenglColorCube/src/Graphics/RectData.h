#ifndef RECTDATA_H
#define RECTDATA_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<filesystem>
#include"./Graphics.h"
class RectangleEngine : public GraphicsEngine
{
public:
    RectangleEngine();
    void Draw() override;
    void InitBufferData() override;

private:
    std::vector<float>m_Vertice = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,  // bottom left
           -0.5f,  0.5f, 0.0f   // top left
       };

      std::vector<int>m_Indices = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
//      unsigned int m_VBO, m_VAO, m_EBO;
//      unsigned int m_Texture;
};
#endif // RECTDATA_H
