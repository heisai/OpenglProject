#ifndef EVENTCONTRAL_H
#define EVENTCONTRAL_H

#include <GLFW/glfw3.h>
#include"../Camera.h"
class EventControl
{
public:
	static void MouseEvent(GLFWwindow* window, double xposIn, double yposIn);
	static void MouseButtonEvent(GLFWwindow* window, int button, int action, int mods);

	static void MouseScrollEvent(GLFWwindow* window, double xoffset, double yoffset);
		
	static float lastX;
	static float lastY;
	static bool firstMouse;
	static bool pressed;
};


#endif