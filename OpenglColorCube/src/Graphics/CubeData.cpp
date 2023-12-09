#include"CubeData.h"
CubeDataEngine::CubeDataEngine(std::shared_ptr<Shader> shader):
    m_shader(shader)
{
    
}
void CubeDataEngine::Draw()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 mvpmat4 = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

	mvpmat4 = projection * view * model;
	m_shader->setMat4("mvpmat4", mvpmat4);

	//设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	
}

void CubeDataEngine::InitBufferData()
{
	// 顶点数组对象
	glGenVertexArrays(1, &m_VAO);
	//顶点缓冲对象
	glGenBuffers(1, &m_VBO);
	//绑定VAO
	glBindVertexArray(m_VAO);
	//把顶点数组复制到缓冲中供OpenGL使用
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_Vertice.size() * sizeof(float), &(m_Vertice[0]), GL_STATIC_DRAW);
	
}

