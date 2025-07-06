#pragma once

#include "View/Core/Core.h"
#include "View/Core/KeyCodes.h"
#include "View/Core/MouseCodes.h"

namespace View
{

    	class VIEW_API Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);

        static bool IsMouseButtonPressed(MouseCode button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();

    };

}