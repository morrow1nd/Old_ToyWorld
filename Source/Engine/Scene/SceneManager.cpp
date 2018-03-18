#include "Prerequisites/Types.h"
#include "SceneManager.h"
#include "IComponent.h"
#include "Scene.h"


namespace ToyWorld
{


void SceneManager::StartUp(Engine& engine)
{
    m_CurrScene = new Scene();
}

void SceneManager::ShutDown()
{
    if (m_CurrScene != nullptr)
    {
        delete m_CurrScene;
    }
}


} // end of namespace ToyWorld