#ifndef RECTDATA_H
#define RECTDATA_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<filesystem>
#include"Graphics.h"
class RectData
{
public:
     RectData();
    void BindBuffData();
    void Draw();

private:
    unsigned int VBO, VAO, EBO;
    unsigned int texture;
    std::vector<float>vertice = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,  // bottom left
           -0.5f,  0.5f, 0.0f   // top left
       };

      std::vector<int>indices = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

};
#endif // RECTDATA_H
