#include "scene.hpp"

using namespace ray_tracer::geometry;
using namespace ray_tracer::math;
using namespace ray_tracer::light;

namespace ray_tracer
{
  namespace core
  {
    Scene::Scene() : m_Size(12), m_Count(12), m_Triangles(nullptr)
    {
      m_Triangles = (Triangle*)malloc(m_Count*sizeof(Triangle));
      
      Vec3f mid(0, 0, 4);
      Vec3f xdim(5, 0, 0);
      Vec3f ydim(0, 5, 0);
      Vec3f zdim(0, 0, 5);

      //down left front
      Vec3f dlf = mid+ydim-xdim-zdim;
      //down right front
      Vec3f drf = mid+ydim+xdim-zdim;
      //down left back
      Vec3f dlb = mid+ydim-xdim+zdim;
      //down right back
      Vec3f drb = mid+ydim+xdim+zdim;

      //up left front
      Vec3f ulf = mid-ydim-xdim-zdim;
      //up right front
      Vec3f urf = mid-ydim+xdim-zdim;
      //up left back
      Vec3f ulb = mid-ydim-xdim+zdim;
      //up right back
      Vec3f urb = mid-ydim+xdim+zdim;


      //floor
      Color c(1.0f, 1.0f, 1.0f);
      float ell = 0;
      m_Triangles[0] = Triangle(dlf, drf, drb, c, ell);
      m_Triangles[1] = Triangle(dlf, drb, dlb, c, ell);

      //right Wall
      c = Color(1.0f, 0.2f, 0.2f);
      ell = 0;
      m_Triangles[2] = Triangle(drb, drf, urf, c, ell);
      m_Triangles[3] = Triangle(drb, urf, urb, c, ell);

      //left Wall
      c = Color(0.2f, 1.0f, 0.2f);
      ell = 0;
      m_Triangles[4] = Triangle(ulf, dlf, dlb, c, ell);
      m_Triangles[5] = Triangle(ulf, dlb, ulb, c, ell);

      //back Wall
      c = Color(1.0f, 1.0f, 1.0f);
      ell = 0;
      m_Triangles[6] = Triangle(dlb, drb, urb, c, ell);
      m_Triangles[7] = Triangle(dlb, urb, ulb, c, ell);

      //front Wall
      c = Color(1.0f, 1.0f, 1.0f);
      ell = 0;
      m_Triangles[8] = Triangle(urf, drf, dlf, c, ell);
      m_Triangles[9] = Triangle(urf, dlf, ulf, c, ell);

      //Ceiling
      c = Color(1.0f, 1.0f, 0.2f);
      ell = 100.0f;
      m_Triangles[10] = Triangle(urb, urf, ulf, c, ell);
      m_Triangles[11] = Triangle(urb, ulf, ulb, c, ell);
    }

    Scene::~Scene()
    {
      if(m_Triangles)
	{
	  free(m_Triangles);
	  m_Triangles = nullptr;
	}
    }

    bool Scene::Intersect(Ray& ray, Intersection& inters) const
    {
      bool res = false;
      for(int i = 0; i < m_Count; ++i)
	res |= m_Triangles[i].Intersect(ray, inters);
      return res;
    }
  }
}
