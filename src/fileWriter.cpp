#include "fileWriter.hpp"
#include <fstream>

using namespace ray_tracer::light;

namespace ray_tracer
{
  namespace core
  {
    void SavePPM(const Color* image, unsigned int width, unsigned int height, const std::string& fileName)
    {
      std::ofstream file(fileName);

      file << "P3\n" << width << " " << height << "\n" << 255 << "\n";

      for(unsigned int y = 0; y < height; ++y)
	{
	  for(unsigned int x = 0; x<width; ++x)
	    {
	      Color c = image[y*width + x];
	      file << (int)(c.GetR()*255) << " " << (int)(c.GetG()*255) << " " << (int)(c.GetB()*255) << "   ";
	    }
	  file << "\n";
	}
      
      file.close();
    }
  }
}
