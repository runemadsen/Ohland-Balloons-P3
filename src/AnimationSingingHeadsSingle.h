#pragma once

#include "Animation.h"
#include "ofxMidi.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "BalloonControllerHead.h"

class AnimationSingingHeadsSingle : public Animation
{
public:
    
	AnimationSingingHeadsSingle(int frameBlinkEnd, int frameCloseStart, string videoName);
	
    void update();
	void draw();
	void wasSelected();
	void wasDeselected();
	void destroy();
	
	void allOn();
	void allOff();
	
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	void setMidiNote(int midiNote) { _midiNote = midiNote; }
	
	void noteOn();
	void noteOff();
	
private:
	
	int _frameBlinkEnd;
	int _frameCloseStart;
	
	ofxAlphaVideoPlayer head;
	
	int _headState; // 1 = blinking, 2 = opening, 3 = closing
	bool _newState;
	
	int _midiNote;
};


