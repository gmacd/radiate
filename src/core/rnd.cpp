#include "rnd.hpp"

using namespace std;

namespace gmlib {

	// TODO Replace with fast rnd gen after investigation
	Rnd::Rnd():
		_device(),
		_rnd(_device())
    {
	}

	float Rnd::nextFloat()
	{
		return generate_canonical<float, 10>(_rnd);
	}

	float Rnd::nextFloat(float scale)
	{
		return nextFloat()*scale;
	}

	Vec4 Rnd::nextVecInUnitCube()
	{
		return Vec4(nextFloat(2.0f), nextFloat(2.0f), nextFloat(2.0f)) - Vec4::One;
	}

	Vec4 Rnd::nextVecInUnitSphere()
	{
		while (true)
		{
			auto v = nextVecInUnitCube();
			if (v.sqLength() < 1.0f)
				return v;
		}
	}
}
