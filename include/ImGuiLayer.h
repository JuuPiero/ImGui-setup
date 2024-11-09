#pragma once
#include "Application.h"
class ImGuiLayer {

public:
    ImGuiLayer(ApplicationProperties* properties);
    ~ImGuiLayer();
    void Initialize(); 
    void BeginFrame();
    void EndFrame();
private:
    ApplicationProperties* properties;
};


