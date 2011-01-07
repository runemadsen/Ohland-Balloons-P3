#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "ofxAlphaVideoPlayer.h"

class BalloonControllerHeadSilence : public BalloonController
{
	
public:
	
	BalloonControllerHeadSilence(string videoname, Balloon * model);
	
	void update();
	void draw();
	void reset();
	void destroy();
	
	void noteOn();
	void noteOff();
	
private:
	
	ofxAlphaVideoPlayer head;
	
	bool _shouldPlay;
};