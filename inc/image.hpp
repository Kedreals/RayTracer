#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include "color.hpp"
#include <string>

namespace ray_tracer
{
  namespace core
  {
    /** \brief simple class containing a way to scale the raw data to fit in 0 to 1
     */
    struct Image
    {
    private:
      unsigned int m_width, m_height, m_index_highest;
      float m_highest;
      light::Color* m_data;

    public:
      /** \brief simple ctor
       */
      Image(unsigned int width, unsigned int height);
      /** \brief copying an image is expensive therefore it is prohibited
       */
      Image(const Image&) = delete;
      /** \brief simple dtor
       */
      ~Image();

      /** \brief return the Color value of the specified pixel
       */
      const light::Color& GetPixel(unsigned int x, unsigned int y) const;
      /** \brief sets the specified pixel
       */
      void SetPixel(unsigned int x, unsigned int y, const light::Color& value);

      /** \brief tries to save the image to the given fileName

	  only .ppm is supported as of now
       */
      void Save(const std::string& fileName) const;
    };
  }
}
#endif
