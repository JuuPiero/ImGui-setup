#pragma once
#include "Application.h"
extern Application* CreateApplication();

int main(int argc, char** argv) {
    auto app = CreateApplication();

    app->Run();
    app->Shutdown();
    delete app;
    return 0;
}