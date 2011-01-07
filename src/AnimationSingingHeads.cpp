#include "AnimationSingingHeads.h"

/* Constructor
 ___________________________________________________________ */

AnimationSingingHeads::AnimationSingingHeads(int frameBlinkEnd, int frameCloseStart, string videoName)
{
	_usingControllers = true;
	
	_frameBlinkEnd = frameBlinkEnd;
	_frameCloseStart = frameCloseStart;
	_videoName = videoName;
	
	// first balloon reacts to midi note 60, next 61, etc...
	_midiNotes.push_back(60);
	_midiNotes.push_back(61);
	_midiNotes.push_back(62);
	_midiNotes.push_back(63);
	_midiNotes.push_back(64);
	_midiNotes.push_back(65);
	_midiNotes.push_back(67);
	_midiNotes.push_back(69);
	_midiNotes.push_back(71);
	_midiNotes.push_back(72);
	_midiNotes.push_back(74);
}

/* Update
 ___________________________________________________________ */

void AnimationSingingHeads::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationSingingHeads::draw()
{
	ofSetColor(255, 255, 255);
	
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationSingingHeads::getNewController(Balloon * model)
{		
	BalloonControllerHead * b = new BalloonControllerHead(model, _frameBlinkEnd, _frameCloseStart, _videoName);
	return b;
}

void AnimationSingingHeads::wasSelected()
{
	
}

void AnimationSingingHeads::wasDeselected()
{
	
}

/* Destroy
 ___________________________________________________________ */

void AnimationSingingHeads::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



