#pragma once
#include "Application.h"
#include "Utils.h"
extern Application* CreateApplication();
extern Shared<Application> CreateApp();

int main(int argc, char** argv) {
    auto app = CreateApp();
    app->Run();
    // delete app;
    return 0;
}