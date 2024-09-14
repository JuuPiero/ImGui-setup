#pragma once
#include "Application.h"
// #include <iostream>
class Editor : public Application {
public:
    Editor(ApplicationProperties props);
    ~Editor();

    void Run() override;
    void Shutdown() override;
    void RenderUI();
};