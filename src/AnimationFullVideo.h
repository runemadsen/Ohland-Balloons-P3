#pragma once

#include "AnimationFull.h"
#include "ofxMidi.h"

#define MARGIN 20

class AnimationFullVideo : public AnimationFull
{
public:
    
	AnimationFullVideo(string videoName);
	
    void update();
	void draw();
	void wasSelected();
	void wasDeselected();
	
	void destroy();
	
private:
	
	ofVideoPlayer _vid;
	
	bool _shouldPlay;
	bool _shouldStop;
};


