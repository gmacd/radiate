#pragma once

#include "core/ray.hpp"
#include "core/vec4.hpp"
#include "intersect.hpp"

namespace gmlib {

	class Obj {
	public:
		virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& hit) const = 0;
	};


	class SphereObj: public Obj {
	public:
		SphereObj(const Point4& centre, float radius): _sphere(centre, radius) {}
		SphereObj(const Sphere& s): _sphere(s) {}

		virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& hit) const;

		const Sphere& sphere() const { return _sphere; }
		const Point4& centre() const { return _sphere.centre(); }
		float radius() const { return _sphere.radius(); }

	private:
		Sphere _sphere;
	};
}
