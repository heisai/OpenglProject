#include"LightMapsEngine.h"

LightMapsEngine::LightMapsEngine(std::shared_ptr<Shader> shader):
	GraphicsEngine(shader)
{
    InitTextures(&m_Texture, Utils::GlslAbsolute("container2.png", "LightMap"));
	InitTextures(&m_Texture1, Utils::GlslAbsolute("container2_specular.png", "LightMap"));

	InitTextures(&m_Texture2, Utils::GlslAbsolute("matrix.jpg", "LightMap"));
	
}

void LightMapsEngine::Draw()
{
	//glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*m_ImguiWidget->DrawImgui();
	m_ImguiWidget->SetUniform();*/


#if 1
	glUseProgram(m_shader->ShaderPromger);
	m_shader->SetInt("MaterialData.diffuse", 0);
	m_shader->SetInt("MaterialData.specular", 1);
	m_shader->SetInt("MaterialData.emission", 2);
	//设置光源属性
	float x = static_cast<float>(sin(glfwGetTime()));
	float y = static_cast<float>(sin(glfwGetTime()));
	float z = static_cast<float>(sin(glfwGetTime()));

	m_shader->setVec3("LightData.positon", x,1.0f,z * 100);
	m_shader->setVec3("LightData.ambient", 0.2f, 0.2f, 0.2f);
	m_shader->setVec3("LightData.diffuse", 0.5f, 0.5f, 0.5f);
	m_shader->setVec3("LightData.specular", 1.0f, 1.0f, 1.0f);


	//glm::vec3 lightColor;
	//lightColor.x = static_cast<float>(sin(glfwGetTime() * 2.0));
	//lightColor.y = static_cast<float>(sin(glfwGetTime() * 0.7));
	//lightColor.z = static_cast<float>(sin(glfwGetTime() * 1.3));
	//glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // decrease the influence
	//glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence
	//m_shader->setVec3("LightData.ambient", ambientColor);
	//m_shader->setVec3("LightData.diffuse", diffuseColor);
	//m_shader->setVec3("LightData.specular", 1.0f, 1.0f, 1.0f);

#else
	//设置光源属性
	m_shader->setVec4("LightData.positon", 0.0f, 1.0f, 5.0f, 1.0f);
	m_shader->setVec4("LightData.ambient", 0.2f, 0.2f, 0.2f, 1.0f);
	m_shader->setVec4("LightData.diffuse", 0.5f, 0.5f, 0.5f, 1.0f);
	m_shader->setVec4("LightData.specular", 1.0f, 1.0f, 1.0f, 1.0f);
#endif 

	// 设置 物体属性
	//m_shader->setVec3("MaterialData.ambient", 1.0f, 0.5f, 0.31f);
	
	//m_shader->setVec3("MaterialData.diffuse", 1.0f, 0.5f, 0.31f);
	//m_shader->setVec3("MaterialData.specular", 0.5f, 0.5f, 0.5f);
	m_shader->setFloat("MaterialData.shiniess", 64.0f);
	glm::vec3 cubePositions[] = {
		   glm::vec3(0.0f,  0.0f,  -3.0f),
		   glm::vec3(2.0f,  2.0f, -10.0f),
		   glm::vec3(-1.5f, -2.2f, -13.5f),
		   glm::vec3(-3.8f, -2.0f, -11.3f),
		   glm::vec3(2.4f, -0.4f, -10.5f),
		   glm::vec3(-1.7f,  3.0f, -9.5f),
		   glm::vec3(1.3f, -2.0f, -6.5f),
		   glm::vec3(-1.5f,  2.0f, -8.5f),
		   glm::vec3(1.5f,  0.2f, -5.5f),
		   glm::vec3(-1.3f,  1.0f, -8.5f)
	};
	for (unsigned int i = 0; i < 10; i++)
	{
		//设置 mvp
		glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		model = glm::rotate(model, (float)glfwGetTime()+ (i+1), glm::vec3(2.0f, 3.3f, -2.0f));
		model = glm::scale(model, glm::vec3(0.6));
		projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

		m_shader->setMat4("model", model);
		m_shader->setMat4("view", view);
		m_shader->setMat4("project", projection);
		m_shader->setFloat("UTime", (float)glfwGetTime());

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Texture);
		// bind specular map
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, m_Texture1);

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, m_Texture2);

		//设置顶点属性指针
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}







	
}

void LightMapsEngine::InitBufferData()
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
}

void LightMapsEngine::InitTextures(unsigned int* texture, const std::string& path, bool alpha)
{
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;

    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
		GLenum format;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;

	
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);



    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
		stbi_image_free(data);
    }
    
}
