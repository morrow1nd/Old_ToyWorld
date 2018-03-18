#pragma once


#include "Prerequisites/Types.h"
#include "SceneObject.h"


namespace ToyWorld
{


class IComponent;


class IComponentManager
{
public:
    virtual IComponent* GetComponent(SceneObject so) = 0;
    virtual IComponent& AddComponent(SceneObject so) = 0;
    virtual void DestoryComponent(SceneObject so) = 0;
    virtual bool HasComponent(SceneObject so) = 0;

};


} // end of namespace ToyWorld