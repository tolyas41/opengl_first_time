#include "Camera.h"
#include <functional>

//void Camera::mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void Camera::scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void Camera::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 60.0f)
        fov = 60.0f;
}

Camera::Camera(GLFWwindow* currentWindow)
    : window { currentWindow }
{
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y)
    {
        if (Camera* somecamera = static_cast<Camera*>(glfwGetWindowUserPointer(window)))
            somecamera->mouse_callback(window, x, y);
    });
    glfwSetScrollCallback(window, [](GLFWwindow* window, double x, double y)
    {
        if (Camera* somecamera = static_cast<Camera*>(glfwGetWindowUserPointer(window)))
            somecamera->scroll_callback(window, x, y);
    });

}

void Camera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    lastX = xpos;
    lastY = ypos;

    yaw += (xpos - lastX) * sensitivity;
    pitch += (lastY - ypos) * sensitivity;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);

}


void Camera::cameraMovement(float deltaTime)
{
    const float cameraSpeed = cameraMoveVal * deltaTime; 
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

glm::mat4 Camera::getLookAt()
{
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}