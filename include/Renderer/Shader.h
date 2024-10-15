#pragma once


class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();

    inline unsigned int GetShader() { return m_Id; }
private:
    unsigned int m_Id;
};

