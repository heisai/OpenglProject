#include"Camera.h"

Camera& Camera::GetInstall()
{
	static Camera instance;
	return instance;
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(m_Position, m_Position + m_DirectionVec3, m_UpVec3);
}

void Camera::MouseMovement(float xoffset, float yoffset)
{
	yaw += sensitivity * xoffset;
	pitch += sensitivity * yoffset;
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	std::cout << yaw <<"\t:" << pitch <<"\t:" << xoffset<<"\t:" << yoffset << std::endl;
	//方向向量
	glm::vec3 direction(
		cos(glm::radians(pitch)) * cos(glm::radians(yaw)),
		sin(glm::radians(pitch)),
		cos(glm::radians(pitch)) * sin(glm::radians(yaw))
	);

	m_DirectionVec3 = glm::normalize(direction);
	// 向右向量

	m_RightVec3 = glm::normalize(glm::cross(m_WorldUpVec3, m_DirectionVec3));
	//向上向量
	m_UpVec3 = glm::normalize(glm::cross(m_DirectionVec3, m_RightVec3));
}

void Camera::MouseScrollEvent(float yoffset)
{
	Zoom -= (float)yoffset;
	if (Zoom < 1.0f)
		Zoom = 1.0f;
	if (Zoom > 45.0f)
		Zoom = 45.0f;

}

float Camera::GetZoom() const
{
	return Zoom;
}

Camera::Camera()
{

}
