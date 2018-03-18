#pragma once

#include "Prerequisites/Types.h"
#include "ToyWorldConfig.h"

#if defined(TOY_WORLD_RENDER_API_OPENGL)
# include "glad/glad.h"
#elif defined(TOY_WORLD_RENDER_API_DX11)

#endif


namespace ToyWorld
{

#if defined(TOY_WORLD_RENDER_API_OPENGL)

typedef GLuint VBO;
VBO GetVBOInitValue();

typedef GLuint EBO;
EBO GetEBOInitValue();

typedef GLuint VAO;
VAO GetVAOInitValue();

typedef GLuint ShaderInternal;
ShaderInternal GetShaderInternalInitValue();

typedef GLuint ProgramInternal;
ProgramInternal GetProgramInternalInitValue();

typedef GLint UniformLocation;

enum GpuVertexDataUsage
{
    StaticDraw = GL_STATIC_DRAW,
    DynamicDraw = GL_DYNAMIC_DRAW,
    StreamDraw = GL_STREAM_DRAW,
};

enum GpuDataType
{
    Bool = GL_BOOL,
    UnsignedByte = GL_UNSIGNED_BYTE,
    Short = GL_SHORT,
    UnsignedShort = GL_UNSIGNED_SHORT,
    Int = GL_INT,
    UnsignedInt = GL_UNSIGNED_INT,
    HalfFloat = GL_HALF_FLOAT,
    Float = GL_FLOAT,
    Double = GL_DOUBLE,
    // TODO: and more, see http://docs.gl/gl4/glVertexAttribPointer
};

enum GpuPrimitiveType
{
    Points = GL_POINTS,
    LineStrip = GL_LINE_STRIP,
    LineLoop = GL_LINE_LOOP,
    Lines = GL_LINES,
    LineStripAdjacency = GL_LINE_STRIP_ADJACENCY,
    LinesAdjacency = GL_LINES_ADJACENCY,
    TriangleStrip = GL_TRIANGLE_STRIP,
    TriangleFan = GL_TRIANGLE_FAN,
    Triangles = GL_TRIANGLES,
    TriangleStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
    TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
    Patches = GL_PATCHES
};


#elif defined(TOY_WORLD_RENDER_API_DX11)

#endif


} // end of namespace ToyWorld