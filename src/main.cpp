#include <cstdio>

#include "core/debug.hpp"
#include "core/image.hpp"
#include "core/vec4.hpp"

//using namespace radiate;
using namespace gmlib;

int main()
{
    csRegisterSignalHandlers();

	printf("radiate\n");

    Image img(640, 480);
    for (auto y = 0; y < img.Height(); y++)
    {
        for (auto x = 0; x < img.Width(); x++)
        {
            img.Set(x, y, Vec4(1, 1, 0));
        }
    }
    
    img.WritePng("out.png");

	return 0;
}
