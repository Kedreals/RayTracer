#ifndef _VEC_HPP_
#define _VEC_HPP_

namespace ray_tracer
{
  namespace math
  {
    #define PI 3.14159265f

    /** \brief simple 3d Vector
     */
    struct Vec3f
    {
    private:
      float m_X, m_Y, m_Z;
      
    public:
      /** \brief default constructor
       */
      Vec3f();
      /** \brief constructor
       */
      Vec3f(float x, float y, float z);
      /** \brief copy ctor
       */
      Vec3f(const Vec3f& other);
      /** \brief default dtor
       */
      ~Vec3f();

      /** \brief getter for x component
       */
      float X() const;
      /** \brief getter for y component
       */
      float Y() const;
      /** \brief getter for z component
       */
      float Z() const;

      /** \brief setter for x component
       */
      void X(float x);
      /** \brief setter for y component
       */
      void Y(float y);
      /** \brief setter for z component
       */
      void Z(float z);

      /** \brief access operator
       */
      float operator [](int i) const;
      /** \brief access operator
       */
      float& operator [](int i);

      /** \brief simple multiplication by -1
       */
      Vec3f operator -() const;
      
      /** \brief add to vectors componentwise
       */
      Vec3f operator +(const Vec3f& other) const;
      /** \brief add another Vector to this
       */
      Vec3f& operator +=(const Vec3f& other);

      /** \brief scale by a scalar 
       */
      Vec3f operator *(float other) const;
      /** \brief scale and override
       */
      Vec3f& operator *=(float other);

      /** \brief substract to vectors
       */
      Vec3f operator -(const Vec3f& other) const;
      /** \brief substract and override
       */
      Vec3f& operator -=(const Vec3f& other);

      /** \brief divide by scalar
       */
      Vec3f operator /(float other) const;
      /** \brief divide and override
       */
      Vec3f& operator /=(float other);

      /** \brief length of the vector
       */
      float Norm() const;
      /** \brief sqaured length of the vector
       */
      float Norm2() const;

      /** \brief dot product of 2 Vectors
       */
      float Dot(const Vec3f& other) const;
      /** \brief cross product of 2 Vectors
       */
      Vec3f Cross(const Vec3f& other) const;
    };

    /** \brief scale the Vector
     */
    Vec3f operator *(float lhs, const Vec3f& rhs);

    /** \brief simple 3x3 Matrix
     */
    struct Matrix3x3
    {
    private:
      Vec3f r0, r1, r2;
    public:
      /** \brief simple ctor
       */
      Matrix3x3(float a00 = 0.0f, float a01 = 0.0f, float a02 = 0.0f,
		float a10 = 0.0f, float a11 = 0.0f, float a12 = 0.0f,
		float a20 = 0.0f, float a21 = 0.0f, float a22 = 0.0f);
      /** \brief ctor where the rows are specified
       */
      Matrix3x3(const Vec3f& row0, const Vec3f& row1, const Vec3f& row2);
      /** \brief copy ctor
       */
      Matrix3x3(const Matrix3x3& other);
      /** \brief simple dtor
       */
      ~Matrix3x3();

      /** \brief getter for the rows
       */
      const Vec3f& operator [](int i) const;
      /** \brief setter for the rows
       */
      Vec3f& operator [](int i);

      /** \brief getter for a specific element
       */
      float GetValue(int i, int j) const;
      /** \brief setter for a specific element
       */
      void SetValue(float value, int i, int j);

      /** \brief simple addidtion of matrices
       */
      Matrix3x3 operator +(const Matrix3x3& other) const;
      /** \brief addidtion and overriding
       */
      Matrix3x3& operator +=(const Matrix3x3& other);

      /** \brief substraction
       */
      Matrix3x3 operator -(const Matrix3x3& other) const;
      /** \brief substraction and overriding
       */
      Matrix3x3& operator -=(const Matrix3x3& other);

      /** \brief component wise multiply by -1
       */
      Matrix3x3 operator -() const;

      /** \brief matrix multiplication
       */
      Matrix3x3 operator *(const Matrix3x3& other) const;
      /** \brief multiplication and overriding
       */
      Matrix3x3& operator *=(const Matrix3x3& other);

      /** \brief Matrix Vector multiplication
       */
      Vec3f operator *(const Vec3f& other) const;

      /** \brief component wise multiply by scalar
       */
      Matrix3x3 operator *(float other) const;
      /** \brief component wise multiply and override
       */
      Matrix3x3& operator *=(float other);

      /** \brief divide component wise by a scalar
       */
      Matrix3x3 operator /(float other) const;
      /** \brief divide and override
       */
      Matrix3x3& operator /=(float other);

      /** \brief computes the determinant
       */
      float Det() const;

      /** \brief returns transposed matrix
       */
      Matrix3x3 Transpose() const;
      /** \brief transpose this matrix
       */
      Matrix3x3& TransposeThis();
    };

    /** \brief scale by scalar
     */
    Matrix3x3 operator *(float lhs, const Matrix3x3& rhs);
    /** \brief interpret the vector as row and then do matrix vector multiplication
     */
    Vec3f operator *(const Vec3f& lhs, const Matrix3x3& rhs);
    /** \brief interpret the vector as row and do matrix vector multiplication
     */
    Vec3f& operator *=(Vec3f& lhs, const Matrix3x3& rhs);
  }
}

#endif //_VEC_HPP_
