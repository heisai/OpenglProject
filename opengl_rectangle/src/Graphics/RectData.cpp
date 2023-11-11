#include"RectData.h"
RectangleEngine::RectangleEngine():GraphicsEngine()
{
    // �����������
    glGenVertexArrays(1, &m_VAO);
    //���㻺�����
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    //��VAO
    glBindVertexArray(m_VAO);
    //�Ѷ������鸴�Ƶ������й�OpenGLʹ��
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);


}


void RectangleEngine::Draw()
{
    glBufferData(GL_ARRAY_BUFFER, m_Vertice.size() * sizeof(float), &(m_Vertice[0]), GL_STATIC_DRAW);
//    std::cout<<sizeof(vertice)<<"||" << vertice.size() * sizeof(float)<<"||"<< vertice.size()<< "||" << sizeof(vertice1)<<std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Indices),  &(m_Indices[0]), GL_STATIC_DRAW);

    //���ö�������ָ��
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
