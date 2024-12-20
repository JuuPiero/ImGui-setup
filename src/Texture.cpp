#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"

Texture::Texture(): m_Id(-1) {}

Texture::Texture(const char* imagePath): m_ImagePath(imagePath) {
    glGenTextures(1, &m_Id);
    glBindTexture(GL_TEXTURE_2D, m_Id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    // bytes images
    unsigned char *data = stbi_load(imagePath, &width, &height, &channels, 0);
    
    if (data) {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}
Shared<Texture> Texture::Create(const char* imagePath) {
    return std::make_shared<Texture>(imagePath);
}

Texture::~Texture() {
    PrintLn("Free texture " << m_Id);
    glDeleteTextures(1, &m_Id);
}
