#ifndef _MODEL_HPP_
#define _MODEL_HPP_

#include "triangle.hpp"

namespace ray_tracer
{
  namespace geometry
  {
    /** \brief simple model class
	
	\bug doesn't render correctly
     */
    struct Model
    {
    public:
      Model();
      Model(int num, Triangle* triangles);
      ~Model();

      void Add(const Triangle& triangle);
      void Add(int num, const Triangle* triangles);

      bool Intersect(core::Ray& ray, core::Intersection& i) const;
      
    private:
      Model(const Model&) = delete;
      void Resize(int addition = 1);
      
      int m_Size, m_Count;
      Triangle* m_Triangles;
      
    };
  }
}
#endif
