#pragma once

#include <functional>
#include "Prerequisites/Types.h"


namespace ToyWorld
{


class SceneObject
{
public:
    typedef uint32 IdType;

    SceneObject()
        : m_Id(0)
    {
    }

    SceneObject(SceneObject::IdType id)
        : m_Id(id)
    {
    }

    bool operator==(const SceneObject& rh) const
    {
        return this->m_Id == rh.m_Id;
    }


private:
    uint32 m_Id;
    
    friend class SceneObjectHasher;
};

class SceneObjectHasher
{
public:
    size_t operator()(const SceneObject& so) const
    {
        return std::hash<SceneObject::IdType> ()(so.m_Id);
    }
};


} // end of namespace ToyWorld