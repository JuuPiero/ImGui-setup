#include "Editor.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImGuiLayer.h"
#include <iostream>


Editor::Editor(ApplicationProperties props): Application(props) {
    std::cout << "Creating" << std::endl;
}
Editor::~Editor() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Editor::Run() {
    while(!glfwWindowShouldClose(m_Window)) {
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        m_ImGuiLayer->BeginFrame();

        Render();
        
        m_ImGuiLayer->EndFrame();
        glfwGetFramebufferSize(m_Window, &m_Props.Width, &m_Props.Height);
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
}
void Editor::Shutdown() {
    delete m_ImGuiLayer;
    std::cout << "Quitting the editor" << std::endl;
}


