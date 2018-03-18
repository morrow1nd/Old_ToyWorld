#pragma once

#include "Prerequisites/Types.h"


namespace ToyWorld
{


// Enum used for object construction specifying the object should be zero initializes
enum TW_ZERO
{
    TwZero
};

// Enum used for matrix/quaternion constructor specifying it should be initialized with an identity value
enum TW_IDENTITY
{
    TwIdentity
};

// Values that represent in which order are euler angles applied when used in transformations
enum class EulerAngleOrder
{
    XYZ,
    XZY,
    YXZ,
    YZX,
    ZXY,
    ZYX
};


} // end of namespace ToyWorld