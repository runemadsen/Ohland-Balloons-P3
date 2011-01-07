#include "AnimationSweep.h"

/* Constructor
 ___________________________________________________________ */

AnimationSweep::AnimationSweep(vector <string> imgNames)
{
	_usingControllers = true;
	
	_imgNames = imgNames;
}

/* Update
 ___________________________________________________________ */

void AnimationSweep::update()
{	
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->update();
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationSweep::draw()
{
	for(int i = 0; i < _controllers.size(); i++)
	{
		_controllers[i]->draw();
	}
}

/* Overrides
 ___________________________________________________________ */

BalloonController * AnimationSweep::getNewController(Balloon * model)
{		
	int modulo = _controllers.size() % _imgNames.size();
		
	BalloonControllerSweep * b = new BalloonControllerSweep(_imgNames[modulo], model);
	
	b->setStartNum(_controllers.size() * 20);
	
	return b;
}

/* Destroy
 ___________________________________________________________ */

void AnimationSweep::destroy()
{
	for (int i = 0; i < _controllers.size(); i++) 
	{
		_controllers[i]->destroy();
		delete _controllers[i];
	}
	
	_controllers.clear();
}



