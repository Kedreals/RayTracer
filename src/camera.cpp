#include "camera.hpp"
#include <cmath>

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

    float GenerateOffset(int max_multisampling, int step, bool xDir)
    {
      int count = (int)sqrt(max_multisampling);
      float width = 1.0f / (count + 1.0f);
      
      if(xDir)
	{
	  return (1 + (step % count))*width;
	}
      else
	{
	  return (1+(step / count))*width;
	}
    }
    
    Ray Camera::GenerateRay(unsigned int pixel_x, unsigned int pixel_y, int max_multisampling, int multisampling_step) const
    {
      Vec3f o(0.0f, 0.0f, 0.0f);

      float xmax = tan(m_fov);
      float step = 2.0f*xmax/(float)m_width;

      //generate x offset for the sampling step
      float r = GenerateOffset(max_multisampling, multisampling_step, true);
      
      float x = -xmax + ((float)pixel_x + r) * step;

      //generate y offset for the sampling step
      r = GenerateOffset(max_multisampling, multisampling_step, false);

      step = step*(float)m_width /(float)m_height;
      float y = -xmax + ((float)pixel_y + r) * step;

      Vec3f d(x, y, 1);
      d /= d.Length();
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
