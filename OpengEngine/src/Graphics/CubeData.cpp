#include"CubeData.h"
CubeDataEngine::CubeDataEngine(std::shared_ptr<Shader> shader):
	GraphicsEngine(shader)
{
	m_ImguiWidget = std::make_shared<CubeImGui>(shader);
}
void CubeDataEngine::Draw()
{

	

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//设置顶点属性指针
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);


	if (m_ImguiWidget)
	{
		m_ImguiWidget->DrawImgui();
		m_ImguiWidget->SetUniform();
	}

	
	
}

void CubeDataEngine::InitBufferData()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	// 顶点数组对象
	glGenVertexArrays(1, &m_VAO);
	//顶点缓冲对象
	glGenBuffers(1, &m_VBO);
	//绑定VAO
	glBindVertexArray(m_VAO);
	//把顶点数组复制到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_Vertice.size() * sizeof(float), &(m_Vertice[0]), GL_STATIC_DRAW);

	//设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	
}

