#include "vzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace View
{

    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        		VI_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        VI_PROFILE_FUNCTION();

        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        		VI_CORE_ASSERT(status, "Failed to initialize Glad!");

        VI_CORE_INFO("OpenGL Info:");
        //VI_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        //VI_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        //VI_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
        VI_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        VI_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        VI_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

    }

    void OpenGLContext::SwapBuffers()
    {
        VI_PROFILE_FUNCTION();

        glfwSwapBuffers(m_WindowHandle);
    }

}