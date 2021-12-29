#pragma once

#include "ofMain.h"

#include "collectable.h"
#include "vector2D.h"

class ofApp : public ofBaseApp
{
public:
	static constexpr int gridSize = 25;
	static constexpr int gridCenter = gridSize / 2;

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	void resetState();

private:
	ofTrueTypeFont titleFont;
	int squareSize;
	int centerWindowWidth;
    int centerWindowHeight;

	vector2D currentPosition;
	int keyPress;

	KCC::collectable collectable;
};
