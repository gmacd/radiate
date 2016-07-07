#pragma once

#include <vector>
#include "vec4.hpp"


namespace radiate {

    class Image
    {
    public:
        Image(int w, int h);

        int Width() const { return _w; }
        int Height() const { return _h; }

        void Set(int x, int y, const Vec4& colour);

        void WritePng(const char* path);

    private:
        int _w, _h;
        std::vector<Vec4> _pixels;
    };
}
