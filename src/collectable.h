#pragma once

#include "vector2D.h"

namespace KCC
{
    class player;
    class collectable
    {
    public:
        void setup(const player* pPlayer);
        void draw();

        void randomizePosition();
        inline const vector2D& getPosition() const { return position; }

    private:
        vector2D position;
        const player* pPlayer;
    };
}
