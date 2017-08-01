#include "intersect.hpp"

namespace gmlib {

	bool intersectRaySphere(const Sphere& s, const Ray& r, float tMin, float tMax, HitRecord& hit)
	{
		Vec4 oc = r.origin() - s.centre();
		float a = dot(r.dir(), r.dir());
		float b = dot(oc, r.dir());
		float c = dot(oc, oc) - s.radius()*s.radius();
		float discriminant = b*b - a*c;
		if (discriminant > 0)
		{
			float sqrtDisc = std::sqrt(discriminant); 
			float t = (-b - sqrtDisc) / a;
			if (t < tMax && t > tMin)
			{
				auto pt = r.point(t);
				hit = HitRecord(pt, (pt-s.centre()) / s.radius(), t);
				return true;
			}

			t = (-b + sqrtDisc) / a;
			if (t < tMax && t > tMin)
			{
				auto pt = r.point(t);
				hit = HitRecord(pt, (pt-s.centre()) / s.radius(), t);
				return true;
			}
		}

		return false;
	}
}
