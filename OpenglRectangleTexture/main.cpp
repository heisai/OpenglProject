
#include<iostream>
#include"src/Widget.h"
#include"src/Graphics/RectTexture.h"
#include<filesystem>
int main()
{




    Widget w;
    std::shared_ptr<Shader>m_Shader = std::make_shared<Shader>("123.txt","456.txt");
    std::shared_ptr<GraphicsEngine>m_RectData = std::make_shared<RectTextureEngine>();
    w.SetShader(m_Shader);
    w.SetGraphics(m_RectData);
    w.SetBackGround(0.2f, 0.3f, 0.3f);
    w.Show();
}
