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
    virtual ~Application();
    void Initialize();
    virtual void Shutdown();
    virtual void Run();
    virtual void Render();
    virtual void RenderUI();
    inline const ApplicationProperties& Properties() const { return m_Props; }
    
protected:
    ApplicationProperties m_Props;
    GLFWwindow* m_Window;
    ImGuiLayer* m_ImGuiLayer;
};