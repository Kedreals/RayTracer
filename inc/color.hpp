#ifndef _COLOR_HPP_
#define _COLOR_HPP_

#include <iostream>

namespace ray_tracer
{
  namespace light
  {
    /** \brief a simple struct containing the basic color interactions
     */
    struct Color
    {
    private:
      float m_r,m_g,m_b;
    public:
      Color(float r = 0.0f, float g = 0.0f, float b = 0.0f);
      Color(unsigned char r, unsigned char g, unsigned char b);
      Color(const Color& other);
      ~Color();

      float GetR() const;
      float GetG() const;
      float GetB() const;

      void SetR(float r);
      void SetG(float g);
      void SetB(float b);

      Color operator *(float rhs) const;
      Color& operator *=(float rhs);

      Color operator +(float rhs) const;
      Color& operator +=(float rhs);

      Color operator +(const Color& rhs) const;
      Color& operator +=(const Color& rhs);

      Color operator *(const Color& rhs) const;
      Color& operator *=(const Color& rhs);
    };

    Color operator +(float lhs, const Color& rhs);
    Color operator *(float lhs, const Color& rhs);
    std::ostream& operator <<(std::ostream& lhs, const Color& rhs);
  }
}

#endif //_COLOR_HPP_
