#pragma once

#include "vector2D.h"

namespace KCC
{
    class player
    {
    public:
        void draw();
        void update(int keyPress);

        inline const vector2D& getPosition() const { return currentPosition; }
        void setPosition(int x, int y);
        
    private:
        vector2D currentPosition;
    };
}