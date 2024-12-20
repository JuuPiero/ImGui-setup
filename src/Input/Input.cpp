#include "Utils.h"
#include "Input/Input.h"
std::unordered_map<unsigned int, bool> Input::keys;
std::unordered_map<unsigned int, bool> Input::buttons;
glm::vec2 Input::cursorPosition(0, 0);
glm::vec2 Input::lastCursorPosition(0, 0);
// glm::vec2 Input::delta(0, 0);

void Input::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
    // lastX = xpos;
    // lastY = ypos;
    lastCursorPosition.x = xpos;
    lastCursorPosition.y = ypos;

    // deltaX = xpos - lastX;
    // deltaY = ypos - lastY;

    // Cập nhật vị trí chuột hiện tại
    cursorPosition = glm::vec2(xpos, ypos);
    // lastX = xpos;
    // lastY = ypos;
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if(action == GLFW_PRESS) {
        buttons[button] = true;
    }
    else if(action == GLFW_RELEASE) {
        buttons[button] = false;
    }
}

void Input::KeyListenerCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS) {
        keys[key] = true;
    }
    else if(action == GLFW_RELEASE) {
        keys[key] = false;
    }
}
