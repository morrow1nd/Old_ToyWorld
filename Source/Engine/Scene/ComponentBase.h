#pragma once

#include "Prerequisites/Types.h"
#include "IComponent.h"
#include "SceneObject.h"


namespace ToyWorld
{


class ComponentBase : public IComponent
{
public:
    virtual void Init(SceneObject so) override
    {
        m_SO = so;
    }

    virtual const SceneObject& GetSceneObject() const override
    {
        return m_SO;
    }

    virtual const SceneObject& SO() const override
    {
        return m_SO;
    }

    virtual void Destory() override
    {
    }


protected:
    SceneObject m_SO;
};


} // end of namespace ToyWorld