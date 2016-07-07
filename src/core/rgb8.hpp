#pragma once

#include <cstdint>
#include "vec4.hpp"


namespace radiate {

    // Unsigned 8-bit RGB
    class Rgb8
    {
    public:
        Rgb8(): Rgb8(0, 0, 0) {}
        Rgb8(uint8_t r, uint8_t g, uint8_t b): r(r), g(g), b(b) {}

        Rgb8(const Vec4& c):
            r((uint8_t)(c.r * 255)),
            g((uint8_t)(c.g * 255)),
            b((uint8_t)(c.b * 255))
        {}

        Rgb8& operator=(const Vec4& rhs)
        {
            r = (uint8_t)(rhs.r * 255);
            g = (uint8_t)(rhs.g * 255);
            b = (uint8_t)(rhs.b * 255);
            return *this;
        }

        uint8_t r, g, b;
    };
}
