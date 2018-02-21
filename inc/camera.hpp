#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "color.hpp"
#include "ray.hpp"

namespace ray_tracer
{
  namespace core
  {
    struct Camera
    {
    private:
      unsigned int m_width, m_height;
      float m_fov;
      light::Color* m_Image;

    public:
      Camera(unsigned int width = 512, unsigned int height = 512, float fov = 45.0f*3.14159265f / 180.0f);
      //Camera(unsigned int width, unsigned int height, float fov, Vec3f pos, Vec3f up, Vec3f eye);
      Camera(const Camera&) = delete;
      ~Camera();

      Ray GenerateRay(unsigned int pixel_x, unsigned int pixel_y) const;
      void SetPixel(unsigned int x, unsigned int y, const light::Color& value);
      light::Color GetPixel(unsigned int x, unsigned int y) const;
      float GetFov() const;
    };
  }
}

#endif //_CAMERA_HPP_
