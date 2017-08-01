#pragma once

#include <vector>
#include "vec4.hpp"
#include "ray.hpp"


namespace gmlib {

	class Camera
	{
	public:
		Camera();

		Ray generateRay(float u, float v) const;

	private:
		Point4 _origin;
		Point4 _lowerLeftCorner;
		Vec4 _widthVec;
		Vec4 _heightVec;
	};
}
