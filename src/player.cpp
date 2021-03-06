#include "player.h"

#include "vector2D.h"
#include "colors.h"
#include "ofApp.h"
#include "ofGraphics.h"

void KCC::player::update(int keyPress)
{
    vector2D previousPosition = currentPosition;

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

    vector2D previousFollowPosition;
    for(follow* follower : followers)
    {
        previousFollowPosition = follower->getPosition();
        follower->update(previousPosition);
        previousPosition = previousFollowPosition;
    }
}

void KCC::player::draw()
{
    ofSetColor(KCC::colors::lightPinkRed);

    static const int gridUnit = ofGetWindowWidth() / ofApp::gridSize;
    ofDrawRectangle(currentPosition.x * gridUnit, currentPosition.y * gridUnit, gridUnit, gridUnit);

    for(follow* follower : followers)
    {
        follower->draw();
    }
}

void KCC::player::addFollower()
{
    followers.push_back(new follow(currentPosition.x, currentPosition.y, followers.size() + 1));
}

void KCC::player::removeAllFollowers()
{
    for(follow* follower : followers)
    {
        delete follower;
    }

    followers.clear();
}

bool KCC::player::hasCollidedWithSelf() const
{
    return hasPosition(currentPosition.x, currentPosition.y);
}

bool KCC::player::hasPosition(int x, int y) const
{
    for(follow* follower : followers)
    {
        const vector2D& followerPosition = follower->getPosition();
        if(followerPosition.x == x && followerPosition.y == y)
        {
            return true;
        }
    }

    return false;
}

void KCC::player::setPosition(int x, int y)
{
    currentPosition.x = x;
    currentPosition.y = y;
}
