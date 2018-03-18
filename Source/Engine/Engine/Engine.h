#pragma once

#include "Prerequisites/Types.h"
#include "Engine/EngineStartUpParam.h"
#include "Base/IModule.h"
#include "Scene/SceneManager.h"


namespace ToyWorld
{


class Engine
{
public:
    void StartUp(const EngineStartUpParam& param);

    void ShutDown();

    void Run();
    
    template<typename ModuleType>
    ModuleType* GetModule()
    {
        return GetModuleHelper<ModuleType>().GetModule(*this);
    }


private:
    friend class GetModuleHelper;

    template<typename ModuleType>
    struct GetModuleHelper
    {
        ModuleType* GetModule(Engine& engine)
        {
            return nullptr;
        }
    };

    template<>
    struct GetModuleHelper<SceneManager>
    {
        SceneManager* GetModule(Engine& engine)
        {
            return &(engine.m_SceneManager);
        }
    };

    void _Update(float delta);
    void _PostUpdate(float delta);

private:
    SceneManager m_SceneManager;
};


} // end of namespace ToyWorld