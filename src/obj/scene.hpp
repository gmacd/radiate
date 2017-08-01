#pragma once

#include <vector>

namespace gmlib {

	class Obj;
	class Ray;
	class HitRecord;

	class Scene
	{
	public:
		Scene() {}
		
		void add(Obj* obj);
		
		virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& hit) const;
		
	private:
		std::vector<Obj*> _objs;
	};
}
