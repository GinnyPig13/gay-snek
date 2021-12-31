#include "colors.h"
#include "ofGraphics.h"
#include "follow.h"

ofColor KCC::colors::getColor (int followerCount)
{ 
    int colorNumber = 8;
    if (followerCount % colorNumber == 0)
    {
        return lightPinkRed;
    }

    if (followerCount % colorNumber == 1)
    {
        return deepChampagneOrange;
    }

    if (followerCount % colorNumber == 2)
    {
        return lemonCremeYellow;
    }

    if (followerCount % colorNumber == 3)
    {
        return teaGreen;
    }

    if (followerCount % colorNumber == 4)
    {
        return celesteLightBlue;
    }

    if (followerCount % colorNumber == 5)
    {
        return babyEyesBlue;
    }

    if (followerCount % colorNumber == 6)
    {
        return maximumBluePurple;
    }

    if (followerCount % colorNumber == 7)
    {
        return mauvePink;
    }

    else 
    {
        return babyPowderWhite;
    }
}