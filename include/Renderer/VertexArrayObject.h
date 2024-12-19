#pragma once
#include <vector>
#include "Renderer/Buffer.h"

struct BufferLayout {
    unsigned int count;
    unsigned int type;
    bool normalized;
    unsigned int size;
};

struct VertexBufferLayout {
    template<typename T> void Push(unsigned int count, bool normalized = false);
    std::vector<BufferLayout> elements;
    unsigned int stride = 0;
};

class VertexArrayObject {

public:
    VertexArrayObject();
    static Shared<VertexArrayObject> Create();
    ~VertexArrayObject();
    void Bind();
    void Unbind();
    void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& vertexBufferLayout);


private:
    unsigned int m_Id;
    
};

