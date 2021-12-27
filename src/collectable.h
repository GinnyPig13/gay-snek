#pragma once

#include "vector2D.h"

namespace KCC
{
    class collectable
    {
    public:
        void draw(int size);

        inline void setPlayerPosition(vector2D* playerPosition) { this->playerPosition = playerPosition; }
        void randomizePosition(int size);

    private:
        vector2D position;
        vector2D* playerPosition;
    };
}
