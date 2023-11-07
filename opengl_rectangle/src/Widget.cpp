#include"Widget.h"

Widget::Widget(std::string title, int width, int height):
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

void Widget::SetGraphics( const std::shared_ptr<RectData> &graphics_value)
{
     m_RectData = graphics_value;
}

void Widget::Show()
{
	//�ж�GLFW �Ƿ��˳�
	while (!glfwWindowShouldClose(window))
	{
        ProcessInput();
        //������ɫ(״̬)
        glClearColor(m_red, m_green, m_blue, 1.0f);
        //������ɫ(����)
        glClear(GL_COLOR_BUFFER_BIT);

        this->DrawGraphics();

		//������ɫ����, ������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ��
		glfwSwapBuffers(window);
		//�����¼�����
		glfwPollEvents();
	}
}

void Widget::SetWindowTitle(const std::string& title)
{
	title_text = title;
}
void Widget::InitWidget()
{

//      ��ʼ��glfw
		glfwInit();
//		�������汾
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		���ô˰汾
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		���������ļ�
//		 GLFW_OPENGL_CORE_PROFILE ����ģʽ
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // ���ɴ��ڶ���
        window = glfwCreateWindow(m_witdh, m_height, title_text.c_str(), NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        //���������������̵߳�������
        glfwMakeContextCurrent(window);
        //���ƴ��ڴ�С Qt
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
void Widget::DrawGraphics()
{
    if(m_Shader == nullptr || m_RectData == nullptr)
    {
        return;
    }
    glUseProgram(m_Shader->ShaderPromger);
    m_RectData->Draw();
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
