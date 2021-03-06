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
        void removeAllFollowers();

        bool hasCollidedWithSelf() const;
        bool hasPosition(int x, int y) const;

    private:
        vector2D currentPosition;
        std::vector<follow*> followers;
    };
}
