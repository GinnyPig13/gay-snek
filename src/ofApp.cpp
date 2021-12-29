#include "ofApp.h"

#include "vector2D.h"
#include "colors.h"

namespace
{
    void loadTitleFont(ofTrueTypeFont& font);
    void drawTitle(const ofTrueTypeFont& font);

    bool hasCollectedCollectable(const KCC::collectable& collectable, const vector2D& player);
    bool hasCollidedWithBorder(const vector2D& player);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(KCC::colors::richBlack);
    loadTitleFont(titleFont);

    // Create a dynamically proportional window one third the size of the screen
    int length = 0.3 * ofGetScreenWidth();
    // Create variables to force the window to be centered dynamically
    int centerWidth = (ofGetScreenWidth()/2) - (length/2);
    int centerHeight = (ofGetScreenHeight()/2) - (length/2);
    ofSetWindowShape(length, length);
    ofSetWindowPosition(centerWidth, centerHeight);

    squareSize = ofGetWindowHeight()/gridSize;
	centerWindowWidth = (ofGetWindowWidth()/2) - (squareSize/2);
    centerWindowHeight = (ofGetWindowHeight()/2) - (squareSize/2);

    ofSetFrameRate(5);

    resetState();
}

//--------------------------------------------------------------
void ofApp::update(){
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

    if(hasCollectedCollectable(collectable, currentPosition))
    {
        collectable.randomizePosition();
    }

    if(hasCollidedWithBorder(currentPosition))
    {
        resetState();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawTitle(titleFont);

    collectable.draw();

    //Create a character square
    ofSetColor(KCC::colors::lightPinkRed);
    ofDrawRectangle(currentPosition.x * squareSize, currentPosition.y * squareSize, squareSize, squareSize);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT ||
        key == OF_KEY_RIGHT ||
        key == OF_KEY_DOWN ||
        key == OF_KEY_UP)
    {
        keyPress = key;
    }
}

void ofApp::resetState()
{
    currentPosition.x = gridCenter;
    currentPosition.y = gridCenter;

    collectable.setup(&currentPosition);

    keyPress = -1;
}

namespace
{
    void loadTitleFont(ofTrueTypeFont& font)
    {
        // Scale font size by width
        constexpr float defaultWidth = 1980.0f;
        constexpr int defaultFontSize = 50;
        const float fontScalar = ofGetScreenWidth() / defaultWidth;
        font.load("Cinderheart.otf", defaultFontSize * fontScalar);
    }

    void drawTitle(const ofTrueTypeFont& font)
    {
        const std::string title = "GAY SNEK";
        const float titleWidth = font.stringWidth(title);
        const float titleHeight = font.stringHeight(title);

        const float centerWindow = ofGetWidth() / 2.0f;
        const float centerTitle = titleWidth / 2.0f;

        ofSetColor(KCC::colors::babyPowderWhite);
        font.drawString(title, centerWindow - centerTitle, titleHeight);
    }

    bool hasCollectedCollectable(const KCC::collectable& collectable, const vector2D& player)
    {
        const vector2D& collectablePosition = collectable.getPosition();
        return collectablePosition.x == player.x && collectablePosition.y == player.y;
    }

    bool hasCollidedWithBorder(const vector2D& player)
    {
        if(player.x < 0 || player.x >= ofApp::gridSize)
        {
            return true;
        }

        if(player.y < 0 || player.y >= ofApp::gridSize)
        {
            return true;
        }

        return false;
    }
}
