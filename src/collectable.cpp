#include "collectable.h"

#include "ofApp.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "colors.h"
#include "player.h"

void KCC::collectable::setup(const player* pPlayer)
{
    this->pPlayer = pPlayer;
    if(pPlayer)
    {
        randomizePosition();
    }
}

void KCC::collectable::randomizePosition()
{
    if(pPlayer)
    {
        int randomX = 0;
        int randomY = 0;
        do
        {
            randomX = static_cast<int>(ofRandom(ofApp::gridSize));
            randomY = static_cast<int>(ofRandom(ofApp::gridSize));
        } while (pPlayer->hasPosition(randomX, randomY));


        position.x = randomX;
        position.y = randomY;
    }
}

void KCC::collectable::draw()
{
    ofSetColor(KCC::colors::deepChampagneOrange);

    static const int gridUnit = ofGetWindowWidth() / ofApp::gridSize;
    ofDrawRectangle(position.x * gridUnit, position.y * gridUnit, gridUnit, gridUnit);
}
