#pragma once

namespace radiate {
	class Vec4
	{
	public:
		Vec4(): Vec4(0, 0, 0, 1) {}
		Vec4(float x, float y, float z, float w = 1.0f) { v[0] = x;  v[1] = y;  v[2] = z;  v[3] = w; }

		union {
			float v[4];
			float x, y, z, w;
			float r, g, b, a;
		};
	};
}
