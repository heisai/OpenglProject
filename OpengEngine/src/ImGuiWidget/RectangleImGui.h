#pragma once
#include"ImguiWidget.h"
class RectangleImGui : public ImguiWidget
{
public:
	RectangleImGui(std::shared_ptr<Shader>shader_ptr = nullptr);
	RectangleImGui() = delete;
protected:
	void DrawImgui() override;
	void SetUniform() override;
	std::map<std::string, glm::mat4>GetMate4() override;

	float color[4] = { 1.0f,1.0f,1.0f,1.0f };
	float sacl_int = 1.0;
	float move_int = 0.0;

	glm::mat4 transform = glm::mat4(1.0f);
};