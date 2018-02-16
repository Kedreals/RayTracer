#include "vec3.hpp"
#include <cmath>

using namespace ray_tracer::math;

Vec3f::Vec3f(): this(0.0f, 0.0f, 0.0f)
{
}

Vec3f::Vec3f(float x, float y, float z) : m_X(x), m_Y(y), m_Z(z)
{
}

Vec3f::Vec3f(const Vec3f& other) : m_X(other.m_X), m_Y(other.m_Y), m_Z(other.m_Z)
{
}

Vec3f::~Vec3f()
{
}

float Vec3f::X() const
{
  return m_X;
}

float Vec3f::Y() const
{
  return m_Y;
}

float Vec3f::Z() const
{
  return m_Z;
}

void Vec3f::X(float x)
{
  m_X = x;
}

void Vec3f::Y(float y)
{
  m_Y = y;
}

void Vec3f::Z(float z)
{
  m_Z = z;
}

float Vec3f::operator [](int i) const
{
  if(i == 0)
    return m_X;
  else if(i == 1)
    return m_Y;
  else if(i == 2)
    return m_Z;
  else
    throw 1;
}

float& Vec3f::operator [](int i)
{
  if(i == 0)
    return m_X;
  else if(i == 1)
    return m_Y;
  else if(i == 2)
    return m_Z;
  else
    throw 1;
}

Vec3f Vec3f::operator -() const
{
  return *this * -1.0f;
}

Vec3f Vec3f::operator +(const Vec3f& other) const
{
  return Vec3f(m_X+other[0], m_Y+other[1], m_Z+other[2]);
}

Vec3f& Vec3f::operator +=(const Vec3f& other)
{
  m_X += other[0];
  m_Y += other[1];
  m_Z += other[2];
  return *this;
}

Vec3f Vec3f::operator *(float other) const
{
  return Vec3f(m_X*other, m_Y*other, m_Z*other);
}

Vec3f& Vec3f::operator *=(float other)
{
  m_X *= other;
  m_Y *= other;
  m_Z *= other;
  return *this;
}

Vec3f Vec3f::operator -(const Vec3f& other) const
{
  return Vec3f(m_X-other[0], m_Y-other[1], m_Z-other[2]);
}

Vec3f& Vec3f::operator -=(const Vec3f& other)
{
  m_X -= other[0];
  m_Y -= other[1];
  m_Z -= other[2];
  return *this;
}

Vec3f Vec3f::operator /(float other) const
{
  return Vec3f(m_X/other, m_Y/other, m_Z/other);
}

Vec3f Vec3f::operator /=(float other)
{
  m_X /= other;
  m_Y /= other;
  m_Z /= other;
  return *this;
}

float Vec3f::Norm() const
{
  return sqrt(this->Norm2());
}

float Vec3f::Norm2() const
{
  return this->Dot(*this);
}

float Vec3f::Dot(const Vec3f& other) const
{
  return m_X*other[0] + m_Y*other[1] + m_Z*other[2];
}

Vec3f Vec3f::Cross(const Vec3f& other) const
{
  float x = m_Y*other[2] - m_Z*other[1];
  float y = m_Z*other[0] - m_X*other[2];
  float z = m_X*other[1] - m_Y*other[0];
  return Vec3f(x, y, z);
}

Vec3f operator *(float lhs, const Vec3f& rhs)
{
  return rhs * lhs;
}

Matrix3x3::Matrix3x3(float a00, float a01, float a02,
		     float a10, float a11, float a12,
		     float a20, float a21, float a22) : r0(a00, a01, a02), r1(a10, a11, a12), r(a20, a21, a22)
{
}

Matrix3x3::Matrix3x3(const Vec3f& row0, const Vec3f& row1, const Vec3f& row2) : r0(row0), r1(row1), r2(row2)
{
}

Matrix3x3::Matrix3x3(const Matrix3x3& other) : r0(other.r0), r1(other.r1), r2(other.r2)
{
}

Matrix3x3::~Matrix3x3()
{
}

const Vec3f& Matrix3x3::operator [](int i) const
{
  if(i == 0)
    return r0;
  else if(i == 1)
    return r1;
  else if(i == 2)
    return r2;
  else
    throw 1;
}

Vec3f& Matrix3x3::operator [](int i)
{
  if(i == 0)
    return r0;
  else if(i == 1)
    return r1;
  else if(i == 2)
    return r2;
  else
    throw 1;
}

float Matrix3x3::operator [](int i, int j) const
{
  return this->[i][j];
}

float& Matrix3x3::operator [](int i, int j)
{
  return this->[i][j];
}

Matrix3x3 Matrix3x3::operator +(const Matrix3x3& other) const
{
  return Matrix3x3(r0+other.r0, r1+other.r1, r2+other.r2);
}

Matrix3x3& Matrix3x3::operator +=(const Matrix3x3& other)
{
  r0 += other.r0;
  r1 += other.r1;
  r2 += other.r2;
  return *this;
}

Matrix3x3 Matrix3x3::operator -(const Matrix3x3& other) const
{
  return Matrix3x3(-r0, -r1, -r2);
}

Matrix3x3& Matrix3x3::operator -=(const Matrix3x3& other)
{
  r0 -= other.r0;
  r1 -= other.r1;
  r2 -= other.r2;
  return *this;
}

Matrix3x3 Matrix3x3::operator -() const
{
  return Matrix3x3(-r0, -r1, -r2);
}

Matrix3x3 Matrix3x3::operator *(const Matrix3x3& other) const
{
  return Matrix3x3(r0[0]*other[0,0]+r0[1]*other[1,0]+r0[2]*other[2,0],
		   r0[0]*other[0,1]+r0[1]*other[1,1]+r0[2]*other[2,1],
		   r0[0]*other[0,2]+r0[1]*other[1,2]+r0[2]*other[2,2],
		   r1[0]*other[0,0]+r1[1]*other[1,0]+r1[2]*other[2,0],
		   r1[0]*other[0,1]+r1[1]*other[1,1]+r1[2]*other[2,1],
		   r1[0]*other[0,2]+r1[1]*other[1,2]+r1[2]*other[2,2],
		   r2[0]*other[0,0]+r2[1]*other[1,0]+r2[2]*other[2,0],
		   r2[0]*other[0,1]+r2[1]*other[1,1]+r2[2]*other[2,1],
		   r2[0]*other[0,2]+r2[1]*other[1,2]+r2[2]*other[2,2]);
}

Matrix3x3& Matrix3x3::operator *=(const Matrix3x3& other)
{
  auto o = other.Transpose();
  auto row0 = r0;
  auto row1 = r1;
  auto row2 = r2;

  r0[0] = row0.Dot(o[0]);
  r0[1] = row0.Dot(o[1]);
  r0[2] = row0.Dot(o[2]);

  r1[0] = row1.Dot(o[0]);
  r1[1] = row1.Dot(o[1]);
  r1[2] = row1.Dot(o[2]);

  r2[0] = row2.Dot(o[0]);
  r2[1] = row2.Dot(o[1]);
  r2[2] = row2.Dot(o[2]);

  return *this;
}

