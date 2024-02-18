
#include<iostream>
#include"src/Widget.h"
#include"src/Utils/OpengHearder.h"
#include<filesystem>
int main()
{


#if 0
	Widget w;
	std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.txt", "456.txt", "Rectangle");
	std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<RectangleEngine>(m_Shader);
	w.SetShader(m_Shader);
	w.SetGraphics(m_RectData);
	w.SetBackGround(0.2f, 0.3f, 0.3f);
	w.Show();
#endif 	

#if 0
	Widget w;
	std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.txt", "456.txt", "Rectangle");
	std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<RectTextureEngine>();
	w.SetShader(m_Shader);
	w.SetGraphics(m_RectData);
	w.SetBackGround(0.2f, 0.3f, 0.3f);
	w.Show();
#endif 

#if 0
	Widget w;
	std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.txt", "456.txt", "Cube");
	std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<CubeDataEngine>(m_Shader);
	w.SetShader(m_Shader);
	w.SetGraphics(m_RectData);
	w.SetBackGround(0.2f, 0.3f, 0.3f);
	w.Show();
#endif 
#if 0
    Widget w;
    std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.txt","456.txt","CubeColor");
    std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<ColorCubeEngine>(m_Shader);
    w.SetShader(m_Shader);
    w.SetGraphics(m_RectData);
    w.SetBackGround(0.2f, 0.3f, 0.3f);
    w.Show();
#endif 

#if 0
	Widget w;
	std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.txt", "456.txt", "CubeColor");
	std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<MouControlEngine>(m_Shader);
	w.SetShader(m_Shader);
	w.SetGraphics(m_RectData);
	w.SetBackGround(0.2f, 0.3f, 0.3f);
	w.Show();
#endif 

	Widget w;
	std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.vert", "456.frag", "PhongModel");
	std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<PhongModelEngine>(m_Shader);
	w.SetShader(m_Shader);
	w.SetGraphics(m_RectData);
	w.SetBackGround(0.2f, 0.3f, 0.3f);
	w.Show();
}
