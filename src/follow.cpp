#include "follow.h"

#include "colors.h"
#include "ofApp.h"
#include "ofGraphics.h"

KCC::follow::follow(int x, int y)
{
    followPosition.x = x;
    followPosition.y = y;
}

void KCC::follow::draw()
{
    // TODO: Make colors cycle Virginia!

    ofSetColor(KCC::colors::babyPowderWhite);

    static const int gridUnit = ofGetWindowWidth() / ofApp::gridSize;
    ofDrawRectangle(followPosition.x * gridUnit, followPosition.y * gridUnit, gridUnit, gridUnit);
}

void KCC::follow::update(const vector2D& previousPosition)
{
    followPosition.x = previousPosition.x;
    followPosition.y = previousPosition.y;
}
