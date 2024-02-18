

#include"CameraControlEngine.h"

MouControlEngine::MouControlEngine(std::shared_ptr<Shader> shader):
	ColorCubeEngine(shader)
{

}

void MouControlEngine::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 mvpmat4 = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.01, 0.8, 0.8));
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));

	view = Camera::GetInstall().GetViewMatrix();
	projection = glm::perspective(glm::radians(Camera::GetInstall().GetZoom()), (float)800 / (float)600, 0.1f, 100.0f);

	mvpmat4 = projection * view * model;
	m_shader->setMat4("mvpmat4", mvpmat4);

	//设置顶点属性指针
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void MouControlEngine::InitBufferData()
{
	ColorCubeEngine::InitBufferData();
}


