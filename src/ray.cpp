#include "ray.hpp"
#include <limits>

namespace ray_tracer
{
  namespace core
  {
    using namespace math;

    Ray::Ray(const Vec3f& origin, const Vec3f& direction) : m_origin(origin), m_direction(direction / direction.Norm()), m_t(std::numeric_limits<float>::infinity())
    {
    }

    Ray::Ray(const Ray& other) : m_origin(other.m_origin), m_direction(other.m_direction), m_t(other.m_t)
    {
    }

    Ray::~Ray()
    {
    }

    float Ray::T() const
    {
      return m_t;
    }

    void Ray::SetT(float value)
    {
      m_t = value;
    }

    Vec3f Ray::O() const
    {
      return m_origin;
    }

    void Ray::SetO(Vec3f& origin)
    {
      m_origin = origin;
    }

    Vec3f Ray::D() const
    {
      return m_direction;
    }

    void Ray::SetD(Vec3f& origin)
    {
      m_direction = origin;
    }

    Vec3f Ray::operator ()() const
    {
      return m_origin + m_t*m_direction;
    }

    Vec3f Ray::operator ()(float t) const
    {
      return m_origin + t*m_direction;
    }
  }
}
