#ifndef UTILS_H
#define UTILS_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<filesystem>
namespace fs = std::filesystem;
namespace  Utils {

    //��ȡ�ļ�����
    std::string ReadFile(const std::string &file_name);
    // ������ɫ������
    void CreatShaderProgram(const std::string &vs, const std::string &fs);

}
#endif // UTILS_H
