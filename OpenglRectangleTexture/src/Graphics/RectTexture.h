#ifndef RECTTEXTURE_H
#define RECTTEXTURE_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<filesystem>

#include"./Graphics.h"
#include"../Utils/Utils.h"

class RectTextureEngine : public GraphicsEngine
{
public:
    RectTextureEngine();
    void Draw() override;
private:
    void InitTextures(unsigned int *data, const std::string& path,bool alpha = true);
    void InitBufferData();

private:
    std::vector<float>m_Vertice = {
                // positions                    // texture coords
                0.5f,  0.5f, 0.0f,     1.0f, 1.0f, // top right
                0.5f, -0.5f, 0.0f,      1.0f, 0.0f, // bottom right
               -0.5f, -0.5f, 0.0f,      0.0f, 0.0f, // bottom left
               -0.5f,  0.5f, 0.0f,      0.0f, 1.0f  // top left
       };
      std::vector<int>m_Indices = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
      unsigned char* data;


};
#endif // RECTTEXTURE_H
