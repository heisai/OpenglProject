﻿#include"Utils.h"

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

std::string Utils::GlslAbsolute(const std::string& filename, const std::string& dirname)
{
    std::string current_dir = fs::current_path().string();
    const size_t last_slash_idx = current_dir.rfind('\\');
    if (std::string::npos != last_slash_idx)
    {
        current_dir = current_dir.substr(0, last_slash_idx);
    }
    current_dir.append("\\glsl").append("\\").append(dirname).append("\\").append(filename);
    std::cout << "File_Path:" << current_dir << std::endl;
    return current_dir;
}



Utils::MaterialAttrib::MaterialAttrib(const std::string& attrib):
    m_MaterialName(attrib)
{
    //翠
    Material emerald;
    emerald.m_Ambient = glm::vec3(0.0215, 0.1745, 0.0215);
    emerald.m_Diffsue = glm::vec3(0.07568, 0.61424, 0.07568);
    emerald.m_Specular = glm::vec3(0.633, 0.727811, 0.633);
    emerald.m_Shininess = 76.8;
   

    //玉
    Material jade;
    jade.m_Ambient = glm::vec3(0.135,0.2225,0.1575);
    jade.m_Diffsue = glm::vec3(0.54,0.89,0.63);
    jade.m_Specular = glm::vec3(0.316228,0.316228,0.316228);
    jade.m_Shininess = 12.8;
   

    //黑曜石
    Material obsidian;
    obsidian.m_Ambient = glm::vec3(0.05375,0.05,0.06625);
    obsidian.m_Diffsue = glm::vec3(0.18275,0.17,0.22525);
    obsidian.m_Specular = glm::vec3(0.332741,0.328634,0.346435);
    obsidian.m_Shininess = 38.4;
  

    //珍珠
    Material pearl;
    pearl.m_Ambient = glm::vec3(0.25,0.20725,0.20725);
    pearl.m_Diffsue = glm::vec3(1,0.829,0.829);
    pearl.m_Specular = glm::vec3(0.296648,0.296648,0.296648);
    pearl.m_Shininess = 11.264;
  

    //红宝石
    Material ruby;
    ruby.m_Ambient = glm::vec3(0.1745,0.01175,0.01175);
    ruby.m_Diffsue = glm::vec3(0.61424,0.04136,0.04136);
    ruby.m_Specular = glm::vec3(0.727811,0.626959,0.626959);
    ruby.m_Shininess = 76.8;
    

    //绿松石
    Material turquoise;
    turquoise.m_Ambient = glm::vec3(0.1,0.18725,0.1745);
    turquoise.m_Diffsue = glm::vec3(0.396,0.74151,0.69102);
    turquoise.m_Specular = glm::vec3(0.297254,0.30829,0.306678);
    turquoise.m_Shininess = 12.8;
  

    //黄铜
    Material brass;
    brass.m_Ambient = glm::vec3(0.329412,0.223529,0.027451);
    brass.m_Diffsue = glm::vec3(0.780392,0.568627,0.113725);
    brass.m_Specular = glm::vec3(0.992157,0.941176,0.807843);
    brass.m_Shininess = 27.8974;
    

    //青铜
    Material bronze;
    brass.m_Ambient = glm::vec3(0.2125,0.1275,0.054);
    brass.m_Diffsue = glm::vec3(0.714,0.4284,0.18144);
    brass.m_Specular = glm::vec3(0.393548,0.271906,0.166721);
    brass.m_Shininess = 25.6;
   

    //铬合金
    Material chrome;
    chrome.m_Ambient = glm::vec3(0.25,0.25,0.25);
    chrome.m_Diffsue = glm::vec3(0.4,0.4,0.4);
    chrome.m_Specular = glm::vec3(0.774597,0.774597,0.774597);
    chrome.m_Shininess = 76.8;
   

    //铜
    Material copper;
    copper.m_Ambient = glm::vec3(0.19125,0.0735,0.0225);
    copper.m_Diffsue = glm::vec3(0.7038,0.27048,0.0828);
    copper.m_Specular = glm::vec3(0.256777,0.137622,0.086014);
    copper.m_Shininess = 12.8;
   

    //金子
    Material gold;
    gold.m_Ambient = glm::vec3(0.24725,0.1995,0.0745);
    gold.m_Diffsue = glm::vec3(0.75164,0.60648,0.22648);
    gold.m_Specular = glm::vec3(0.628281,0.555802,0.366065);
    gold.m_Shininess = 51.2;
   

    //银
    Material silver;
    silver.m_Ambient = glm::vec3(0.19225,0.19225,0.19225);
    silver.m_Diffsue = glm::vec3(0.50754,0.50754,0.50754);
    silver.m_Specular = glm::vec3(0.508273,0.508273,0.508273);
    silver.m_Shininess = 51.2;
   

    //黑色塑料
 /*   Material black_plastic;
 
    //青色塑料
    Material cyan_plastic;
    //绿色塑料
    Material green_plastic;
    //红色塑料
	Material red_plastic;
    //白色塑料
	Material white_plastic;
    //黄色塑料
	Material yellow_plastic;
    //黑色橡胶
	Material black_rubber;
    //青色橡胶
	Material cyan_rubber;
    //绿色橡胶
	Material green_rubber;
    //红色橡胶
	Material red_rubber;
    //白色橡胶
	Material white_rubber;
   // 黄色橡胶
	Material yellow_rubber;*/


    m_MapMaterial.insert(std::make_pair("emerald", emerald));
    m_MapMaterial.insert(std::make_pair("jade", jade));
    m_MapMaterial.insert(std::make_pair("obsidian", obsidian));
    m_MapMaterial.insert(std::make_pair("pearl", pearl));
    m_MapMaterial.insert(std::make_pair("ruby", ruby));
    m_MapMaterial.insert(std::make_pair("turquoise", turquoise));
    m_MapMaterial.insert(std::make_pair("brass", brass));
    m_MapMaterial.insert(std::make_pair("bronze", bronze));
    m_MapMaterial.insert(std::make_pair("chrome", chrome));
    m_MapMaterial.insert(std::make_pair("copper", copper));
    m_MapMaterial.insert(std::make_pair("gold", gold));
    m_MapMaterial.insert(std::make_pair("silver", silver));

}

void Utils::MaterialAttrib::SetMaterialAttrib(const std::string& attrib)
{
    m_MaterialName = attrib;
}

glm::vec3 Utils::MaterialAttrib::GetAmbient()
{
    return m_MapMaterial[m_MaterialName].m_Ambient;
}

glm::vec3 Utils::MaterialAttrib::GetDiffsue()
{
    return m_MapMaterial[m_MaterialName].m_Diffsue;
}

glm::vec3 Utils::MaterialAttrib::GetSpecular()
{
    return m_MapMaterial[m_MaterialName].m_Specular;
}

float Utils::MaterialAttrib::GetShininess()
{
    return m_MapMaterial[m_MaterialName].m_Shininess;
}
