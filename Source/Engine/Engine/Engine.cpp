#include "Prerequisites/Types.h"
#include "Engine/Engine.h"
#include "Scene/SceneManager.h"
#include "RenderAPI/RenderAPI.h"


namespace ToyWorld
{


void Engine::StartUp(const EngineStartUpParam& param)
{
    RenderAPI::Instance().Init(3, 3, "tem", 800, 600);
    m_SceneManager.StartUp(*this);
}

void Engine::ShutDown()
{
    m_SceneManager.ShutDown();
}

void Engine::Run()
{
    while (true)
    {
        // Limit FPS if needed
        //if (m_FrameStep > 0)
        //{
        //
        //}

        _Update(1);
        _PostUpdate(1);
    }
}

void Engine::_Update(float delta)
{
    m_SceneManager.Update(delta);
}

void Engine::_PostUpdate(float delta)
{
    m_SceneManager.PostUpdate(delta);
}


} // end of namespace ToyWorld