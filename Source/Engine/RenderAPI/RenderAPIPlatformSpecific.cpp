#include "Prerequisites/Types.h"
#include "RenderAPI/RenderAPIPlatformSpecific.h"

#if defined(TOY_WORLD_RENDER_API_OPENGL)
# include "glad/../../src/glad.c"
#elif defined(TOY_WORLD_RENDER_API_DX11)

#endif


namespace ToyWorld
{


#if defined(TOY_WORLD_RENDER_API_OPENGL)

VBO GetVBOInitValue()
{
    return 0;
}

EBO GetEBOInitValue()
{
    return 0;
}

VAO GetVAOInitValue()
{
    return 0;
}

ShaderInternal GetShaderInternalInitValue()
{
    return 0;
}

ProgramInternal GetProgramInternalInitValue()
{
    return 0;
}

#elif defined(TOY_WORLD_RENDER_API_DX11)

#endif


} // end of namespace ToyWorld