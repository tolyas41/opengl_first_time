#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera.h"

class Window
{
public:
	Window();

	//void WindowSetter();

	GLFWwindow* window;
	float WindowWidth = 1920.0f;
	float WindowHeight = 1080.0f;
	const char* WindowName = "LearnOpenGL";
};

