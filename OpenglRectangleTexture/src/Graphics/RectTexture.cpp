#include"RectTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
RectTextureEngine::RectTextureEngine():GraphicsEngine()
{
    InitBufferData();
    InitTextures(&m_Texture,"E:\\wall.jpg");
    InitTextures1(&m_Texture1,"E:\\awesomeface.png");


}


void RectTextureEngine::Draw()
{
    
   
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_Texture1);
    //设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



void RectTextureEngine::InitTextures(unsigned int *texture, const std::string& path,bool alpha )
{

        // texture 1
        // ---------
        glGenTextures(1, texture);
        glBindTexture(GL_TEXTURE_2D, *texture);
         // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;

        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
}

void RectTextureEngine::InitTextures1(unsigned int *texture, const std::string &path, bool alpha)
{
       glGenTextures(1, texture);
       glBindTexture(GL_TEXTURE_2D, *texture);
       // set the texture wrapping parameters
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
       // set texture filtering parameters
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
       // load image, create texture and generate mipmaps
       int width, height, nrChannels;
       data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
       if (data)
       {
           // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
           glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
           glGenerateMipmap(GL_TEXTURE_2D);
       }
       else
       {
           std::cout << "Failed to load texture" << std::endl;
       }
       stbi_image_free(data);
}

void RectTextureEngine::InitBufferData()
{
    // 顶点数组对象
    glGenVertexArrays(1, &m_VAO);
    //顶点缓冲对象
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    //绑定VAO
    glBindVertexArray(m_VAO);
    //把顶点数组复制到缓冲中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glBufferData(GL_ARRAY_BUFFER, m_Vertice.size() * sizeof(float), &(m_Vertice[0]), GL_STATIC_DRAW);
//    std::cout<<sizeof(vertice)<<"||" << vertice.size() * sizeof(float)<<"||"<< vertice.size()<< "||" << sizeof(vertice1)<<std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Indices),  &(m_Indices[0]), GL_STATIC_DRAW);
}
