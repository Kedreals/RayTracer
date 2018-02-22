#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "vec3.hpp"
#include "ray.hpp"

namespace ray_tracer
{
  namespace geometry
  {
    /** \brief simple triangle
     */
    struct Triangle
    {
    private:
      math::Vec3f m_a, m_b, m_c;
      
    public:
      /** \brief simple ctor
       */
      Triangle(const math::Vec3f& a, const math::Vec3f& b, const math::Vec3f& c);
      /** \brief simple copy ctor
       */
      Triangle(const Triangle& other);
      /** \brief default dtor
       */
      ~Triangle();

      /** \brief intersection test using barycentric coordinates
       */
      bool Intersect(core::Ray& ray) const;
    };
  }
}

#endif //_TRIANGLE_HPP_
