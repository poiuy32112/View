#include <View.h>
#include <View/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace View
{

    class Viewnut : public Application
    {
    public:
        Viewnut()
            : Application("Viewnut")
        {
            PushLayer(new EditorLayer());
        }

        ~Viewnut()
        {
        }
    };

    Application* CreateApplication()
    {
        return new Viewnut();
    }

}