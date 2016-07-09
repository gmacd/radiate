#pragma once

namespace radiate {
	class Vec4
	{
	public:
		Vec4(): Vec4(0, 0, 0, 1) {}
		Vec4(float x, float y, float z, float w = 1.0f) {
			this->x = x;  this->y = y;  this->z = z;  this->w = w;
		}

		float r() const { return x; }
		float g() const { return y; }
		float b() const { return z; }
		float a() const { return w; }

		float x, y, z, w;
	};
}
