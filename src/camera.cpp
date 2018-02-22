#include "camera.hpp"
#include <cmath>
#include <iostream>

namespace ray_tracer
{
  namespace core
  {
    using namespace math;
    using namespace light;
    
    Camera::Camera(unsigned int width, unsigned int height, float fov) : m_width(width), m_height(height), m_fov(fov), m_Image(width, height)
    {
    }

    Camera::~Camera()
    {
    }

    Ray Camera::GenerateRay(unsigned int pixel_x, unsigned int pixel_y) const
    {
      Vec3f o(0.0f, 0.0f, 0.0f);

      float step = (2*m_fov)/(float)m_width;
      float x = -m_fov + ((float)pixel_x + 0.5f) * step;
      step = step*(float)m_width /(float)m_height;
      float y = -m_fov + ((float)pixel_y + 0.5f) * step;

      Vec3f d(sin(x)*cos(y), sin(y), cos(x)*cos(y));
      return Ray(o, d);
    }

    void Camera::SetPixel(unsigned int x, unsigned int y, const Color& value)
    {
      m_Image.SetPixel(x, y, value);
    }

    const Color& Camera::GetPixel(unsigned int x, unsigned int y) const
    {
      return m_Image.GetPixel(x, y);
    }

    float Camera::GetFov() const
    {
      return m_fov*180.0f / PI;
    }

    const Image& Camera::GetImage() const
    {
      return m_Image;
    }
    
    void Camera::SaveImage(const std::string& fileName) const
    {
      m_Image.Save(fileName);
    }
  }
}
