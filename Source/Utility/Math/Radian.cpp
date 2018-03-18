#include "Math/Radian.h"
#include "Math/Math.h"
#include "Degree.h"


namespace ToyWorld
{


Radian::Radian(const Degree& d) : m_Rad(d.ValueRadians())
{
}

Radian Radian::Wrap()
{
    m_Rad = fmod(m_Rad, Math::TWO_PI);

    if (m_Rad < 0)
        m_Rad += Math::TWO_PI;

    return *this;
}

Radian& Radian::operator= (const Degree& d)
{
    m_Rad = d.ValueRadians();
    return *this;
}

Radian Radian::operator+ (const Degree& d) const
{
    return Radian(m_Rad + d.ValueRadians());
}

Radian& Radian::operator+= (const Degree& d)
{
    m_Rad += d.ValueRadians();
    return *this;
}

Radian Radian::operator- (const Degree& d) const
{
    return Radian(m_Rad - d.ValueRadians());
}

Radian& Radian::operator-= (const Degree& d)
{
    m_Rad -= d.ValueRadians();
    return *this;
}

float Radian::ValueDegrees() const
{
    return m_Rad * Math::RAD2DEG;
}


} // end of namespace ToyWorld