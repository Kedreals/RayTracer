#ifndef _RAY_HPP_
#define _RAY_HPP_

#include "vec3.hpp"

namespace ray_tracer
{
  namespace core
  {
    struct Ray
    {
    private:
      math::Vec3f m_origin, m_direction;
      float m_t;

    public:
      Ray(const math::Vec3f& origin, const math::Vec3f& direciton);
      Ray(const Ray& other);
      ~Ray();

      float T() const;
      void SetT(float value);

      math::Vec3f O() const;
      void SetO(math::Vec3f& origin);

      math::Vec3f D() const;
      void SetD(math::Vec3f& direction);

      math::Vec3f operator ()() const;
      math::Vec3f operator ()(float t) const;
      
    };
  }
}

#endif //_RAY_HPP_
