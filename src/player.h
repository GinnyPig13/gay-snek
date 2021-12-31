#pragma once

#include "vector2D.h"
#include "follow.h"

namespace KCC
{
    class player
    {
    public:
        void draw();
        void update(int keyPress);

        inline const vector2D& getPosition() const { return currentPosition; }
        void setPosition(int x, int y);

        void addFollower();
        void removeAllFollewers();

    private:
        vector2D currentPosition;
        std::vector<follow*> followers;
    };
}
