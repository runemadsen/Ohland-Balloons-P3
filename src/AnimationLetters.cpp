#include "AnimationLetters.h"

/* Constructor
 ___________________________________________________________ */

AnimationLetters::AnimationLetters()
{
	_usingControllers = true;
	
	// you can put "empty" in the vector to not show an image on a balloon
	//_imgNames.push_back("empty");
	_imgNames.push_back("o");
	_imgNames.push_back("h");
	_imgNames.push_back("l");
	_imgNames.push_back("a");
	_imgNames.push_back("h");
	_imgNames.push_back("d");
	//_imgNames.push_back("empty");
	
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

void AnimationLetters::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationLetters::draw()
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

BalloonController * AnimationLetters::getNewController(Balloon * model)
{		
	BalloonControllerLetter * b = new BalloonControllerLetter(model);
	
	if(_controllers.size() < _imgNames.size())
	{
		b->loadImage("letters/" + _imgNames[_controllers.size()] + ".png", "letters/" + _imgNames[_controllers.size()] + "_over.png");
	}
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationLetters::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



