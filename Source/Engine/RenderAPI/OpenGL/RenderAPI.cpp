#include "RenderAPI/RenderAPI.h"
#include "GLFW/glfw3.h"


namespace ToyWorld
{


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void RenderAPI::Init(int glfwContextVersionMajor, int glfwContextVersionMinor, const String& windowTitle,
    int windowWidth, int windowHegiht)
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfwContextVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfwContextVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHegiht, windowTitle.c_str(), NULL, NULL);
    if (window == NULL)
    {
        // TODO: showErrorMsgBox(...)
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // TODO: showErrorMsgBox(...)
        // std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    m_Window = window;
}

void RenderAPI::ClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void ToyWorld::RenderAPI::ClearColorBufferBit()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderAPI::DrawElements(GpuPrimitiveType mode, int count, GpuDataType type, const void * indices)
{
    glDrawElements(mode, count, type, indices);
}

void RenderAPI::SwapBuffers()
{
    glfwSwapBuffers((GLFWwindow*)m_Window);
}


} // end of namespace ToyWorld