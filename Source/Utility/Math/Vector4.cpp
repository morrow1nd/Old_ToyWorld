#include "Prerequisites/Types.h"
#include "Math/Vector4.h"
#include "Math/Math.h"


namespace ToyWorld
{


const Vector4 Vector4::ZERO(0, 0, 0, 0);

bool Vector4::isNaN() const
{
    return Math::IsNaN(x) || Math::IsNaN(y) || Math::IsNaN(z) || Math::IsNaN(w);
}


} // end of namespace ToyWorld