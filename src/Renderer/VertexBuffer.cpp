#include "Renderer/Buffer.h"

VertexBuffer::VertexBuffer(void* data, unsigned int size): Buffer(data), m_Size(size) {
    glGenBuffers(1, &m_Id);
    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

Shared<VertexBuffer> VertexBuffer::Create(void* data, unsigned int size) {
    return std::make_shared<VertexBuffer>(data, size);
}


VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_Id);
}
void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}
void VertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}