#include"Widget.h"

Widget::Widget(const std::string& title, int width, int height):
    title_text(title),
    m_witdh(width),
    m_height(height),
    m_red(0.0),
    m_green(0.0),
    m_blue(0.0),
    m_Shader(nullptr),
    m_RectData(nullptr)
{
    InitWidget();
    InitImGui();
}
void Widget::SetBackGround(GLfloat red,GLfloat green,GLfloat blue)
{
    m_red = red;
    m_green = green;
    m_blue = blue;
}

void Widget::SetShader( const std::shared_ptr<Shader> &shader_value)
{
    m_Shader = shader_value;
}

void Widget::SetGraphics( const std::shared_ptr<GraphicsEngine> &graphics_value)
{
     m_RectData = graphics_value;
}

void Widget::Show()
{
   /* glUseProgram(m_Shader->ShaderPromger);
    glUniform1i(glGetUniformLocation(m_Shader->ShaderPromger, "texture1"), 0);
    glUniform1i(glGetUniformLocation(m_Shader->ShaderPromger, "texture2"), 1);*/

    this->InitBufferData();
   
	//判断GLFW 是否退出
	while (!glfwWindowShouldClose(window))
	{
        ProcessInput();

        

        //设置颜色(状态)
        glClearColor(m_red, m_green, m_blue, 1.0f);
        //设置颜色(动作)
        glClear(GL_COLOR_BUFFER_BIT);
		this->DrawGraphics();

		//交换颜色缓冲, 它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上
		glfwSwapBuffers(window);
		//监听事件输入
		glfwPollEvents();
	}
}

void Widget::SetWindowTitle(const std::string& title)
{
	title_text = title;
}

void Widget::framebuffer_size_callback1(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Widget::InitWidget()
{

//      初始化glfw
		glfwInit();
//		设置主版本
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		设置此版本
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		设置配置文件
//		 GLFW_OPENGL_CORE_PROFILE 核心模式
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // 生成窗口对象
        window = glfwCreateWindow(m_witdh, m_height, title_text.c_str(), NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        //将窗口设置文主线程的上下文
        glfwMakeContextCurrent(window);
        //绘制窗口大小 Qt
        glfwSetFramebufferSizeCallback(window, &Widget::framebuffer_size_callback1);
		glfwSetMouseButtonCallback(window, &EventControl::MouseButtonEvent);
		glfwSetCursorPosCallback(window, &EventControl::MouseEvent);
		glfwSetScrollCallback(window, &EventControl::MouseScrollEvent);

        LoadGlad();
}

int Widget::LoadGlad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
    return 1;
}

void Widget::ProcessInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

}

void Widget::InitBufferData()
{
	if (m_RectData == nullptr)
	{
		return;
	}
	m_RectData->InitBufferData();
}

void Widget::DrawGraphics()
{
    if(m_Shader == nullptr || m_RectData == nullptr)
    {
        return;
    }
    glUseProgram(m_Shader->ShaderPromger);
   /* m_RectData->processMouseInput(window);*/
    m_RectData->Draw();


	

}

void Widget::InitImGui()
{



    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);//GLFWwindow
    ImGui_ImplOpenGL3_Init("#version 330");//自己的版本
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}




