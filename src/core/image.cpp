#include "image.hpp"

#include <vector>
#include "rgb8.hpp"

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#ifdef _MSC_VER
#pragma warning(default:4996)
#endif

namespace gmlib {

    Image::Image(int w, int h):
        _w(w), _h(h), _pixels(w*h, Vec4())
    {
    }

    void Image::set(int x, int y, const Vec4& colour)
    {
        _pixels[x + y*_w] = colour;
    }

    void Image::writePng(const char* path)
    {
        // Convert to bytes
        std::vector<Rgb8> buf(_w*_h);
        for (auto i = 0; i < _w*_h; i++)
        {
            buf[i] = _pixels[i];
        }
        
        stbi_write_png(path, _w, _h, 3, buf.data(), 3*_w);
    }
}
