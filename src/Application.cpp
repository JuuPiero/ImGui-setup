#define STB_IMAGE_IMPLEMENTATION
#define GLAD_GL_IMPLEMENTATION
#include "Application.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImGuiLayer.h"
Application::Application(ApplicationProperties props): m_Props(props) {
    m_ImGuiLayer = new ImGuiLayer(&m_Props);
    Initialize();
}
Application::~Application() {
    Shutdown();
}

void Application::Initialize() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(m_Props.Width, m_Props.Height, m_Props.Title, NULL, NULL);
    if (m_Window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return;
    }
    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1); // Enable vsync
    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    glfwSetWindowUserPointer(m_Window, this);

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
        Application* app = (Application*)glfwGetWindowUserPointer(window);
        app->m_Props.Width = width;
        app->m_Props.Height = height;
    });

    m_ImGuiLayer->Initialize();

    // Thiết lập backends
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 410");

}
void Application::Shutdown() {
    delete m_ImGuiLayer;
    glfwDestroyWindow(m_Window);
    glfwTerminate();
    std::cout << "Quitting the application" << std::endl;
}

void Application::Run() {
    while(!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        m_ImGuiLayer->BeginFrame();
        Render();
        RenderUI();
        
        m_ImGuiLayer->EndFrame();
        // glfwGetFramebufferSize(m_Window, &m_Props.Width, &m_Props.Height);
        glfwSwapBuffers(m_Window);
    }
}

void Application::Render() {

}

void Application::RenderUI() {
    ImGui::ShowDemoWindow();
}