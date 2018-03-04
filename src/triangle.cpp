#include "triangle.hpp"
#include <iostream>
#include <cmath>

using namespace ray_tracer::math;
using namespace ray_tracer::core;
using namespace ray_tracer::light;

namespace ray_tracer
{
  namespace geometry
  {
    Triangle::Triangle(const Vec3f& a, const Vec3f& b, const Vec3f& c, float ell) : Triangle(a, b, c, Color(1.0f, 1.0f, 1.0f), ell)
    {
    }

    Triangle::Triangle(const Vec3f& a, const Vec3f& b, const Vec3f& c, const Color& color, float ell) : m_ell(ell), m_a(a), m_b(b), m_c(c), m_color(color)
    {
      m_ell /= Area();
    }

    Triangle::Triangle(const Triangle& other) : m_a(other.m_a), m_b(other.m_b), m_c(other.m_c)
    {
    }

    Triangle::~Triangle()
    {
    }

    bool Triangle::Intersect(Ray& ray) const
    {
      Vec3f n = (m_b-m_a).Cross(m_c - m_a);
      float pn = m_a.Dot(n);
      float t = (-ray.O().Dot(n) + pn)/(ray.D().Dot(n));

      if(t < 0 || t >= ray.T())
	return false;

      float u, v, w;
      
      Vec3f p = ray(t);
      float abc = n.Norm();

      Vec3f e1 = m_a-m_c;
      Vec3f e2 = p-m_c;

      Vec3f c = e1.Cross(e2);
      u = (n.Dot(c)/fabs(n.Dot(c)))*c.Norm() / abc;

      e1 = m_b - m_a;
      e2 = p - m_a;

      c = e1.Cross(e2);
      v = (n.Dot(c)/fabs(n.Dot(c)))*c.Norm() / abc;

      e1 = m_c - m_b;
      e2 = p - m_b;

      c = e1.Cross(e2);
      w = (n.Dot(c)/fabs(n.Dot(c)))*c.Norm() / abc;

      if(u < 0 || v < 0 || w < 0)
	return false;

      ray.SetT(t);
      
      return true;
    }

    float Triangle::Area() const
    {
      return (m_b-m_a).Cross(m_c-m_a).Length()/2.0f;
    }

    const Color& Triangle::GetColor() const
    {
      return m_color;
    }

    float Triangle::GetEll() const
    {
      return m_ell;
    }

    Vec3f Triangle::GetNormal() const
    {
      Vec3f n = (m_b-m_a).Cross(m_c-m_a);
      return n / n.Length();
    }
  }
}
