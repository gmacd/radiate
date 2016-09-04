#include <cstdio>
#include <limits>
#include <iostream>

#include "core/camera.hpp"
#include "core/debug.hpp"
#include "core/image.hpp"
#include "core/ray.hpp"
#include "core/rnd.hpp"
#include "core/timer.hpp"
#include "core/vec4.hpp"
#include "obj/obj.hpp"
#include "obj/intersect.hpp"
#include "obj/scene.hpp"

using namespace std;
using namespace gmlib;

Vec4 fireRay(const Ray& r, const Scene& scene, Rnd& rnd)
{
	HitRecord hit;
	if (scene.hit(r, 0.001f, numeric_limits<float>::max(), hit))
	{
		auto target = hit._point + hit._normal + rnd.nextVecInUnitSphere();
		return 0.5f * fireRay(Ray(hit._point, target-hit._point), scene, rnd);
	}
	else
	{
		// Miss, so render pretty blue gradient background
	    auto dir = r.dir().normal();
	    auto t = 0.5f * (dir.y + 1.0f);
	    return (1.0f-t)*Vec4::One + t*Vec4(0.5f, 0.7f, 1.0f);
	}
}


int main()
{
    registerSignalHandlers();

	printf("radiate\n");
	
	Scene scene; 
	scene.add(new SphereObj(Point4(0, 0, -1), 0.5));
	scene.add(new SphereObj(Point4(0, -100.5, -1), 100));

	Camera camera;

	int w = 800, h = 400;
    Image img(w, h);

	Rnd rnd;
	Timer timer;

    for (auto y = 0; y < h; y++)
    {
        for (auto x = 0; x < w; x++)
        {
			// Anti-alias
			Vec4 colour;
			const int numSamples = 50;
			for (int s = 0; s < numSamples; s++)
			{
				float u = float(x + rnd.nextFloat()) / float(w);
				float v = float(y + rnd.nextFloat()) / float(h);

				Ray ray = camera.generateRay(u, v);

				colour += fireRay(ray, scene, rnd);
			}
			colour /= float(numSamples);

			// Gamma correct - gamma 2
			colour = colour.sqrt();

			// TODO Simplify y when camera is improved
            img.set(x, h-y-1, colour);
        }
    }

	timer.update();

	printf("Completed in %fs\n", timer.totalElapsed());
    
    img.writePng("out.png");

	cin.ignore();

	return 0;
}
