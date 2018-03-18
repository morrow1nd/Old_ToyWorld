#pragma once

#include "Prerequisites/Types.h"


namespace ToyWorld
{


class Engine;

class IModule
{
public:
    virtual void StartUp(Engine& root) = 0;
    virtual void ShutDown() = 0;
    virtual void Update(float delta) { }
    virtual void PostUpdate(float delta) { }
};


} // end of namespace ToyWorld