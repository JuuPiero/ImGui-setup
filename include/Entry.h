#pragma once
#include "Application.h"
#include "Utils.h"
extern Application* CreateApplication();
extern 

int main(int argc, char** argv) {
    auto app = CreateApplication();
    app->Run();
    delete app;
    return 0;
}