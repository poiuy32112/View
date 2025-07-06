#pragma once

#include "View/Core/Layer.h"

#include "View/Events/ApplicationEvent.h"
#include "View/Events/KeyEvent.h"
#include "View/Events/MouseEvent.h"

namespace View
{
    	class VIEW_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }

        void SetDarkThemeColors();
    private:
        bool m_BlockEvents = true;
    };

}