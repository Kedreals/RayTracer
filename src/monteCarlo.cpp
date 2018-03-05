#include "monteCarlo.hpp"
#include <cstdlib>
#include <cmath>

using namespace ray_tracer::light;
using namespace ray_tracer::core;

namespace ray_tracer
{
  namespace math
  {
    float RandFloat()
    {
      return static_cast<float>(rand())/static_cast<float>(RAND_MAX);
    }
    
    H2Coordinates CosWeightedH2()
    {
      H2Coordinates res;

      res.phi = RandFloat() * 2 * PI;
      res.theta = asin(sqrt(RandFloat()));
      
      return res;
    }

    Vec3f TransformH2ToR3(const Vec3f& n, H2Coordinates omega)
    {
      //bring n in spherical coordinates centered around (0, 0, 1)
      float t = acos(n.Z());
      float p = atan2(n.Y(), n.X());

      //generate Rotation matrix to rotate (0, 0, 1) to n
      Mat3x3 RotT(cos(t), 0, sin(t),
		  0, 1, 0,
		  -sin(t), 0, cos(t));
      Mat3x3 RotP(cos(p), -sin(p), 0,
		  sin(p), cos(p), 0,
		  0, 0, 1);

      //generate R3 vector from omega if n where (0, 0, 1)
      Vec3f r(sin(omega.theta)*cos(omega.phi), sin(omega.theta)*sin(omega.phi), cos(omega.theta));

      //apply rotation to get R3 vector in the right direction
      return RotP*RotT*r;
    }

    H2Coordinates TransformR3ToH2(const Vec3f& n, const Vec3f& d)
    {
      //get spherical coordinates of n
      float t = acos(n.Z());
      float p = atan2(n.Y(), n.X());

      //generate rotation matrices to transform n to (0, 0, 1)
      Mat3x3 RotP(cos(-p), -sin(-p), 0,
		  sin(-p), cos(-p), 0,
		  0, 0, 1);
      Mat3x3 RotT(cos(-t), 0, sin(-t),
		  0, 1, 0,
		  -sin(-t), 0, cos(-t));

      //apply transformations to d
      Vec3f tmp = RotT*RotP*d;

      //get spherical coordinates of the resulting vector
      H2Coordinates res;
      res.theta = acos(tmp.Z());
      res.phi = atan2(tmp.Y(), tmp.X());

      return res;
    }

    Vec3f CosWeightedPointR3(const Vec3f& n)
    {
      return TransformH2ToR3(n, CosWeightedH2());
    }

    Color MonteCarlo(const Vec3f& pos, const Vec3f& n, const Scene& scene, int sampleCount)
    {
      Color res(0.0, 0.0, 0.0);

      for(int i = 0; i < sampleCount; ++i)
	{
	  Intersection intersect;
	  Ray r(pos + 0.001f*n, CosWeightedPointR3(n));

	  if(scene.Intersect(r, intersect))
	    //implicitly used diffuse BSDF 1/Pi cancels with correction factor for Monte Carlo Pi
	    res += intersect.Color*intersect.Ell;
	}
      res *= 1.0f/sampleCount;
      
      return res;
    }
  }
}
