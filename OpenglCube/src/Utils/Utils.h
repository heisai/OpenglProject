#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<filesystem>
namespace fs = std::filesystem;
namespace  Utils {

    //读取文件内容
    std::string ReadFile(const std::string &file_name);
    // 生成着色其内容
    void CreatShaderProgram(const std::string &vs, const std::string &fs);

    std::string GlslAbsolute(const std::string& filename);

}
#endif // UTILS_H
