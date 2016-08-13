#include <cstdio>
#include <limits>

#include "core/debug.hpp"
#include "core/image.hpp"
#include "core/ray.hpp"
#include "core/vec4.hpp"
#include "obj/obj.hpp"
#include "obj/intersect.hpp"
#include "obj/scene.hpp"

//using namespace radiate;
using namespace gmlib;


Vec4 colour(const Ray& r, const Scene& scene) {
	HitRecord hit;
	if (scene.hit(r, 0, std::numeric_limits<float>::max(), hit))
	{
		return 0.5f * (hit._normal + Vec4::One);
	}
	else
	{
		// Miss, so render pretty blue gradient background
	    auto dir = r.dir().normal();
	    auto t = 0.5f * (dir.y + 1.0f);
	    return (1.0f-t)*Vec4::One + t*Vec4(0.5, 0.7, 1);
	}
}


int main()
{
    registerSignalHandlers();

	printf("radiate\n");
	
	Scene scene; 
	scene.add(new SphereObj(Point4(0, 0, -1), 0.5));
	scene.add(new SphereObj(Point4(0, -100.5, -1), 100));

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
            img.set(x, y, colour(ray, scene));
        }
    }
    
    img.writePng("out.png");

	return 0;
}
