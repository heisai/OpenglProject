#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<iostream>
using namespace std;

class Camera
{
public:
	static Camera& GetInstall();
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;

	glm::mat4 GetViewMatrix();
	void MouseMovement(float xoffset, float yoffset);
	void MouseScrollEvent(float yoffset);
	float GetZoom()const;
	

private:
	Camera();
private:
	glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	float m_Sensitivity = 0.05;
	glm::vec3  m_DirectionVec3 = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3  m_RightVec3;
	glm::vec3  m_UpVec3;
	glm::vec3  m_WorldUpVec3 = glm::vec3(0.0f, 1.0f, 0.0f);


	float yaw = -90.0f;
	float pitch = 0.0f;
	float sensitivity = 0.02f;
	float Zoom = 45.0f;
};
