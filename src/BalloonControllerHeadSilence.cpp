#include "BalloonControllerHeadSilence.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerHeadSilence::BalloonControllerHeadSilence(string videoname, Balloon * model) : BalloonController(model)
{	
	head.loadMovie(videoname);
	
	_shouldPlay = false;
}

/* Update
 ___________________________________________________________ */

void BalloonControllerHeadSilence::update()
{
	head.idleMovie();
	
	if(_shouldPlay)
	{
		if(head.getCurrentFrame() != 1)
		{
			head.setFrame(1);
		}
		
		head.play();
		
		_shouldPlay = false;
	}
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerHeadSilence::draw()
{
	ofFill();
	ofSetColor(0, 0, 0, 255);
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(), _model->getHeight());
	
	ofRectangle bounds = _model->getBoundsFromSize(head.getWidth(), head.getHeight());
	
	if(_useOffset)
	{
		bounds.y += _offSet;
	}
	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	
	head.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	ofDisableAlphaBlending();
}

void BalloonControllerHeadSilence::reset()
{
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerHeadSilence::noteOn()
{
	_shouldPlay = true;
}

void BalloonControllerHeadSilence::noteOff()
{
	
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerHeadSilence::destroy()
{	
	head.close();
}