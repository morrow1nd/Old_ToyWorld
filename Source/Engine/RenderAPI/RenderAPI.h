#pragma once

#include "Prerequisites/Types.h"
#include "Prerequisites/StdHeaders.h"
#include "Base/ISingleton.h"
#include "RenderAPI/RenderAPIPlatformSpecific.h"


namespace ToyWorld
{


class RenderAPI : public ISingleton<RenderAPI>
{
public:
    RenderAPI()
        : m_Window(nullptr)
    {
    }

    void Init(int glfwContextVersionMajor, int glfwContextVersionMinor, const String& windowTitle,
        int windowWidth, int windowHegiht);

    // Clear render target's color
    void ClearColor(float r, float g, float b, float a);

    void ClearColorBufferBit();

    // Render primitives from array data
    //  mode: Specifies what kind of primitives to render
    //  count: Specifies the number of elements to be rendered
    //  type: Specifies the type of the values in indices. Must be one of UnsignedByte, UnsignedShort, or UnsignedInt.
    //  indices: Specifies an offset of the first index in the array in the data store of the buffer currently
    //      bound to the EBO target.
    void DrawElements(GpuPrimitiveType mode, int count, GpuDataType type, const void* indices);

    void SwapBuffers();


private:
    void* m_Window;
};


} // end of namespace ToyWorld