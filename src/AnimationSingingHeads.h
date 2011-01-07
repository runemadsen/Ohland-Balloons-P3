#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerHead.h"

class AnimationSingingHeads : public Animation
{
public:
    
	AnimationSingingHeads(int frameBlinkEnd, int frameCloseStart, string videoName);
	
    void update();
	void draw();
	void wasSelected();
	void wasDeselected();
	void destroy();
	
	BalloonController * getNewController(Balloon * model);
	
private:
	
	int _frameBlinkEnd;
	int _frameCloseStart;
	string _videoName;

};


