#pragma once
#include "Utils.h"

class Texture {
public:
    Texture();
    Texture(const char* imagePath);
    ~Texture();
    static Shared<Texture> Create(const char* imagePath);

    inline unsigned int GetTexture() { return m_Id; }
    inline unsigned int GetWidth() { return m_Width; }
    inline unsigned int GetHeight() { return m_Height; }
    inline const std::string& GetImagePath() { return m_ImagePath; }
    glm::vec2 GetSize() { return glm::vec2(m_Width, m_Height); }

    inline void Bind() { glBindTexture(GL_TEXTURE_2D, m_Id); }
    inline void Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }

private:
    unsigned int m_Id;
    unsigned int m_Width;
    unsigned int m_Height;
    std::string m_ImagePath;
};

