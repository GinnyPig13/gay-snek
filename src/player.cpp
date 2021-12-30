#include "player.h"

#include "vector2D.h"
#include "colors.h"
#include "ofApp.h"
#include "ofGraphics.h"

void KCC::player::update(int keyPress)
{
        if (keyPress == OF_KEY_LEFT)
    {
        currentPosition.x = currentPosition.x - 1;
    }
    else if (keyPress == OF_KEY_RIGHT)
    {
        currentPosition.x = currentPosition.x + 1;
    }
    else if (keyPress == OF_KEY_UP)
    {
        currentPosition.y = currentPosition.y - 1;
    }
    else if (keyPress == OF_KEY_DOWN)
    {
        currentPosition.y = currentPosition.y + 1;
    }
}

void KCC::player::draw()
{
    ofSetColor(KCC::colors::lightPinkRed);

    static const int gridUnit = ofGetWindowWidth() / ofApp::gridSize;
    ofDrawRectangle(currentPosition.x * gridUnit, currentPosition.y * gridUnit, gridUnit, gridUnit);
}

void KCC::player::setPosition(int x, int y)
{
    currentPosition.x = x;
    currentPosition.y = y;
}