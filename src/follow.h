#pragma once

#include "vector2D.h"
#include "ofGraphics.h"

namespace KCC
{
    class follow
    {
    public:
        follow(int x, int y, int followCount);

        void draw();
        void update(const vector2D& previousPosition);

        inline const vector2D& getPosition() const { return followPosition; }

    private:
        vector2D followPosition;
        ofColor color;
    };
}
