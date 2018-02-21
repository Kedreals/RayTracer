#include "camera.hpp"
#include <cmath>
#include <iostream>

namespace ray_tracer
{
  namespace core
  {
    using namespace math;
    using namespace light;
    
    Camera::Camera(unsigned int width, unsigned int height, float fov) : m_width(width), m_height(height), m_fov(fov)
    {
      m_Image = new Color[width*height];
    }

    Camera::~Camera()
    {
      if(m_Image)
	{
	  //delete m_Image;
	  m_Image = (Color*)nullptr;
	}
    }

    Ray Camera::GenerateRay(unsigned int pixel_x, unsigned int pixel_y) const
    {
      Vec3f o(0.0f, 0.0f, 0.0f);

      float step = (2*m_fov)/(float)m_width;
      float x = -m_fov + ((float)pixel_x + 0.5f) * step;
      step = step*(float)m_width /(float)m_height;
      float y = -m_fov + ((float)pixel_y + 0.5f) * step;

      Vec3f d(sin(y)*cos(x), sin(x), cos(y)*cos(x));
      return Ray(o, d);
    }

    void Camera::SetPixel(unsigned int x, unsigned int y, const Color& value)
    {
      m_Image[y*m_width+x] = value;
    }

    Color Camera::GetPixel(unsigned int x, unsigned int y) const
    {
      return m_Image[y*m_width + x];
    }

    float Camera::GetFov() const
    {
      return m_fov*180.0f / PI;
    }
  }
}
