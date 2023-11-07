#include"RectData.h"
RectData::RectData()
{
    // 顶点数组对象
    glGenVertexArrays(1, &VAO);
    //顶点缓冲对象
    glGenBuffers(1, &VBO);
     glGenBuffers(1, &EBO);
    //绑定VAO
    glBindVertexArray(VAO);
    //把顶点数组复制到缓冲中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertice.size() * sizeof(float), &(vertice[0]), GL_STATIC_DRAW);
//    std::cout<<sizeof(vertice)<<"||" << vertice.size() * sizeof(float)<<"||"<< vertice.size()<< "||" << sizeof(vertice1)<<std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),  &(indices[0]), GL_STATIC_DRAW);

    //设置顶点属性指针
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);
}

void RectData::BindBuffData()
{

}

void RectData::Draw()
{
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
