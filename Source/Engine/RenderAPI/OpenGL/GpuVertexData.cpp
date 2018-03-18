#include "RenderAPI/GpuVertexData.h"


namespace ToyWorld
{


void GpuVertexData::Construct(float* vertexData, int vertexDataSize, GpuVertexDataUsage vertexDataUsage,
    uint32* indexData, int indexDataSize, GpuVertexDataUsage indexDataUsage)
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    // Bind the vertex array object first, then bind and set vertex buffer(s), and then configure vertex
    // attributes(s).
    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize, vertexData, (GLenum)vertexDataUsage);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSize, indexData, indexDataUsage);
}

void GpuVertexData::SetAttribute(uint32 index, int size, GpuDataType type, bool normalized,
    int stride, const void* pointer)
{
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(index);
}

void GpuVertexData::BindVAO()
{
    glBindVertexArray(m_VAO);
}

void GpuVertexData::UnbindVAO()
{
    glBindVertexArray(GetVAOInitValue()); // 0
}

void GpuVertexData::Destory()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
}


} // end of namespace ToyWorld