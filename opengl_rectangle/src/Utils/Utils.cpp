#include"Utils.h"

std::string Utils::ReadFile(const std::string &file_name)
{
    std::ifstream  file;
    std::stringstream filestream;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        file.open(file_name);
        filestream << file.rdbuf();
        file.close();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
    }
    return filestream.str();
}

void Utils::CreatShaderProgram(const std::string &vs, const std::string &fs)
{
    std::string vs_text = ReadFile(vs);
    std::string fs_text = ReadFile(fs);
}
