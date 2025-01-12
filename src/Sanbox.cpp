#include "Sanbox.h"
#include "ImGuiLayer.h"
#include "Utils.h"
#include "Entry.h"
#include "Renderer/Renderer.h"
#include "Input/Input.h"
#include "Texture.h"

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
Shared<VertexArrayObject> VAO;
Shared<Shader> shader;
Shared<ElementBuffer> EBO;

Shared<Texture> texture;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f); // Vị trí camera
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f); // Hướng nhìn
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); // Vector "up"


glm::mat4 projection(1.0f);
glm::mat4 model(1.0f);
glm::mat4 view(1.0f);


Sanbox::Sanbox(ApplicationProperties props): Application(props) {
    PrintLn("Creating Sanbox");
    
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f,    1.0f, 0.0f, 
        0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 1.0f,    1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f,   0.0f, 1.0f, 

        -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f,   0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.5f, 0.5f, 0.5f, 1.0f,   0.0f, 1.0f,
    };
    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        0, 4, 7, 7, 3, 0,
        1, 5, 6, 6, 2, 1,
        0, 1, 5, 5, 4, 0,
        3, 2, 6, 6, 7, 3
    };
   
    VAO = VertexArrayObject::Create();

    VBO = VertexBuffer::Create(vertices, sizeof(vertices));
    EBO = ElementBuffer::Create(indices, count(indices));
    texture = Texture::Create("../res/a.jpg");
    shader = Shader::Create("../res/default.vert", "../res/default.frag");
    VertexBufferLayout layout;
    layout.Push<float>(3, false);
    layout.Push<float>(4, false);
    layout.Push<float>(2, false);
    VAO->AddBuffer(*VBO, layout);

    texture->Active(0);

    cubePositions = {
        glm::vec3( 0.0f,  0.0f,  0.0f), 
        glm::vec3( 2.0f,  5.0f, -15.0f), 
        glm::vec3(-1.5f, -2.2f, -2.5f),  
        glm::vec3(-3.8f, -2.0f, -12.3f),  
        glm::vec3( 2.4f, -0.4f, -3.5f),  
        glm::vec3(-1.7f,  3.0f, -7.5f),  
        glm::vec3( 1.3f, -2.0f, -2.5f),  
        glm::vec3( 1.5f,  2.0f, -2.5f), 
        glm::vec3( 1.5f,  0.2f, -1.5f), 
        glm::vec3(-1.3f,  1.0f, -1.5f)  
    };

}

void Sanbox::Render(double deltaTime) {
    // view = glm::lookAt(cameraPos, cameraTarget, cameraUp);
    // const float radius = 10.0f;
    // float camX = sin(glfwGetTime()) * radius;
    // float camZ = cos(glfwGetTime()) * radius;
    view = glm::lookAt(cameraPos, cameraTarget, cameraUp);

    projection = glm::perspective(glm::radians(45.0f), (float)m_Props.Width / (float)m_Props.Height, 0.1f, 100.0f);


    texture->Bind();
    shader->Use();  
    VAO->Bind();

    for(unsigned int i = 0; i < 10; i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        float angle = (float)glfwGetTime() * (i + 1); 
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        glm::mat4 MVP = projection * view * model;
        shader->SetMatrix4("MVP", MVP);
        shader->SetTexture("texture1", 0);
        glDrawElements(GL_TRIANGLES, EBO->Count(), GL_UNSIGNED_INT, 0);
    }
}


void Sanbox::RenderUI(double deltaTime) {
    // ImGui::DockSpaceOverViewport(0U, ImGui::GetMainViewport());
    // Application::RenderUI();
    ImGui::Begin("Image Window");
        ImVec2 windowSize = ImGui::GetWindowSize();
        ImGui::Image((void*)(intptr_t)texture->GetTexture(), windowSize, ImVec2(0, 1), ImVec2(1, 0));
    ImGui::End();
    // ImGui::Begin("Work space", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    // ImGui::SetWindowSize(ImVec2(m_Props.Width * 0.2f, m_Props.Height));
    ImGui::Begin("Test window");
        ImGui::Text("FPS: %.1f", 1.0f / deltaTime);
        ImGui::Spacing();
        ImGui::DragFloat3("Cam Target", &cameraTarget[0]);
        ImGui::DragFloat3("Cam Up", &cameraUp[0]);

    ImGui::End();
}


void Sanbox::HandleInput(double deltaTime) {
    float cameraSpeed = 2.5f * (float)deltaTime;
    if(Input::GetKey(GLFW_KEY_W)) 
        cameraPos += cameraSpeed * cameraFront;
    if(Input::GetKey(GLFW_KEY_S))
        cameraPos -= cameraSpeed * cameraFront;
    if(Input::GetKey(GLFW_KEY_A))
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(Input::GetKey(GLFW_KEY_D))
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

    // if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    //     cameraPos += cameraSpeed * cameraFront;
    // if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    //     cameraPos -= cameraSpeed * cameraFront;
    // if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    //     cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    // if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    //     cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}