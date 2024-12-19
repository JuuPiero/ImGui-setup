#include "Sanbox.h"
#include "ImGuiLayer.h"
#include "Utils.h"
#include "Entry.h"
#include "Renderer/Renderer.h"

Application* CreateApplication() {
    auto props = ApplicationProperties();
    props.Width = 1080;
    props.Height = 800;
    props.Title = "Sanbox";

    return new Sanbox(props);
}
Shared<Application> CreateApp() {
    auto props = ApplicationProperties();
    props.Width = 1080;
    props.Height = 800;
    props.Title = "Sanbox";

    return std::make_shared<Sanbox>(props);
}


Shared<VertexBuffer> VBO;
Shared<VertexArrayObject> vertexArray;
Shared<Shader> shader;

Sanbox::Sanbox(ApplicationProperties props): Application(props) {
    PrintLn("Creating Sanbox");
    
    float vertices[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };
    vertexArray = VertexArrayObject::Create();
    VBO = VertexBuffer::Create(vertices, sizeof(vertices));
    shader = Shader::Create("../res/default.vert", "../res/default.frag");
    VertexBufferLayout layout;
    layout.Push<float>(3, false);
    vertexArray->AddBuffer(*VBO, layout);
}

void Sanbox::Render() {
    shader->Use();    
    vertexArray->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}


void Sanbox::RenderUI() {
    // ImGui::DockSpaceOverViewport(0U, ImGui::GetMainViewport());
    // Application::RenderUI();
    
    // ImGui::Begin("Docking Demo");
    // ImGui::Text("Hello, Docking!");
    // ImGui::End();
    // Tạo cửa sổ Dockspace
    // static float test[2];
    // ImGui::Begin("Drag");
    //     ImGui::DragFloat2("Test", test);
    // ImGui::End();
    // ImGui::Begin("Work space", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    // ImGui::SetWindowSize(ImVec2(m_Props.Width * 0.2f, m_Props.Height));
    // ImGui::SetWindowPos(ImVec2(0, 0));
    //     ImGui::TextWrapped("main.cpp");

    // ImGui::End();
}
