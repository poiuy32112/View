#include "vzpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace View
{
    Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    VI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(size);
        }

        VI_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    //VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
    //{
    //    switch (Renderer::GetAPI())
    //    {
    //    case RendererAPI::API::None:    VI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
    //    case RendererAPI::API::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
    //    }

    //    VI_CORE_ASSERT(false, "Unknown RendererAPI!");
    //    return nullptr;
    //}

    //IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    //{
    //    switch (Renderer::GetAPI())
    //    {
    //    case RendererAPI::API::None:    VI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
    //    case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(indices, size);
    //    }

    //    VI_CORE_ASSERT(false, "Unknown RendererAPI!");
    //    return nullptr;
    //}
    Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    VI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(vertices, size);
        }

        VI_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    VI_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLIndexBuffer>(indices, size);
        }

        VI_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}