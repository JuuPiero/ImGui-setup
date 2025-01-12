#pragma once
#include "Application.h"
#include <glm/glm.hpp>
// #include <iostream>
class Sanbox : public Application {
public:
    Sanbox(ApplicationProperties props);
    void RenderUI(double deltaTime) override; 
    void Render(double deltaTime) override;
    void HandleInput(double deltaTime) override;
    
    std::vector<glm::vec3> cubePositions;

};