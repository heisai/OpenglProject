#include"RectangleImGui.h"

RectangleImGui::RectangleImGui(std::shared_ptr<Shader>shader_ptr):
	ImguiWidget(shader_ptr)
{

}

void RectangleImGui::DrawImgui()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	{
		ImGui::Begin("Panel");
		ImGui::Button("Hello!");
		ImGui::ColorEdit3("color", color);
		ImGui::SliderFloat("Scale", &sacl_int, 0.1, 1.0);
		ImGui::SliderFloat("Move", &move_int, -1.0, 1.0);
		ImGui::End();
	}
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void RectangleImGui::SetUniform()
{
	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(sacl_int, sacl_int, sacl_int));
	transform = glm::translate(transform, glm::vec3(move_int, 0.0, 0.0));
	m_Shader->setVec3("vec3color", color[0], color[1], color[2]);
	m_Shader->setMat4("transform", transform);
}

std::map<std::string, glm::mat4> RectangleImGui::GetMate4()
{
	std::map<std::string, glm::mat4>map_data;
	map_data.insert(std::make_pair("model", transform));
	return map_data;
}

