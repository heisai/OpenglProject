#pragma once
#include"ImguiWidget.h"
#include"../Utils/Utils.h"
using namespace Utils;
class PhongModelImGui : public ImguiWidget
{
public:
	PhongModelImGui(std::shared_ptr<Shader>shader_ptr = nullptr);
	PhongModelImGui() = delete;
protected:
	void DrawImgui() override;
	void SetUniform() override;

	float color[4] = { 1.0f,1.0f,1.0f,1.0f };
	float sacl_int = 1.0;
	float move_int = 0.0;
	bool X;
	bool Y;
	bool Z;

	const char* m_ComboxItems[12] = { "emerald", "jade",
	"obsidian", "pearl",
	"ruby", "turquoise",
	"brass", "bronze",
	"chrome", "copper",
	"gold","silver" };

	int item_current = 0;

	std::shared_ptr<MaterialAttrib>m_MaterialAttrib;

};