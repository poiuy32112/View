#pragma once

#include "Core.h"

#include "Window.h"
#include "View/Core/LayerStack.h"
#include "View/Events/Event.h"
#include "View/Events/ApplicationEvent.h"

#include "View/Core/Timestep.h"

#include "View/ImGui/ImGuiLayer.h"

namespace View
{

    class Application
    {
    public:
        //Application();
        Application(const std::string& name = "View App");
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        //-
        bool OnWindowResize(WindowResizeEvent& e);
        //-

    private:
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;

        //-
        bool m_Minimized = false;
        //-

        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}