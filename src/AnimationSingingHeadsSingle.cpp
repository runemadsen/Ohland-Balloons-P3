#include "AnimationSingingHeadsSingle.h"

/* Constructor
 ___________________________________________________________ */

AnimationSingingHeadsSingle::AnimationSingingHeadsSingle(int frameBlinkEnd, int frameCloseStart, string videoName)
{
	_frameBlinkEnd = frameBlinkEnd;
	_frameCloseStart = frameCloseStart;
	
	head.loadMovie(videoName);
	
	_headState = 1;
	
	head.play();
	head.setFrame(ofRandom(1, _frameBlinkEnd - 1));
}

/* Update
 ___________________________________________________________ */

void AnimationSingingHeadsSingle::update()
{	
	if(_headState == 1)
	{
		if(_newState)
		{
			head.firstFrame();
		}
		else if (head.getCurrentFrame() > _frameBlinkEnd)
		{
			head.firstFrame();
		}
	}
	else if(_headState == 2)
	{
		if(_newState)
		{
			head.setFrame(_frameBlinkEnd);
		}
		else if(head.getCurrentFrame() >= _frameCloseStart)
		{
			head.setFrame(_frameCloseStart);
		}
	}
	else if(_headState == 3)
	{
		if(head.getCurrentFrame() == head.getTotalNumFrames())
		{
			_headState = 1;
		}
	}
	
	head.idleMovie();
	
	_newState = false;
	
}

/* Draw
 ___________________________________________________________ */

void AnimationSingingHeadsSingle::draw()
{
	for (int i = 0; i < _points.size(); i++) 
	{
		ofFill();
		ofSetColor(0, 0, 0, 255);
		ofEllipse(_points[i]->getCenterX(), _points[i]->getCenterY(), _points[i]->getWidth(), _points[i]->getHeight());
		
		ofRectangle bounds = _points[i]->getBoundsFromSize(head.getWidth(), head.getHeight());
		
		if(_useOffset)
		{
			bounds.y += _offSet;
		}
		
		ofSetColor(255, 255, 255);
		ofEnableAlphaBlending();
		
		head.draw(bounds.x, bounds.y, bounds.width, bounds.height);
		ofDisableAlphaBlending();
	}
	
}

/* MIDI
 ___________________________________________________________ */

void AnimationSingingHeadsSingle::newMidiMessage(ofxMidiEventArgs& eventArgs)
{
	if(eventArgs.byteOne == _midiNote)
	{
		if(eventArgs.status == MIDI_NOTE_ON)
		{
			noteOn();
		}
		else if(eventArgs.status == MIDI_NOTE_OFF)
		{
			noteOff();
		}
		else 
		{
			printf("ERROR: Midi message neither on or off");
		}
	}
}

void AnimationSingingHeadsSingle::noteOn()
{
	_headState = 2;
	_newState = true;
}

void AnimationSingingHeadsSingle::noteOff()
{
	_headState = 3;
	_newState = true;
}

/* Overrides
___________________________________________________________ */

void AnimationSingingHeadsSingle::wasSelected()
{
	
}

void AnimationSingingHeadsSingle::wasDeselected()
{
	_headState = 1;
}

void AnimationSingingHeadsSingle::allOn()
{
	noteOn();
}

void AnimationSingingHeadsSingle::allOff()
{
	noteOff();
}

/* Destroy
 ___________________________________________________________ */

void AnimationSingingHeadsSingle::destroy()
{
	head.closeMovie();
}



