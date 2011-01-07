#include "AnimationStars.h"

/* Constructor
 ___________________________________________________________ */

AnimationStars::AnimationStars()
{
	_usingControllers = true;
	
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
	
	for(int i = 0; i < NUM_TEXTURES; i++)
	{
		textures[i].loadImage("particleGrid" + ofToString(i, 0) + ".png");
	}
}

/* Update
 ___________________________________________________________ */

void AnimationStars::update()
{
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationStars::draw()
{
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationStars::getNewController(Balloon * model)
{		
	BalloonControllerStars * b = new BalloonControllerStars(model);
	b->setTexture(textures[0], 2, 2);
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationStars::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}