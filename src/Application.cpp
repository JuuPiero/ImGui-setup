#define STB_IMAGE_IMPLEMENTATION
#define GLAD_GL_IMPLEMENTATION
#include "Application.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImGuiLayer.h"
Application::Application(ApplicationProperties props): m_Props(props) {
    m_ImGuiLayer = new ImGuiLayer();
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
    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
        
    });

    // Thiết lập ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Thiết lập style của ImGui
    ImGui::StyleColorsDark();

    // Thiết lập backends
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    m_ImGuiLayer->Initialize();

}
void Application::Shutdown() {
    delete m_ImGuiLayer;
    glfwDestroyWindow(m_Window);
    glfwTerminate();
    std::cout << "Quitting the application" << std::endl;
}

void Application::Run() {
    while(!glfwWindowShouldClose(m_Window)) {
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        Render();
        m_ImGuiLayer->BeginFrame();

        RenderUI();
        
        m_ImGuiLayer->EndFrame();
        glfwGetFramebufferSize(m_Window, &m_Props.Width, &m_Props.Height);
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
}

void Application::Render() {

}

void Application::RenderUI() {

}