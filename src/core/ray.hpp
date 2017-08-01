#pragma once

#include "vec4.hpp"

namespace gmlib {
	
	class Ray
	{
	public:
		Ray() {}
		Ray(const Point4& origin, const Vec4& dir): _origin(origin), _dir(dir) {}

		Point4 point(float t) const { return _origin + t*_dir; }

		const Point4& origin() const { return _origin; }
		const Vec4& dir() const { return _dir; }

	private:
		Point4 _origin;
		Vec4 _dir;
	};
}
