#pragma once

#include "View.h"

class ExampleLayer : public View::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(View::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(View::Event& e) override;
private:
	View::ShaderLibrary m_ShaderLibrary;
	View::Ref<View::Shader> m_Shader;
	View::Ref<View::VertexArray> m_VertexArray;

	View::Ref<View::Shader> m_FlatColorShader;
	View::Ref<View::VertexArray> m_SquareVA;

	View::Ref<View::Texture2D> m_Texture, m_ChernoLogoTexture;

	View::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};