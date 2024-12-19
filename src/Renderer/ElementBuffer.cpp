#include "Renderer/Buffer.h"

ElementBuffer::ElementBuffer(unsigned int* indices, unsigned int count): m_Count(count), Buffer(indices) {
    glGenBuffers(1, &m_Id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

Shared<ElementBuffer> ElementBuffer::Create(unsigned int* indices, unsigned int count) {
    return std::make_shared<ElementBuffer>(indices, count);
}

ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &m_Id);
}
void ElementBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
}
void ElementBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}