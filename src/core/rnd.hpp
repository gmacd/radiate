#pragma once

#include <random>

#include "vec4.hpp"

namespace gmlib {
	
	class Rnd
	{
	public:
		Rnd();

		float nextFloat();
		float nextFloat(float scale);

		Vec4 nextVecInUnitCube();
		Vec4 nextVecInUnitSphere();

	private:
		std::random_device _device;
		std::ranlux48_base _rnd;
	};
}
