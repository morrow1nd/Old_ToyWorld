#pragma once

#include "Prerequisites/Types.h"
#include "Prerequisites/StdHeaders.h"
#include "RenderAPI/RenderAPIPlatformSpecific.h"


namespace ToyWorld
{


// Normal gpu program: one vertex shader and one fragment shader
class GpuProgram
{
public:
    enum GpuProgramError
    {
        GPE_NoError = 0,
        GPE_VertexShaderError,
        GPE_FragmentShaderError,
        GPE_LinkError,
    };

public:
    GpuProgram()
        :
        m_ShaderProgram(GetProgramInternalInitValue()),
        m_ErrorCode(GPE_NoError)
    {
    }

    bool Init(const String& vertexShaderCode, const String& fragmentShaderCode);

    GpuProgramError GetErrorCode() const;

    const String& GetErrorInfo() const;

    // Bind this gpu program
    void UseProgram();

    UniformLocation GetUniformLocation(const String& uniformVariableName);

    // Uniform variable setters
    void SetUniform(const UniformLocation& location, float v);
    void SetUniform(const UniformLocation& location, float v0, float v1);
    void SetUniform(const UniformLocation& location, float v0, float v1, float v2);
    void SetUniform(const UniformLocation& location, float v0, float v1, float v2, float v3);
    void SetUniform(const UniformLocation& location, int v);
    void SetUniform(const UniformLocation& location, int v0, int v1);
    void SetUniform(const UniformLocation& location, int v0, int v1, int v2);
    void SetUniform(const UniformLocation& location, int v0, int v1, int v2, int v3);
    void SetUniform(const UniformLocation& location, uint32 v);
    void SetUniform(const UniformLocation& location, uint32 v0, uint32 v1);
    void SetUniform(const UniformLocation& location, uint32 v0, uint32 v1, uint32 v2);
    void SetUniform(const UniformLocation& location, uint32 v0, uint32 v1, uint32 v2, uint32 v3);
    void SetUniform(const UniformLocation& location, int count, const float* value);
    void SetUniform(const UniformLocation& location, int count, const int* value);
    void SetUniform(const UniformLocation& location, int count, const uint32* value);
    // TODO: SetUniformMatrix...


private:
    ProgramInternal m_ShaderProgram;
    GpuProgramError m_ErrorCode;
    String m_ErrorInfo;
};


} // end of namespace ToyWorld