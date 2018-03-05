#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "triangle.hpp"

/** \brief all structs, functions and namingspacese of the project are contained here
 */
namespace ray_tracer
{
  /** \brief the most essential structs and function are contained in here
   */ 
  namespace core
  {
    /** \brief simple class containing all triangles

	\todo fix model and use the model instead of triangles
     */
    struct Scene
    {
    public:
      /** \brief default ctor
	  
	  currently builds an test scene
	  \todo implement a way to load a scene
       */
      Scene();
      /** \brief simple dtor
       */
      ~Scene();

      /** \brief checks if the ray intersects any triangle in the scene

	  informations about the intersection are safed in \a intersection also \a ray is updated with its t value.
       */
      bool Intersect(Ray& ray, Intersection& intersection) const;
    private:
      Scene(const Scene&) = delete;
      
      int m_Size, m_Count;
      geometry::Triangle* m_Triangles;
    };
  }
}

#endif
