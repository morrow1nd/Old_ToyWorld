#include "Prerequisites/Types.h"
#include "Math/Degree.h"
#include "Math/Math.h"
#include "Math/Radian.h"


namespace ToyWorld
{

Degree::Degree(const Radian& r)
    :m_Deg(r.ValueDegrees())
{
}

Degree Degree::Wrap()
{
    m_Deg = fmod(m_Deg, 360.0f);

    if (m_Deg < 0)
        m_Deg += 360.0f;

    return *this;
}

Degree& Degree::operator= (const Radian& r)
{
    m_Deg = r.ValueDegrees();
    return *this;
}

Degree Degree::operator+ (const Radian& r) const
{
    return Degree(m_Deg + r.ValueDegrees());
}

Degree& Degree::operator+= (const Radian& r)
{
    m_Deg += r.ValueDegrees();
    return *this;
}

Degree Degree::operator- (const Radian& r) const
{
    return Degree(m_Deg - r.ValueDegrees());
}

Degree& Degree::operator-= (const Radian& r)
{
    m_Deg -= r.ValueDegrees();
    return *this;
}

float Degree::ValueRadians() const
{
    return m_Deg * Math::DEG2RAD;
}

} // end of namespace ToyWorld