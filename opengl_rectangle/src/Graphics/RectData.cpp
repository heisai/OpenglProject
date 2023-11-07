#include"RectData.h"
RectData::RectData()
{
    // �����������
    glGenVertexArrays(1, &VAO);
    //���㻺�����
    glGenBuffers(1, &VBO);
     glGenBuffers(1, &EBO);
    //��VAO
    glBindVertexArray(VAO);
    //�Ѷ������鸴�Ƶ������й�OpenGLʹ��
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertice.size() * sizeof(float), &(vertice[0]), GL_STATIC_DRAW);
//    std::cout<<sizeof(vertice)<<"||" << vertice.size() * sizeof(float)<<"||"<< vertice.size()<< "||" << sizeof(vertice1)<<std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),  &(indices[0]), GL_STATIC_DRAW);

    //���ö�������ָ��
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
