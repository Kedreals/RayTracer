#include "color.hpp"

using namespace ray_tracer::light;

Color::Color(float r, float g, float b) : m_r(r), m_g(g), m_b(b)
{
  if(m_r < 0)
    m_r = 0;

  if(m_g < 0)
    m_g = 0;

  if(m_b < 0)
    m_b = 0;
}

Color::Color(double r, double g, double b) : Color((float)r, (float)g, (float)b)
{
}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : Color((float)r/255.0f, (float)g/255.0f, (float)b/255.0f)
{
}

Color::Color(const Color& other) : m_r(other.m_r), m_g(other.m_g), m_b(other.m_b)
{
}

Color::~Color()
{
}

float Color::GetR() const
{
  return m_r;
}

float Color::GetG() const
{
  return m_g;
}

float Color::GetB() const
{
  return m_b;
}

void Color::SetR(float r)
{
  m_r = r;
}

void Color::SetG(float g)
{
  m_g = g;
}

void Color::SetB(float b)
{
  m_b = b;
}

Color Color::operator *(float rhs) const
{
  return Color(m_r*rhs, m_g*rhs, m_b*rhs);
}

Color& Color::operator *=(float rhs)
{
  m_r *= rhs;
  m_g *= rhs;
  m_b *= rhs;
  return *this;
}

Color Color::operator +(float rhs) const
{
  return Color(m_r+rhs, m_g+rhs, m_b+rhs);
}

Color& Color::operator +=(float rhs)
{
  m_r += rhs;
  m_g += rhs;
  m_b += rhs;
  return *this;
}

Color Color::operator +(const Color& rhs) const
{
  return Color(m_r + rhs.m_r, m_g + rhs.m_g, m_b + rhs.m_b);
}

Color& Color::operator +=(const Color& rhs)
{
  m_r += rhs.m_r;
  m_g += rhs.m_g;
  m_b += rhs.m_b;
  return *this;
}

Color Color::operator *(const Color& rhs) const
{
  return Color(m_r*rhs.m_r, m_g*rhs.m_g, m_b*rhs.m_b);
}

Color& Color::operator *=(const Color& rhs)
{
  m_r *= rhs.m_r;
  m_g *= rhs.m_g;
  m_b *= rhs.m_b;
  return *this;
}

Color ray_tracer::light::operator +(float lhs, const Color& rhs)
{
  return rhs+lhs;
}

Color ray_tracer::light::operator *(float lhs, const Color& rhs)
{
  return rhs*lhs;
}

std::ostream& ray_tracer::light::operator <<(std::ostream& lhs, const Color& rhs)
{
  return lhs << rhs.GetR() << ", " << rhs.GetG() << ", " << rhs.GetB() << ", ";
}
