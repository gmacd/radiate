#pragma once

#include <cmath>

namespace gmlib {
	
	class Vec4
	{
	public:
		static Vec4 Zero;
		static Vec4 One;

		Vec4() : Vec4(0, 0, 0, 0) {}
		Vec4(const Vec4& v) : Vec4(v.x, v.y, v.z, v.w) {}
		Vec4(float x, float y, float z, float w = 0.0f) : x(x), y(y), z(z), w(w) {}

		//float dot(const Vec4& v) const { return x*v.x + y*v.y + z*v.z + w*v.w; }
		float length() const { return std::sqrt(dot(*this, *this)); }
		float sqLength() const { return dot(*this, *this); }

		float normalize() { float len = length();  x/=len;  y/=len;  z/=len;  w/=len;  return len; }
		Vec4 normal() const { float len = length();  return Vec4(x/len, y/len, z/len, w/len); }

		Vec4 sqrt() const { return Vec4(std::sqrt(x), std::sqrt(y), std::sqrt(z), 0); }

		Vec4 operator-() const { return Vec4(x, y, z, w); }

		Vec4 operator+=(float s) { x += s;  y += s;  z += s;  w += s;  return *this; }
		Vec4 operator-=(float s) { x -= s;  y -= s;  z -= s;  w -= s;  return *this; }
		Vec4 operator*=(float s) { x *= s;  y *= s;  z *= s;  w *= s;  return *this; }
		Vec4 operator/=(float s) { x /= s;  y /= s;  z /= s;  w /= s;  return *this; }

		Vec4 operator+=(const Vec4& v) { x += v.x;  y += v.y;  z += v.z;  w += v.w;  return *this; }
		Vec4 operator-=(const Vec4& v) { x -= v.x;  y -= v.y;  z -= v.z;  w -= v.w;  return *this; }
		Vec4 operator*=(const Vec4& v) { x *= v.x;  y *= v.y;  z *= v.z;  w *= v.w;  return *this; }
		Vec4 operator/=(const Vec4& v) { x /= v.x;  y /= v.y;  z /= v.z;  w /= v.w;  return *this; }

		friend Vec4 operator+(const Vec4& v1, const Vec4& v2) { return Vec4(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z, v1.w+v2.w); }
		friend Vec4 operator-(const Vec4& v1, const Vec4& v2) { return Vec4(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z, v1.w-v2.w); }
		friend Vec4 operator*(const Vec4& v1, const Vec4& v2) { return Vec4(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z, v1.w*v2.w); }
		friend Vec4 operator/(const Vec4& v1, const Vec4& v2) { return Vec4(v1.x/v2.x, v1.y/v2.y, v1.z/v2.z, v1.w/v2.w); }

		friend Vec4 operator+(const Vec4& v, float s) { return Vec4(v.x+s, v.y+s, v.z+s, v.w+s); }
		friend Vec4 operator-(const Vec4& v, float s) { return Vec4(v.x-s, v.y-s, v.z-s, v.w-s); }
		friend Vec4 operator*(const Vec4& v, float s) { return Vec4(v.x*s, v.y*s, v.z*s, v.w*s); }
		friend Vec4 operator/(const Vec4& v, float s) { return Vec4(v.x/s, v.y/s, v.z/s, v.w/s); }

		friend Vec4 operator+(float s, const Vec4& v) { return Vec4(s+v.x, s+v.y, s+v.z, s+v.w); }
		friend Vec4 operator-(float s, const Vec4& v) { return Vec4(s-v.x, s-v.y, s-v.z, s-v.w); }
		friend Vec4 operator*(float s, const Vec4& v) { return Vec4(s*v.x, s*v.y, s*v.z, s*v.w); }
		friend Vec4 operator/(float s, const Vec4& v) { return Vec4(s/v.x, s/v.y, s/v.z, s/v.w); }

		friend float dot(const Vec4& v1, const Vec4& v2) { return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w; }

		union { float x, r; };
		union { float y, g; };
		union { float z, b; };
		union { float w, a; };
	};

	class Point4
	{
	public:
		Point4(): Point4(0, 0, 0) {}
		Point4(const Point4& p): Point4(p.x, p.y, p.z) {}
		Point4(float x, float y, float z): x(x), y(y), z(z), w(1) {}

		friend Vec4 operator-(const Point4& p1, const Point4& p2) { return Vec4(p1.x-p2.x, p1.y-p2.y, p1.z-p2.z); }

		friend Point4 operator+(const Point4& p, const Vec4& v) { return Point4(p.x+v.x, p.y+v.y, p.z+v.z); }
		friend Point4 operator-(const Point4& p, const Vec4& v) { return Point4(p.x-v.x, p.y-v.y, p.z-v.z); }


		float x, y, z, w;
	};
}
