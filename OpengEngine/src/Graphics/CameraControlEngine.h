#pragma once
#include"ColorCubeEngine.h"
#include"../Camera.h"
class MouControlEngine : public ColorCubeEngine
{
public:
	explicit MouControlEngine(std::shared_ptr<Shader> shader);
	void Draw() override;
	void InitBufferData() override;	
};