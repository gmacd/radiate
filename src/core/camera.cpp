#include "camera.hpp"


namespace gmlib {

	Camera::Camera():
		_origin(0, 0, 0),
		_lowerLeftCorner(-2, -1, -1),
		_widthVec(4, 0, 0),
		_heightVec(0, 2, 0)
	{
	}

	Ray Camera::generateRay(float u, float v) const
	{
		return Ray(_origin, _lowerLeftCorner + u*_widthVec + v*_heightVec - _origin);
	}
}
