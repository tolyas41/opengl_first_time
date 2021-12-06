#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>



class Camera
{
public:

	Camera(GLFWwindow* currentWindow);

	float fov = 60.0f;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 getLookAt();
	void cameraMovement(float deltaTime);

private:
	GLFWwindow* window;
	float lastX = 400, lastY = 300;
	bool firstMouse = true;
	const float sensitivity = 0.1f;
	float yaw = -90.0f;
	float pitch = 0.0f;
	const float cameraMoveVal = 3.0f;

	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

};

