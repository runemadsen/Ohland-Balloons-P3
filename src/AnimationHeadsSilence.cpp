#include "AnimationHeadsSilence.h"

/* Constructor
 ___________________________________________________________ */

AnimationHeadsSilence::AnimationHeadsSilence()
{
	_usingControllers = true;
	
	_videoNames.push_back("silenceheads/black_small.mov");
	_videoNames.push_back("silenceheads/blue_small.mov");
	_videoNames.push_back("silenceheads/red_small.mov");
	_videoNames.push_back("silenceheads/yellow_small.mov");
	
	// first balloon reacts to midi note 60, next 61, etc...
	/*_midiNotes.push_back(60);
	_midiNotes.push_back(61);
	_midiNotes.push_back(62);
	_midiNotes.push_back(63);
	_midiNotes.push_back(64);
	_midiNotes.push_back(65);
	_midiNotes.push_back(67);
	_midiNotes.push_back(69);
	_midiNotes.push_back(71);
	_midiNotes.push_back(72);
	_midiNotes.push_back(74);*/
}

/* Update
 ___________________________________________________________ */

void AnimationHeadsSilence::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationHeadsSilence::draw()
{
	ofSetColor(255, 255, 255);
	
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
}

void AnimationHeadsSilence::wasSelected()
{
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->noteOn();
	}
}

void AnimationHeadsSilence::wasDeselected()
{
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->reset();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationHeadsSilence::getNewController(Balloon * model)
{		
	int modulo = _controllers.size() % _videoNames.size();
	
	BalloonControllerHeadSilence * b = new BalloonControllerHeadSilence(_videoNames[modulo], model);
	b->setUseOffset(_useOffset);
	b->setOffset(_offSet);
	return b;
}

void AnimationHeadsSilence::newMidiMessage(ofxMidiEventArgs& eventArgs)
{

}

/* Destroy
 ___________________________________________________________ */

void AnimationHeadsSilence::destroy()
{	
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



