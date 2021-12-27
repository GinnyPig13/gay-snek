#include "collectable.h"

#include "ofGraphics.h"
#include "ofMath.h"

void KCC::collectable::randomizePosition(int size)
{
    if(playerPosition)
    {
        int randomX = 0;
        int randomY = 0;
        do
        {
            randomX = static_cast<int>(ofRandom(size));
            randomY = static_cast<int>(ofRandom(size));
        } while (randomX == playerPosition->x && randomY == playerPosition->y);

        position.x = randomX;
        position.y = randomY;
    }
}

void KCC::collectable::draw(int size)
{
    ofSetColor(255, 214, 165);
    ofDrawRectangle(position.x * size, position.y * size, size, size);
}
