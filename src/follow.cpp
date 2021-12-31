#include "follow.h"

#include "colors.h"
#include "ofApp.h"
#include "ofGraphics.h"

KCC::follow::follow(int x, int y, int followerCount)
{
    followPosition.x = x;
    followPosition.y = y;
    color = colors::getColor(followerCount);
}

void KCC::follow::draw()
{
    ofSetColor(color);

    static const int gridUnit = ofGetWindowWidth() / ofApp::gridSize;
    ofDrawRectangle(followPosition.x * gridUnit, followPosition.y * gridUnit, gridUnit, gridUnit);
}

void KCC::follow::update(const vector2D& previousPosition)
{
    followPosition.x = previousPosition.x;
    followPosition.y = previousPosition.y;
}
