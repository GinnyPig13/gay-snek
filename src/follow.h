#pragma once

#include "vector2D.h"
#include "ofGraphics.h"

namespace KCC
{
    class follow
    {
    public:
        void draw();
        void update(const vector2D& previousPosition);

    private:
        vector2D followPosition;
        ofColor color;
    };
}
