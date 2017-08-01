#pragma once

#include <vector>
#include "vec4.hpp"


namespace gmlib {

    class Image
    {
    public:
        Image(int w, int h);

        int width() const { return _w; }
        int height() const { return _h; }

        void set(int x, int y, const Vec4& colour);

        void writePng(const char* path);

    private:
        int _w, _h;
        std::vector<Vec4> _pixels;
    };
}
