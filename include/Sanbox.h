#pragma once
#include "Application.h"
// #include <iostream>
class Sanbox : public Application {
public:
    Sanbox(ApplicationProperties props);
    void RenderUI() override; 
    void Render() override;
};