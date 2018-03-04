#ifndef _MONTE_CARLO_HPP_
#define _MONTE_CARLO_HPP_

#include "triangle.hpp"

namespace ray_tracer
{
  namespace math
  {
    /** \brief a struct for spherical coordinates
     */
    struct H2Coordinates
    {
    public:
      float phi, theta;
      
    };

    /** \brief returns a point in the upper hemisphere that is cosine weighted to the theta coordinate

	the distribution is cos(theta)/pi
     */
    H2Coordinates CosWeightedH2();
    /** \brief evaluates the direction corelating to the given normal and spherical coordinates
     */
    Vec3f TransformH2ToR3(const Vec3f& n, H2Coordinates omega);
    /** \brief evaluates the spherical coordinates of the \a d to the \a n
     */
    H2Coordinates TransformR3ToH2(const Vec3f& n, const Vec3f& d);
    /** \brief generates a Cosine Weighted direction in the hemisphere centered around n

	\sa CosWeightedH2() 
	\sa TransformH2ToR3()
     */
    Vec3f CosWeightedPointR3(const Vec3f& n);
    /** \brief Monte Carlo integration of the light field on a given intersection

	generates \a sampleCount many rays from the \a pos. All are cosine weighted in the hemisphere
	centered around \a n. Then the intersections with the lights are evaluated. Finaly the sum
	of all hit light sources is divided by \a sampleCount.
     */
    light::Color MonteCarlo(const Vec3f& pos, const Vec3f& n,int numObj , const geometry::Triangle* obj,int numlights, const geometry::Triangle* lights, int sampleCount = 64);
  }
}

#endif
