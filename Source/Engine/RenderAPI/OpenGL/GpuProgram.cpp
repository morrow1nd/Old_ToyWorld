#include "RenderAPI/GpuProgram.h"


namespace ToyWorld
{


bool GpuProgram::Init(const String & vertexShaderCode, const String & fragmentShaderCode)
{
    const char* code;
    int success;
    char infoLog[512];

    // Vertex shader
    ShaderInternal vertexShader = glCreateShader(GL_VERTEX_SHADER);
    code = vertexShaderCode.c_str();
    glShaderSource(vertexShader, 1, &code, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, sizeof(infoLog), NULL, infoLog);
        m_ErrorCode = GpuProgram::GpuProgramError::GPE_VertexShaderError;
        m_ErrorInfo = String(infoLog);
        return false;
    }

    // Fragment shader
    ShaderInternal fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    code = fragmentShaderCode.c_str();
    glShaderSource(fragmentShader, 1, &code, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, sizeof(infoLog), NULL, infoLog);
        m_ErrorCode = GpuProgram::GpuProgramError::GPE_FragmentShaderError;
        m_ErrorInfo = String(infoLog);
        return false;
    }

    // Link shaders
    m_ShaderProgram = glCreateProgram();
    glAttachShader(m_ShaderProgram, vertexShader);
    glAttachShader(m_ShaderProgram, fragmentShader);
    glLinkProgram(m_ShaderProgram);
    glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_ShaderProgram, sizeof(infoLog), NULL, infoLog);
        m_ErrorCode = GpuProgram::GpuProgramError::GPE_LinkError;
        m_ErrorInfo = String(infoLog);
        return false;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    m_ErrorCode = GpuProgramError::GPE_NoError;
    return true;
}

GpuProgram::GpuProgramError GpuProgram::GetErrorCode() const
{
    return m_ErrorCode;
}

const String & GpuProgram::GetErrorInfo() const
{
    return m_ErrorInfo;
}

void GpuProgram::UseProgram()
{
    glUseProgram(m_ShaderProgram);
}

UniformLocation GpuProgram::GetUniformLocation(const String& uniformVariableName)
{
    return glGetUniformLocation(m_ShaderProgram, uniformVariableName.c_str());
}

void GpuProgram::SetUniform(const UniformLocation & location, float v)
{
    glUniform1f(location, v);
}

void GpuProgram::SetUniform(const UniformLocation & location, float v0, float v1)
{
    glUniform2f(location, v0, v1);
}

void GpuProgram::SetUniform(const UniformLocation & location, float v0, float v1, float v2)
{
    glUniform3f(location, v0, v1, v2);
}

void GpuProgram::SetUniform(const UniformLocation & location, float v0, float v1, float v2, float v3)
{
    glUniform4f(location, v0, v1, v2, v3);
}

void GpuProgram::SetUniform(const UniformLocation & location, int v)
{
    glUniform1i(location, v);
}

void GpuProgram::SetUniform(const UniformLocation & location, int v0, int v1)
{
    glUniform2i(location, v0, v1);
}

void GpuProgram::SetUniform(const UniformLocation & location, int v0, int v1, int v2)
{
    glUniform3i(location, v0, v1, v2);
}

void GpuProgram::SetUniform(const UniformLocation & location, int v0, int v1, int v2, int v3)
{
    glUniform4i(location, v0, v1, v2, v3);
}

void GpuProgram::SetUniform(const UniformLocation & location, uint32 v)
{
    glUniform1ui(location, v);
}

void GpuProgram::SetUniform(const UniformLocation & location, uint32 v0, uint32 v1)
{
    glUniform2ui(location, v0, v1);
}

void GpuProgram::SetUniform(const UniformLocation & location, uint32 v0, uint32 v1, uint32 v2)
{
    glUniform3ui(location, v0, v1, v2);
}

void GpuProgram::SetUniform(const UniformLocation & location, uint32 v0, uint32 v1, uint32 v2, uint32 v3)
{
    glUniform4ui(location, v0, v1, v2, v3);
}

void GpuProgram::SetUniform(const UniformLocation & location, int count, const float * value)
{
    // TODO: see http://docs.gl/gl4/glUniform
}

void GpuProgram::SetUniform(const UniformLocation & location, int count, const int * value)
{
    // TODO: see http://docs.gl/gl4/glUniform
}

void GpuProgram::SetUniform(const UniformLocation & location, int count, const uint32 * value)
{
    // TODO: see http://docs.gl/gl4/glUniform
}


} // end of namespace ToyWorld