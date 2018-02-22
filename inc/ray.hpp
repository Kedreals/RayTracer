#ifndef _RAY_HPP_
#define _RAY_HPP_

#include "vec3.hpp"

namespace ray_tracer
{
  namespace core
  {
    /** \brief simple ray class
     */
    struct Ray
    {
    private:
      math::Vec3f m_origin, m_direction;
      float m_t;

    public:
      /** \brief simple ctor
       */
      Ray(const math::Vec3f& origin, const math::Vec3f& direciton);
      /** \brief copy ctor
       */
      Ray(const Ray& other);
      /** \brief default dtor
       */
      ~Ray();

      /** \brief returns the t value
       */
      float T() const;
      /** \brief sets the t value
       */
      void SetT(float value);

      /** \brief returns the origin 
       */
      math::Vec3f O() const;
      /** \brief sets the origin
       */
      void SetO(math::Vec3f& origin);

      /** \brief returns the direction
       */
      math::Vec3f D() const;
      /** \brief sets the direction
       */
      void SetD(math::Vec3f& direction);

      /** \brief calculates the position where the ray is at

	  simply evaluates origin + t*direction
       */
      math::Vec3f operator ()() const;
      /** \brief calculates the position where the ray would be with the given t

	  simply evaluates origin + t*direction
       */
      math::Vec3f operator ()(float t) const;
      
    };
  }
}

#endif //_RAY_HPP_
