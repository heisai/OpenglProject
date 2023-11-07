#include"Shader.h"

Shader::Shader(const std::string &vs_filename, const std::string &fs_filename)
{
    std::string vs_sourcecode = Utils::ReadFile(GlslAbsolute(vs_filename));
    std::string fs_sourcecode = Utils::ReadFile(GlslAbsolute(fs_filename));
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

std::string Shader::GlslAbsolute(const std::string &filename)
{
    std::string current_dir = fs::current_path().string();
    const size_t last_slash_idx = current_dir.rfind('\\');
    if (std::string::npos != last_slash_idx)
    {
        current_dir = current_dir.substr(0, last_slash_idx);
    }
    current_dir.append("\\glsl").append("\\").append(filename);
    std::cout<<"File_Path:"<<current_dir<<std::endl;
    return current_dir;
}
