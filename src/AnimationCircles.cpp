#include "AnimationCircles.h"

/* Constructor
 ___________________________________________________________ */

AnimationCircles::AnimationCircles()
{
	_usingControllers = true;
	
	ofColor color;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	
	_colors.push_back(color);
	
	color.g = 255;
	_colors.push_back(color);
	
	color.b = 255;
	_colors.push_back(color);
	
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

void AnimationCircles::update()
{
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationCircles::draw()
{
	ofSetCircleResolution(40);
	
	for(int i = 0; i < _controllers.size(); i++)
	{ 
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationCircles::getNewController(Balloon * model)
{		
	BalloonControllerCircle * b = new BalloonControllerCircle(model);
	
	int modulo = _controllers.size() % _colors.size();
	
	b->setColor(_colors[modulo]);
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationCircles::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}
