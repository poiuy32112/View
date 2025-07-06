#include "vzpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace View
{

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}