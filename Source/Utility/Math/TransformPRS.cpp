#include "Prerequisites/Types.h"
#include "Math/TransformPRS.h"


namespace ToyWorld
{


TransformPRS::TransformPRS()
    : m_LocalPosition(Vector3::ZERO),
    m_LocalRotation(Quaternion::IDENTITY),
    m_LocalScale(Vector3::ONE)
{
}

TransformPRS::TransformPRS(const Vector3& position, const Quaternion& rotation, const Vector3& scale)
    : m_LocalPosition(position),
    m_LocalRotation(rotation),
    m_LocalScale(scale)
{
}

Matrix4 TransformPRS::GetMatrix() const
{
    return Matrix4::TRS(m_LocalPosition, m_LocalRotation, m_LocalScale);
}

Matrix4 TransformPRS::GetInverseMatrix() const
{
    return Matrix4::inverseTRS(m_LocalPosition, m_LocalRotation, m_LocalScale);
}

void TransformPRS::MakeLocal(const TransformPRS& parent)
{
    SetWorldPosition(m_LocalPosition, parent);
    SetWorldRotation(m_LocalRotation, parent);
    SetWorldScale(m_LocalScale, parent);
}

void TransformPRS::MakeWorld(const TransformPRS& parent)
{
    // Update orientation
    const Quaternion& parentOrientation = parent.GetRotation();
    m_LocalRotation = parentOrientation * m_LocalRotation;

    // Update scale
    const Vector3& parentScale = parent.GetScale();

    // Scale own position by parent scale, just combine as equivalent axes, no shearing
    m_LocalScale = parentScale * m_LocalScale;

    // Change position vector based on parent's orientation & scale
    m_LocalPosition = parentOrientation.rotate(parentScale * m_LocalPosition);

    // Add altered position vector to parents
    m_LocalPosition += parent.GetPosition();
}

void TransformPRS::SetWorldPosition(const Vector3& position, const TransformPRS& parent)
{
    Vector3 invScale = parent.GetScale();
    if (invScale.x != 0) invScale.x = 1.0f / invScale.x;
    if (invScale.y != 0) invScale.y = 1.0f / invScale.y;
    if (invScale.z != 0) invScale.z = 1.0f / invScale.z;

    Quaternion invRotation = parent.GetRotation().inverse();

    m_LocalPosition = invRotation.rotate(position - parent.GetPosition()) *  invScale;
}

void TransformPRS::SetWorldRotation(const Quaternion& rotation, const TransformPRS& parent)
{
    Quaternion invRotation = parent.GetRotation().inverse();
    m_LocalRotation = invRotation * rotation;
}

void TransformPRS::SetWorldScale(const Vector3& scale, const TransformPRS& parent)
{
    Matrix3 rotScale;
    Matrix4 parentMatrix = parent.GetMatrix();
    parentMatrix.extract3x3Matrix(rotScale);
    rotScale.inverse();

    Matrix3 scaleMat = Matrix3(Quaternion::IDENTITY, scale);
    scaleMat = rotScale * scaleMat;

    Quaternion rotation;
    Vector3 localScale;
    scaleMat.decomposition(rotation, localScale);

    m_LocalScale = localScale;
}

void TransformPRS::LookAt(const Vector3& location, const Vector3& up)
{
    Vector3 forward = location - GetPosition();

    Quaternion rotation = GetRotation();
    rotation.lookRotation(forward, up);
    SetRotation(rotation);
}

void TransformPRS::Move(const Vector3& vec)
{
    SetPosition(GetPosition() + vec);
}

void TransformPRS::MoveRelative(const Vector3& vec)
{
    // Transform the axes of the relative vector by camera's local axes
    Vector3 trans = GetRotation().rotate(vec);

    SetPosition(GetPosition() + trans);
}

void TransformPRS::Rotate(const Vector3& axis, const Radian& angle)
{
    Quaternion q;
    q.fromAxisAngle(axis, angle);
    Rotate(q);
}

void TransformPRS::Rotate(const Quaternion& q)
{
    // Note the order of the mult, i.e. q comes after

    // Normalize the quat to avoid cumulative problems with precision
    Quaternion qnorm = q;
    qnorm.normalize();
    SetRotation(qnorm * GetRotation());
}

void TransformPRS::Roll(const Radian& angle)
{
    // Rotate around local Z axis
    Vector3 zAxis = GetRotation().rotate(Vector3::UNIT_Z);
    Rotate(zAxis, angle);
}

void TransformPRS::Yaw(const Radian& angle)
{
    Vector3 yAxis = GetRotation().rotate(Vector3::UNIT_Y);
    Rotate(yAxis, angle);
}

void TransformPRS::Pitch(const Radian& angle)
{
    // Rotate around local X axis
    Vector3 xAxis = GetRotation().rotate(Vector3::UNIT_X);
    Rotate(xAxis, angle);
}

void TransformPRS::SetForward(const Vector3& forwardDir)
{
    Quaternion currentRotation = GetRotation();
    currentRotation.lookRotation(forwardDir);
    SetRotation(currentRotation);
}


} // end of namespace ToyWorld