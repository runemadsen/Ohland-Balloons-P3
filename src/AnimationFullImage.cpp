#include "AnimationFullImage.h"

/* Constructor
 ___________________________________________________________ */

AnimationFullImage::AnimationFullImage(string imgName)
{
	_useEasing = true;
	_useMidi = true;
	_nodeOffAlpha = 100;
	_curAlpha = _nodeOffAlpha;
	
	_img.loadImage(imgName);
	
	_useMask = false;
	
	_timer.setDuration(20);
	
	_midiNote = 61;
}

/* Update
 ___________________________________________________________ */

void AnimationFullImage::update()
{
	if (_useEasing) 
	{
		_timer.tick();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationFullImage::draw()
{	
	if (_useEasing) 
	{
		_curAlpha = Quad::easeOut(_timer.getTime(), _nodeOffAlpha, 255, _timer.getDuration());
	}
	
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, _curAlpha);
	
	_img.draw(_bounds->x, _bounds->y, _bounds->width, _bounds->height);
	
	ofSetColor(255, 255, 255);
		
	if(_useMask)
	{
		_mask->draw(0, 0);
	}
	
	ofDisableAlphaBlending();
}

/* Was selected
 ___________________________________________________________ */

void AnimationFullImage::wasSelected()
{

}

/* On / Off for image (not using controllers)
 ___________________________________________________________ */

void AnimationFullImage::nodeOn()
{
	if(_useMidi)
	{
		if(_useEasing)
		{
			_timer.setState(1);
		}
		else 
		{
			_curAlpha = 255;
		}
	}
}

void AnimationFullImage::nodeOff()
{
	if(_useMidi)
	{
		if(_useEasing)
		{
			_timer.setState(-1);
		}
		else 
		{
			_curAlpha = _nodeOffAlpha;
		}
	}
}

void AnimationFullImage::allOn()
{
	nodeOn();
}

void AnimationFullImage::allOff()
{
	nodeOff();
}


/* Destroy
 ___________________________________________________________ */

void AnimationFullImage::destroy()
{	
	if(_img.getTextureReference().bAllocated())
	{
		_img.clear();
	}
}

/* MIDI
 ___________________________________________________________ */

void AnimationFullImage::newMidiMessage(ofxMidiEventArgs& eventArgs)
{
	if(_midiNote == eventArgs.byteOne)
	{
		if(eventArgs.status == MIDI_NOTE_ON)
		{
			nodeOn();
		}
		else if(eventArgs.status == MIDI_NOTE_OFF)
		{
			nodeOff();
		}
	}
}

/* Getter / Setter
 ___________________________________________________________ */

void AnimationFullImage::setUseEasing(bool useEasing) 
{ 
	_useEasing = useEasing; 
}

void AnimationFullImage::setNodeOffAlpha(int nodeOffAlpha) 
{ 
	_nodeOffAlpha = nodeOffAlpha;
	
	_curAlpha = _useMidi ? _nodeOffAlpha : _curAlpha;
}

void AnimationFullImage::setUseMidi(bool useMidi)
{
	_useMidi = useMidi;
	
	_useEasing = _useMidi ? _useEasing : false; // Bug: if you set usemidi on and off again, easing will go on no matter whether you set it off before
	_curAlpha = _useMidi ? _nodeOffAlpha : 255;
}

void AnimationFullImage::setMidiNote(int midiNote)
{
	_midiNote = midiNote;
}
