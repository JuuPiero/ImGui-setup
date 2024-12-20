#pragma once
// #include "Utils.h"
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <glm/glm.hpp>

class Input {
   
public:
    static void KeyListenerCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
    inline static bool GetKey(int key) { return keys[key]; }
    inline static bool GetKeyUp(int key) { return keys[key] == false; }
    inline static bool GetKeyDown(int key) { return keys[key] == true; }
    inline static glm::vec2 GetCursorPosition() { return cursorPosition; }

private:
    static std::unordered_map<unsigned int, bool> keys;
    static std::unordered_map<unsigned int, bool> buttons;
    static glm::vec2 cursorPosition;
    static glm::vec2 lastCursorPosition;
    // static glm::vec2 delta;
};
