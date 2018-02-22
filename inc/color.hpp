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
      /** \brief basic ctor, negative values are set to 0
       */
      Color(float r = 0.0f, float g = 0.0f, float b = 0.0f);
      /** \brief casts double to float then the default ctor
       */
      Color(double r, double g, double b);
      /** \brief takes the chars cast them to float and divide by 255 then the default ctor
       */
      Color(unsigned char r, unsigned char g, unsigned char b);
      /** \brief default copy ctor
       */
      Color(const Color& other);
      /** \brief default dtor
       */
      ~Color();

      /** \brief returns the R value
       */
      float GetR() const;
      /** \brief returns the G value
       */
      float GetG() const;
      /** \brief returns the B value
       */
      float GetB() const;

      /** \brief Sets the R value
       */
      void SetR(float r);
      /** \brief Sets the G value
       */
      void SetG(float g);
      /** \brief Sets the B value
       */
      void SetB(float b);

      /** \brief component wise multiplication
       */
      Color operator *(float rhs) const;
      /** \brief component wise multiplication
       */
      Color& operator *=(float rhs);

      /** \brief component wise addition
       */
      Color operator +(float rhs) const;
      /** \brief component wise addition
       */
      Color& operator +=(float rhs);

      /** \brief component wise addition
       */
      Color operator +(const Color& rhs) const;
      /** \brief component wise addition
       */
      Color& operator +=(const Color& rhs);

      /** \brief component wise multiplication
       */
      Color operator *(const Color& rhs) const;
      /** \brief component wise multiplication
       */
      Color& operator *=(const Color& rhs);
    };

    /** \brief component wise addition
     */
    Color operator +(float lhs, const Color& rhs);
    /** \brief component wise multiplication
     */
    Color operator *(float lhs, const Color& rhs);
    /** \brief debug output
     */
    std::ostream& operator <<(std::ostream& lhs, const Color& rhs);
  }
}

#endif //_COLOR_HPP_
