#include "scene.hpp"

#include "core/ray.hpp"
#include "obj/obj.hpp"
#include "obj/intersect.hpp"

namespace gmlib {

	void Scene::add(Obj* obj)
	{
		_objs.push_back(obj);
	}

	bool Scene::hit(const Ray& ray, float tMin, float tMax, HitRecord& hit) const
	{
		HitRecord currHit;
		bool anythingHit = false;
		auto nearestT = tMax;
		for (auto&& shape: _objs)
		{
			if (shape->hit(ray, tMin, nearestT, currHit))
			{
				anythingHit = true;
				nearestT = currHit._t;
				hit = currHit;
			}
		}
		return anythingHit;
	}
}
