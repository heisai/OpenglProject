#include"RectData.h"
RectangleEngine::RectangleEngine():GraphicsEngine()
{
   

}


void RectangleEngine::Draw()
{
    glBufferData(GL_ARRAY_BUFFER, m_Vertice.size() * sizeof(float), &(m_Vertice[0]), GL_STATIC_DRAW);
//    std::cout<<sizeof(vertice)<<"||" << vertice.size() * sizeof(float)<<"||"<< vertice.size()<< "||" << sizeof(vertice1)<<std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_Indices),  &(m_Indices[0]), GL_STATIC_DRAW);

    //设置顶点属性指针
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RectangleEngine::InitBufferData()
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

}
