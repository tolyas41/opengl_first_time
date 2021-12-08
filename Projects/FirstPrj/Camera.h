#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>



class Camera
{
private:
    Camera() {}
public:

	static float fov;

	static glm::vec3 cameraPos;
	static glm::vec3 cameraFront;
	static glm::vec3 cameraUp;

	static glm::mat4 getLookAt();
	static void cameraMovement(float deltaTime, GLFWwindow* window);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	static bool firstMouse;

	static float lastX, lastY;
	static float sensitivity;
	static float yaw;
	static float pitch;
	static float cameraMoveVal;


};

