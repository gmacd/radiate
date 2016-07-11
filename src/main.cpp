#include <cstdio>

#include "core/debug.hpp"
#include "core/image.hpp"
#include "core/intersect.hpp"
#include "core/ray.hpp"
#include "core/vec4.hpp"

//using namespace radiate;
using namespace gmlib;


Vec4 colour(const Ray& r) {
    if (intersectRaySphere(Sphere(Point4(0, 0, -1), 0.5f), r))
        return Vec4(1, 0, 0);

    // Miss, so render pretty blue gradient background
    auto dir = r.dir().normal();
    auto t = 0.5f * (dir.y + 1.0f);
    return (1.0f-t)*Vec4(1, 1, 1) + t*Vec4(0.5, 0.7, 1);
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
