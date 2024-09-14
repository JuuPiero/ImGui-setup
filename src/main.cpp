#include "Entry.h"
#include "Editor.h"
#include "Ultils.h"


static char buffer[1000] = {0};

void Editor::RenderUI() {

    ImGui::Begin("Work space", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    ImGui::SetWindowSize(ImVec2(m_Props.Width * 0.2f, m_Props.Height));
    ImGui::SetWindowPos(ImVec2(0, 0));
        ImGui::TextWrapped("main.cpp");

    ImGui::End();

    ImGui::Begin("Editor", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    ImGui::SetWindowSize(ImVec2(m_Props.Width * 0.8f, m_Props.Height));
    ImGui::SetWindowPos(ImVec2(m_Props.Width * 0.2f, 0));
        // ImGui::TextWrapped("ss");

        ImGui::SetWindowFontScale(1.5f);
        ImGui::InputTextMultiline("Content", buffer, 1000, ImVec2(m_Props.Width * 0.8f, m_Props.Height));
        ImGui::SetWindowFontScale(1.0f); 

        if(ImGui::Button("Click me!!")) {
            PrintLn("Clicked");
        }


    ImGui::End();

}


Application* CreateApplication() {
    auto props = ApplicationProperties();
    props.Width = 1080;
    props.Height = 800;
    props.Title = "Text Editor";

    return new Editor(props);
}