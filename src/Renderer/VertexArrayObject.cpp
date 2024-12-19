#include "Renderer/VertexArrayObject.h"
#include "Utils.h"

VertexArrayObject::VertexArrayObject() {
    glGenVertexArrays(1, &m_Id);
    glBindVertexArray(m_Id);
}

void VertexArrayObject::Bind() {
    glBindVertexArray(m_Id);

}
void VertexArrayObject::Unbind() {
    glBindVertexArray(0);

}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &m_Id);
}
void VertexArrayObject::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout) {
    vertexBuffer.Bind();
    unsigned int offset = 0;
    auto& elements = vertexBufferLayout.elements;
    for (int i = 0; i < elements.size(); i++) {
        // PrintLn(i << "|" << vertexBufferLayout.elements[i].count << "|" << vertexBufferLayout.elements[i].type << "|" << vertexBufferLayout.elements[i].normalized << "|" <<  vertexBufferLayout.stride << "|" << offset);
        glVertexAttribPointer(i, vertexBufferLayout.elements[i].count, vertexBufferLayout.elements[i].type, vertexBufferLayout.elements[i].normalized ? GL_TRUE : GL_FALSE, vertexBufferLayout.stride, (void*)offset);
        glEnableVertexAttribArray(i);  
        offset += vertexBufferLayout.elements[i].size;
    }
}
template<typename T> void VertexBufferLayout::Push(unsigned int count, bool normalized) {}

template<> void VertexBufferLayout::Push<float>(unsigned int count, bool normalized) {
    elements.push_back({count, GL_FLOAT, normalized, (unsigned int)(count * sizeof(float))});
    stride += count * sizeof(float);
}

Shared<VertexArrayObject> VertexArrayObject::Create() {
    return std::make_shared<VertexArrayObject>();
}