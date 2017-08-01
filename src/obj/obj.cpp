#include "obj.hpp"

#include "intersect.hpp"

namespace gmlib {

	bool SphereObj::hit(const Ray& r, float tMin, float tMax, HitRecord& hit) const
	{
		return intersectRaySphere(_sphere, r, tMin, tMax, hit);
	}

}
