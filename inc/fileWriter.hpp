#ifndef _FILE_WRITER_HPP_
#define _FILE_WRITER_HPP_

#include "color.hpp"
#include <string>

namespace ray_tracer
{
  namespace core
  {
    /** \brief saves the given array in the .ppm format
     */
    void SavePPM(const light::Color* image, unsigned int width, unsigned int height, const std::string& fileName);
  }
}

#endif //_FILE_WRITER_HPP_
