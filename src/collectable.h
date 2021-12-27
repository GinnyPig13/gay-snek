#pragma once

#include "vector2D.h"

namespace KCC
{
    class collectable
    {
    public:
        void setup(int size, const vector2D* playerPosition);
        void draw(int size);

        void randomizePosition();
        inline const vector2D& getPosition() { return position; }

    private:
        vector2D position;
        const vector2D* playerPosition;

        int size;
    };
}
