#include "collectable.h"

#include "ofGraphics.h"
#include "ofMath.h"
#include "colors.h"

void KCC::collectable::setup(int size, const vector2D* playerPosition)
{
    this->size = size;
    this->playerPosition = playerPosition;

    if(playerPosition)
    {
        randomizePosition();
    }
}

void KCC::collectable::randomizePosition()
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
    ofSetColor(KCC::colors::deepChampagneOrange);
    ofDrawRectangle(position.x * size, position.y * size, size, size);
}
