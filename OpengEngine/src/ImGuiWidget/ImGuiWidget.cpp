#include"ImGuiWidget.h"

ImguiWidget::ImguiWidget( std::shared_ptr<Shader> shader_ptr):
	m_Shader(shader_ptr)
{
	
}

void ImguiWidget::DrawImgui()
{
	
}

void ImguiWidget::SetUniform()
{
	
}

std::map<std::string, glm::mat4> ImguiWidget::GetMate4()
{
	std::map<std::string, glm::mat4>map_data;
	return map_data;
}
