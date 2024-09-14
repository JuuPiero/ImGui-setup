#pragma once
struct GLFWwindow;
class ImGuiLayer;
struct ApplicationProperties {
    int Width, Height;
    const char* Title;
};

class Application {
public:
    Application(ApplicationProperties props);
    void Initialize();
    virtual void Run() = 0;
    virtual void Shutdown() = 0;
    virtual ~Application() = default;
protected:
    ApplicationProperties m_Props;
    GLFWwindow* m_Window;
    ImGuiLayer* m_ImGuiLayer;
};