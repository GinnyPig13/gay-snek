#pragma once

#include "vector2D.h"

namespace KCC
{
    class collectable
    {
    public:
        void setup(const vector2D* playerPosition);
        void draw();

        void randomizePosition();
        inline const vector2D& getPosition() const { return position; }

    private:
        vector2D position;
        const vector2D* playerPosition;
    };
}
