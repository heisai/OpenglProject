#include"Shader.h"

Shader::Shader(const std::string &vs_filename, const std::string &fs_filename, std::string dirname)
{
    std::string vs_sourcecode = Utils::ReadFile(Utils::GlslAbsolute(vs_filename, dirname));
    std::string fs_sourcecode = Utils::ReadFile(Utils::GlslAbsolute(fs_filename, dirname));
    vShaderCode = vs_sourcecode.c_str();
    gShaderCode = fs_sourcecode.c_str();
    std::cout<<vs_sourcecode<<std::endl;
    std::cout<<fs_sourcecode<<std::endl;
    this->CreatShader();
    this->BindShader(); 
}

void Shader::CreatProgram()
{
    this->CreatShader();
    this->BindShader();
}

void Shader::CreatShader()
{
    VertecShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertecShader,1,&vShaderCode,NULL);
     glCompileShader(VertecShader);
    FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader,1,&gShaderCode,NULL);

    glCompileShader(FragmentShader);

}
void Shader::BindShader()
{
    ShaderPromger = glCreateProgram();
    glAttachShader(ShaderPromger,VertecShader);
    glAttachShader(ShaderPromger,FragmentShader);
    glLinkProgram(ShaderPromger);
}


