#include "AnimationDogs.h"

/* Constructor
 ___________________________________________________________ */

AnimationDogs::AnimationDogs()
{
	_usingControllers = true;
	
	// save image names
	_imgNames.push_back("dog1");
	_imgNames.push_back("dog2");
	_imgNames.push_back("dog3");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog5");
	_imgNames.push_back("dog6");
	_imgNames.push_back("dog7");
	_imgNames.push_back("dog8");
	_imgNames.push_back("dog4");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	_imgNames.push_back("dog9");
	
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

void AnimationDogs::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationDogs::draw()
{
	ofSetColor(255, 255, 255);
	
	ofEnableAlphaBlending();
	
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
	
	ofDisableAlphaBlending();
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationDogs::getNewController(Balloon * model)
{		
	BalloonControllerDog * b = new BalloonControllerDog(model);
	
	if(_controllers.size() < _imgNames.size())
	{
		b->loadImage("dogs/" + _imgNames[_controllers.size()] + ".png");
	}
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationDogs::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



