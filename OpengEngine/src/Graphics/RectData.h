#ifndef RECTDATA_H
#define RECTDATA_H
#include"./Graphics.h"
#include"../ImGuiWidget/RectangleImGui.h"
class RectangleEngine : public GraphicsEngine
{
public:
    RectangleEngine(std::shared_ptr<Shader> shader = nullptr);
    void Draw() override;
    void InitBufferData() override;

private:
    std::vector<float>m_Vertice = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
           -0.5f, -0.5f, 0.0f,  // bottom left
           -0.5f,  0.5f, 0.0f   // top left
       };

      std::vector<int>m_Indices = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
      std::shared_ptr<ImguiWidget>m_ImguiWidget;
};
#endif // RECTDATA_H
