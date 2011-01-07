#include "BalloonControllerHead.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerHead::BalloonControllerHead(Balloon * model, int frameBlinkEnd, int frameCloseStart, string videoName) : BalloonController(model)
{
	_headState = 1;
	
	_frameBlinkEnd = frameBlinkEnd; 
	_frameCloseStart = frameCloseStart;
	
	head.loadMovie(videoName);
	head.play();
	head.setFrame(ofRandom(1, _frameBlinkEnd - 1));
}

/* Update
 ___________________________________________________________ */

void BalloonControllerHead::update()
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

void BalloonControllerHead::draw()
{
	ofFill();
	ofSetColor(0, 0, 0, 255);
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(), _model->getHeight());
	 
	ofRectangle bounds = _model->getBoundsFromSize(head.getWidth(), head.getHeight());
	
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	
	head.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	ofDisableAlphaBlending();
}

void BalloonControllerHead::reset()
{
	_headState = 1;
	//head.setFrame(ofRandom(1, _frameBlinkEnd - 1));
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerHead::noteOn()
{
	_headState = 2;
	_newState = true;
}

void BalloonControllerHead::noteOff()
{
	_headState = 3;
	_newState = true;
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerHead::destroy()
{	
	head.closeMovie();
}