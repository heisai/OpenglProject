#ifndef SHADER_H
#define SHADER_H
#include"./Utils/Utils.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Shader{
public:
    explicit Shader(const std::string& vs_filename,const std::string &fs_filename);
    unsigned int ShaderPromger;

protected:
    void CreatProgram();
    void CreatShader();
    void BindShader();
private:
    std::string GlslAbsolute(const std::string& filename);
private:
    const char* vShaderCode;
    const char* gShaderCode;
    unsigned int VertecShader;
    unsigned int FragmentShader;

};
#endif // SHADER_H
