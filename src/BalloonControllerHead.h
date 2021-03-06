#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "ofxAlphaVideoPlayer.h"

class BalloonControllerHead : public BalloonController
{
	
public:
	
	BalloonControllerHead(Balloon * model, int frameBlinkEnd, int frameCloseStart, string videoName);
	
	void update();
	void draw();
	void reset();
	void destroy();
	
	void noteOn();
	void noteOff();
	
private:
	
	ofxAlphaVideoPlayer head;
	//ofVideoPlayer head;
	
	int _headState; // 1 = blinking, 2 = opening, 3 = closing
	bool _newState;
	
	int _frameBlinkEnd;
	int _frameCloseStart;	
};