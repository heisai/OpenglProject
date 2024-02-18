#pragma once
#include"../ImGui/imgui.h"
#include"../ImGui/imgui_impl_glfw.h"
#include"../ImGui/imgui_impl_opengl3.h"
#include"../Shader.h"

class ImguiWidget
{
public:
	ImguiWidget( std::shared_ptr<Shader>shader_ptr);
	~ImguiWidget() = default;
	virtual void DrawImgui() = 0;
	virtual void SetUniform() = 0;
protected:
	std::shared_ptr<Shader>m_Shader;

};