#pragma once
#include"ImguiWidget.h"
class CubeImGui : public ImguiWidget
{
public:
	CubeImGui(std::shared_ptr<Shader>shader_ptr = nullptr);
	CubeImGui() = delete;
protected:
	void DrawImgui() override;
	void SetUniform() override;

	float color[4] = { 1.0f,1.0f,1.0f,1.0f };
	float sacl_int = 1.0;
	float move_int = 0.0;
	bool X;
	bool Y;
	bool Z;
	
};