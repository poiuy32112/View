#include "vzpch.h"
#include "Entity.h"

namespace View
{

    Entity::Entity(entt::entity handle, Scene* scene)
        : m_EntityHandle(handle), m_Scene(scene)
    {
    }

}