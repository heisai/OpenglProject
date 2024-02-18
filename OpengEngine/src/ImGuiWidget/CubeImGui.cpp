#include"CubeImGui.h"

CubeImGui::CubeImGui(std::shared_ptr<Shader>shader_ptr):
	ImguiWidget(shader_ptr)
{

}

void CubeImGui::DrawImgui()
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
		ImGui::Checkbox("X", &X);
		ImGui::Checkbox("Y", &Y);
		ImGui::Checkbox("Z", &Z);
		ImGui::ShowDemoWindow();
		

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				//ShowExampleMenuFile();
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
				if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
				ImGui::Separator();
				if (ImGui::MenuItem("Cut", "CTRL+X")) {}
				if (ImGui::MenuItem("Copy", "CTRL+C")) {}
				if (ImGui::MenuItem("Paste", "CTRL+V")) {}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		ImGui::End();
	}	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CubeImGui::SetUniform()
{

	m_Shader->setVec3("vec3color", color[0], color[1], color[2]);


	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 mvpmat4 = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.0f));
	if (X)
	{
		model = glm::scale(model, glm::vec3(sacl_int, 1, 1));
	}
	if (Y)
	{
		model = glm::scale(model, glm::vec3(1, sacl_int, 1));
	}
	if (Z)
	{
		model = glm::scale(model, glm::vec3(1, 1, sacl_int));
	}

	
	
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	view = glm::translate(view, glm::vec3(move_int, 0.0, 0.0));

	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

	mvpmat4 = projection * view * model;
	m_Shader->setMat4("mvpmat4", mvpmat4);
}
