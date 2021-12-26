#include "ofApp.h"

namespace
{
    void loadTitleFont(ofTrueTypeFont& font);
    void drawTitle(const ofTrueTypeFont& font);
}

//--------------------------------------------------------------
void ofApp::setup(){
    // Create a dynamically proportional window one third the size of the screen
    int length;
    length = 0.3 * ofGetScreenWidth();
    // Create variables to force the window to be centered dynamically
    int centerWidth;
    centerWidth = (ofGetScreenWidth()/2) - (length/2);
    int centerHeight;
    centerHeight = (ofGetScreenHeight()/2) - (length/2);
    ofSetWindowShape(length, length);
    ofSetWindowPosition(centerWidth, centerHeight);

    loadTitleFont(titleFont);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawTitle(titleFont);

    //Create a character square
    int squareSize;
    squareSize = ofGetWindowHeight()/25;
    int centerWindowWidth;
    centerWindowWidth = ofGetWindowWidth()/2 - squareSize;
    int centerWindowHeight;
    centerWindowHeight = ofGetWindowHeight()/2 - squareSize;
    ofSetColor(255, 173, 173);
    ofDrawRectangle(centerWindowWidth, centerWindowHeight, squareSize, squareSize);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

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
        
        ofSetColor(255, 255, 252);
        font.drawString(title, centerWindow - centerTitle, titleHeight);
    }
}
