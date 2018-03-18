#pragma once

#include "Prerequisites/Types.h"
#include "RenderAPI/RenderAPIPlatformSpecific.h"


namespace ToyWorld
{


class GpuVertexData
{
public:
    GpuVertexData()
      : m_VBO(GetVBOInitValue()),
        m_EBO(GetEBOInitValue())
    {
    }

    // Construct the real GPU VBO and EBO, and then fill them with these data
    // Note: GpuVertexData doesn't keep these pointers
    void Construct(float* vertexData, int vertexDataSize, GpuVertexDataUsage vertexDataUsage,
        uint32* indexData, int indexDataSize, GpuVertexDataUsage indexDataUsage);

    // Define an array of generic vertex attribute data
    // Arguments:
    //  index: Specifies the index of the generic vertex attribute to be modified
    //  size: Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4.
    //  type: Specifies the data type of each component in the array.
    //  normalized:
    //  stride: Specifies the byte offset between consecutive generic vertex attributes
    //  pointer: Specifies a offset of the first component of the first generic vertex attribute in the array
    //      in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target. The initial value
    //      is 0.
    void SetAttribute(uint32 index, int size, GpuDataType type, bool normalized,
        int stride, const void* pointer);

    void BindVAO();

    void UnbindVAO();

    void Destory();


private:
    VBO m_VBO;
    EBO m_EBO;

    VAO m_VAO;
};


} // end of namespace ToyWorld