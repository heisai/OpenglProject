// Include GLFW

#include"EventControls.h"

float EventControl::lastX = 400;
float EventControl::lastY = 300;
bool  EventControl::firstMouse = false;
bool  EventControl::pressed = false;

void EventControl::MouseEvent(GLFWwindow* window, double xposIn, double yposIn)
{
	
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	else
	{
		if (!pressed)
		{
			return;
		}
	}
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;

	Camera::GetInstall().MouseMovement(xoffset, yoffset);
}

void EventControl::MouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		pressed = true;
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		pressed = false;
	}
}

void EventControl::MouseScrollEvent(GLFWwindow* window, double xoffset, double yoffset)
{
	Camera::GetInstall().MouseScrollEvent(yoffset);
}

