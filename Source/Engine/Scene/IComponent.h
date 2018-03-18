#pragma once

#include "Prerequisites/Types.h"
#include "SceneObject.h"


namespace ToyWorld
{


class IComponent
{
public:
    virtual void Init(SceneObject so) = 0;
    virtual const SceneObject& GetSceneObject() const = 0;
    virtual const SceneObject& SO() const = 0;
    virtual void Destory() = 0;
};


} // end of namespace ToyWorld