#include "Sanbox.h"
#include "ImGuiLayer.h"
#include "Utils.h"
#include "Entry.h"


Application* CreateApplication() {
    auto props = ApplicationProperties();
    props.Width = 1080;
    props.Height = 800;
    props.Title = "Text Editor";

    return new Sanbox(props);
}
Shared<Application> CreateApp() {
    auto props = ApplicationProperties();
    props.Width = 1080;
    props.Height = 800;
    props.Title = "Text Editor";

    return std::make_shared<Sanbox>(props);
}


Sanbox::Sanbox(ApplicationProperties props): Application(props) {
    PrintLn("Creating Sanbox");
}

void Sanbox::RenderUI() {
    Application::RenderUI();
    // Tạo một cửa sổ ví dụ
    // ImGui::Begin("Hello, ImGui with Docking!");
    //     ImGui::Text("Đây là một cửa sổ ví dụ với tính năng docking.");
    // ImGui::End();
    // static float test[2];
    // ImGui::Begin("Drag");
    //     ImGui::DragFloat2("Test", test);
    // ImGui::End();
    // ImGui::Begin("Work space", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    // ImGui::SetWindowSize(ImVec2(m_Props.Width * 0.2f, m_Props.Height));
    // ImGui::SetWindowPos(ImVec2(0, 0));
    //     ImGui::TextWrapped("main.cpp");

    // ImGui::End();

    // ImGui::Begin("Editor", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    // ImGui::SetWindowSize(ImVec2(m_Props.Width * 0.8f, m_Props.Height));
    // ImGui::SetWindowPos(ImVec2(m_Props.Width * 0.2f, 0));

    //     ImGui::SetWindowFontScale(1.5f);
    //     static char buffer[1000] = {0};
    //     ImGui::InputTextMultiline("Content", buffer, 1000, ImVec2(m_Props.Width * 0.8f, m_Props.Height));
    //     ImGui::SetWindowFontScale(1.0f); 

    //     if(ImGui::Button("Click me!!")) {
    //         PrintLn("Clicked");
    //     }

    //     // ImGui:: 
    // ImGui::End();
}


void Sanbox::Render()  {
    
}
