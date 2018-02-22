#include "image.hpp"
#include "fileWriter.hpp"
#include <cmath>

using namespace ray_tracer::light;

namespace ray_tracer
{
  namespace core
  {
    Image::Image(unsigned int width, unsigned int height) : m_width(width), m_height(height), m_index_highest(0), m_highest(0)
    {
      m_data = new Color[width*height];
    }

    Image::~Image()
    {
      if(m_data)
	{
	  delete[] m_data;
	  m_data = nullptr;
	}
    }

    const Color& Image::GetPixel(unsigned int x, unsigned int y) const
    {
      return m_data[y*m_width + x];
    }

    void SearchHighest(Color* arr, unsigned int size, float* res, unsigned int* res_index)
    {
      float r = 0;
      int index = 0;
      for(unsigned int i = 0; i < size; ++i)
	{
	  if(arr[i].GetR() > r)
	    {
	      r = arr[i].GetR();
	      index = i;
	    }

	  if(arr[i].GetG() > r)
	    {
	      r = arr[i].GetG();
	      index = i;
	    }

	  if(arr[i].GetB() >r)
	    {
	      r = arr[i].GetB();
	      index = i;
	    }
	}

      *res = r;
      *res_index = index;
    }
    
    void Image::SetPixel(unsigned int x, unsigned int y, const Color& value)
    {
      if(y>= m_height || x >= m_width)
	return;

      bool wasSet = false;
      
      if(value.GetR() > m_highest){
	m_highest = value.GetR();
	m_index_highest = y*m_width+x;
	wasSet = true;
      }

      if(value.GetG() > m_highest){
	m_highest = value.GetG();
	m_index_highest = y*m_width+x;
	wasSet = true;
      }

      if(value.GetB() > m_highest){
	m_highest = value.GetB();
	m_index_highest = y*m_width+x;
	wasSet = true;
      }
      
      m_data[y*m_width + x] = value;
      if(y*m_width + x == m_index_highest && !wasSet)
	{
	  SearchHighest(m_data, m_width*m_height, &m_highest, &m_index_highest);
	}
    }

    inline Color Colorlog(const Color& c)
    {
      return Color(log(c.GetR()+1), log(c.GetG() + 1), log(c.GetB() + 1));
    }
    
    Color* ScaleLog(const Color* input, unsigned int size, float highest)
    {
      Color* res = new Color[size];
      highest = log(highest+1);
      
      for(unsigned int i = 0; i < size; ++i)
	{
	  res[i] = Colorlog(input[i])* (1.0f / highest);
	}
      
      return res;
    }
    
    void Image::Save(const std::string& fileName) const
    {
      std::string ending = fileName.substr(fileName.find("."));
      Color* scaledImage = ScaleLog(m_data, m_width*m_height, m_highest);

      if(ending == ".ppm")
	SavePPM(m_data, m_width, m_height, fileName);

      delete[] scaledImage;
    }
  }
}
