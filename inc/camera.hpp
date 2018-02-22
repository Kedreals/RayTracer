#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "image.hpp"
#include "ray.hpp"
#include <string>

namespace ray_tracer
{
  namespace core
  {
    /** \brief simple Camera class
     */
    struct Camera
    {
    private:
      unsigned int m_width, m_height;
      float m_fov;
      Image m_Image;

    public:
      /** \brief ctor
       */
      Camera(unsigned int width = 512, unsigned int height = 512, float fov = 45.0f*3.14159265f / 180.0f);
      //Camera(unsigned int width, unsigned int height, float fov, Vec3f pos, Vec3f up, Vec3f eye);
      /** \brief no camera should be copied.
       */
      Camera(const Camera&) = delete;
      ~Camera();

      /** \brief Generates a Ray through the middle of the specified pixel
       */
      Ray GenerateRay(unsigned int pixel_x, unsigned int pixel_y) const;
      /** \brief set the Color of the image at that pixel
       */
      void SetPixel(unsigned int x, unsigned int y, const light::Color& value);
      /** \brief returns the Color value of the specified pixel
       */
      const light::Color& GetPixel(unsigned int x, unsigned int y) const;
      /** \brief returns the fov in degree
       */
      float GetFov() const;

      /** \brief return the pointer to the image
       */
      const Image& GetImage() const;
      /** \brief tries to save the image to the given fileName

	  currently only implemented .ppm format
       */
      void SaveImage(const std::string& fileName) const;
    };
  }
}

#endif //_CAMERA_HPP_
