#ifndef RECTDATA_H
#define RECTDATA_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<filesystem>
#include<vector>
class Graphics
{
public:
     Graphics();
protected:
    virtual void BindBuffData() = 0;
    virtual void Draw() = 0;

private:
    unsigned int VBO, VAO, EBO;
    unsigned int texture;
};
#endif // RECTDATA_H
