#include"PhongModelEngine.h"
PhongModelEngine::PhongModelEngine(std::shared_ptr<Shader> shader /*= nullptr*/):
	GraphicsEngine(shader)
{
	m_ImguiWidget = std::make_shared<PhongModelImGui>(shader);
}


void PhongModelEngine::Draw()
{
	//glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_ImguiWidget->DrawImgui();
	m_ImguiWidget->SetUniform();

#if 1
	//设置光源属性
	m_shader->setVec3("LightData.positon", 0.0f, 1.0f, 5.0f);
	//m_shader->setVec3("LightData.ambient", 0.2f, 0.2f, 0.2f);
	//m_shader->setVec3("LightData.diffuse", 0.5f, 0.5f, 0.5f);
	//m_shader->setVec3("LightData.specular", 1.0f, 1.0f, 1.0f);


	glm::vec3 lightColor;
	lightColor.x = static_cast<float>(sin(glfwGetTime() * 2.0));
	lightColor.y = static_cast<float>(sin(glfwGetTime() * 0.7));
	lightColor.z = static_cast<float>(sin(glfwGetTime() * 1.3));
	glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // decrease the influence
	glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence
	m_shader->setVec3("LightData.ambient", ambientColor);
	m_shader->setVec3("LightData.diffuse", diffuseColor);
	m_shader->setVec3("LightData.specular", 1.0f, 1.0f, 1.0f);

#else
	//设置光源属性
	m_shader->setVec4("LightData.positon", 0.0f, 1.0f, 5.0f,1.0f);
	m_shader->setVec4("LightData.ambient", 0.2f, 0.2f, 0.2f,1.0f);
	m_shader->setVec4("LightData.diffuse", 0.5f, 0.5f, 0.5f,1.0f);
	m_shader->setVec4("LightData.specular", 1.0f, 1.0f, 1.0f,1.0f);
#endif 

	// 设置 物体属性
	/*m_shader->setVec3("MaterialData.ambient", 1.0f, 0.5f, 0.31f);
	m_shader->setVec3("MaterialData.diffuse", 1.0f, 0.5f, 0.31f);
	m_shader->setVec3("MaterialData.specular", 0.5f, 0.5f, 0.5f);
	m_shader->setFloat("MaterialData.shiniess", 32.0f);*/


	//设置 mvp
	//glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	//glm::mat4 view = glm::mat4(1.0f);
	//glm::mat4 projection = glm::mat4(1.0f);
	//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.0f));
	//model = glm::scale(model, glm::vec3(0.5, 2, 2));
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	//projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

	//m_shader->setMat4("model", model);
	//m_shader->setMat4("view", view);
	//m_shader->setMat4("project", projection);

	//设置顶点属性指针
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void PhongModelEngine::InitBufferData()
{
	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);

	// 顶点数组对象
	glGenVertexArrays(1, &m_VAO);
	//绑定VAO
	glBindVertexArray(m_VAO);

	//把顶点数组复制到缓冲中供OpenGL使用
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_Vertice.size() * sizeof(float), &(m_Vertice[0]), GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}
