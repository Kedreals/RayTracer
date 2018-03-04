#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "ray.hpp"
#include "color.hpp"

namespace ray_tracer
{
  namespace geometry
  {
    /** \brief simple triangle
     */
    struct Triangle
    {
    private:
      float m_ell;
      math::Vec3f m_a, m_b, m_c;
      light::Color m_color;
      
    public:
      /** \brief simple ctor
       */
      Triangle(const math::Vec3f& a, const math::Vec3f& b, const math::Vec3f& c, float ell = 0.0f);
      /** \brief simple ctor with option for a custom color
       */
      Triangle(const math::Vec3f& a, const math::Vec3f& b, const math::Vec3f& c, const light::Color& color, float ell = 0.0f);
      /** \brief simple copy ctor
       */
      Triangle(const Triangle& other);
      /** \brief default dtor
       */
      ~Triangle();

      /** \brief intersection test using barycentric coordinates
       */
      bool Intersect(core::Ray& ray) const;

      /** \brief calculates the area of the triangle
       */
      float Area() const;

      /** \brief returns the color of this Triangle
       */
      const light::Color& GetColor() const;
      /** \brief returns the radiance of this triangle
       */
      float GetEll() const;

      /** \brief returns the normal
      */
      math::Vec3f GetNormal() const;
    };
  }
}

#endif //_TRIANGLE_HPP_
