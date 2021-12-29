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
	virtual void setup() override;
	virtual void update() override;
	virtual void draw() override;

	virtual void keyPressed(int key) override;

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
