#include <cstdio>

#include "core/debug.hpp"
#include "core/image.hpp"
#include "core/intersect.hpp"
#include "core/ray.hpp"
#include "core/vec4.hpp"

//using namespace radiate;
using namespace gmlib;


Vec4 colour(const Ray& r) {
    auto s = Sphere(Point4(0, 0, -1), 0.5f);
    float t = intersectRaySphere(s, r);
    if (t > 0) {
        auto normal = r.point(t) - s.centre();
        normal.normalize();
        return 0.5f * (normal + Vec4::One);
    }

    // Miss, so render pretty blue gradient background
    auto dir = r.dir().normal();
    t = 0.5f * (dir.y + 1.0f);
    return (1.0f-t)*Vec4::One + t*Vec4(0.5, 0.7, 1);
}


int main()
{
    registerSignalHandlers();

	printf("radiate\n");

    Vec4 viewLowerLeftCorner(-2, -1, -1);
    Vec4 viewSize(4, 2, 0);
    Point4 origin(0, 0, 0);

    int w = 200, h = 100;
    Image img(w, h);
    for (auto y = 0; y < h; y++)
    {
        for (auto x = 0; x < w; x++)
        {
            Vec4 uv(float(x) / float(w), float(y) / float(h), 0);

            Ray ray(origin, viewLowerLeftCorner + uv*viewSize);
            img.set(x, y, colour(ray));
        }
    }
    
    img.writePng("out.png");

	return 0;
}
