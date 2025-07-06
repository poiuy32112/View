#pragma once

#include "View.h"

class Sandbox2D : public View::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(View::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(View::Event& e) override;
private:
    View::OrthographicCameraController m_CameraController;

    // Temp
    View::Ref<View::VertexArray> m_SquareVA;
    View::Ref<View::Shader> m_FlatColorShader;

    View::Ref<View::Texture2D> m_CheckerboardTexture;

    glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
