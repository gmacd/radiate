#pragma once

#include "core/primitives.hpp"
#include "core/ray.hpp"
#include "core/vec4.hpp"

namespace gmlib {
	
	class HitRecord
	{
	public:
		HitRecord(): _point(), _normal(), _t(0) {}

		HitRecord(const Point4& point, const Vec4& normal, float t):
			_point(point), _normal(normal), _t(t) {}

		HitRecord(const HitRecord& hit):
			_point(hit._point), _normal(hit._normal), _t(hit._t) {}

		Point4 _point;
		Vec4 _normal;
		float _t;
	};


	bool intersectRaySphere(const Sphere& s, const Ray& r, float tMin, float tMax, HitRecord& hit);
}
