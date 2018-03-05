#include "model.hpp"

using namespace ray_tracer::core;

namespace ray_tracer
{
  namespace geometry
  {
    Model::Model() : m_Size(0), m_Count(0), m_Triangles(nullptr)
    {
    }

    Model::Model(int num, Triangle* triangles) : m_Size(num), m_Count(num), m_Triangles(triangles)
    {
    }

    Model::~Model()
    {
      if(m_Triangles)
	{
	  free(m_Triangles);
	  m_Triangles = nullptr;
	}
    }


    
    void Model::Add(const Triangle& triangle)
    {
      if(m_Count + 1 <= m_Size)
	{
	  m_Triangles[m_Count++] = triangle;
	}
      else
	{
	  Resize();
	  m_Triangles[m_Count++] = triangle;
	}
    }

    void Model::Add(int num, const Triangle* triangles)
    {
      if(m_Count + num <= m_Size)
	{
	  for(int i = 0; i < num; ++i)
	    {
	      m_Triangles[m_Count++] = triangles[i];
	    }
	}
      else
	{
	  Resize(num);
	  Add(num, triangles);
	}
    }

    bool Model::Intersect(Ray& ray, Intersection& intersection) const
    {
      bool res = false;
      for(int i = 0; i < m_Count; ++i)
	res |= m_Triangles[i].Intersect(ray, intersection);
      return res;
    }

    void Model::Resize(int addition)
    {
      if(m_Count + addition >= m_Size)
	m_Size *= 2;
      else if(m_Count + addition < m_Size/2)
	m_Size /= 2;
      else
	return;
      
      Triangle* nt = (Triangle*)malloc(m_Size*sizeof(Triangle));
      for(int i = 0; i < m_Count && i < m_Size; ++i)
	nt[i] = m_Triangles[i];
      free(m_Triangles);
      m_Triangles = nt;
    }
    
  }
}
