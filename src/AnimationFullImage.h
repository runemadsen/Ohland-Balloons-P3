#pragma once

#include "AnimationFull.h"
#include "ofxMidi.h"
#include "Tools.h"
#include "Quad.h"

#define MARGIN 20

class AnimationFullImage : public AnimationFull
{
public:
    
	AnimationFullImage(string imgName);
	
    void update();
	void draw();
	void wasSelected();
	
	void destroy();
	
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	void nodeOn();
	void nodeOff();
	void allOn();
	void allOff();
	
	void setMidiNote(int midiNote);
	void setUseEasing(bool useEasing);
	void setNodeOffAlpha(int nodeOffAlpha);
	void setUseMidi(bool useMidi);
	
private:
	
	bool _useEasing;
	bool _useMidi;
	int _nodeOffAlpha;
	int _curAlpha;
	
	int _midiNote;
	
	PTimer _timer;
	ofImage _img;
};


