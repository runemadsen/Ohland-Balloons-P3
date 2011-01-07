#include "BalloonControllerCircle.h"

/* Constructor
 ___________________________________________________________ */

BalloonControllerCircle::BalloonControllerCircle(Balloon * model) : BalloonController(model)
{
	timer.setDuration(10);
	
	_img.loadImage("balloon3.png");
}

void BalloonControllerCircle::setColor(ofColor color)
{
	_color = color;
}

/* Update
 ___________________________________________________________ */

void BalloonControllerCircle::update()
{
	timer.tick();
}

/* Draw
 ___________________________________________________________ */

void BalloonControllerCircle::draw()
{
	float alpha = Expo::easeOut(timer.getTime(), 0, 255, timer.getDuration());
	
	ofEnableAlphaBlending();
	
	ofSetColor(_color.r, _color.g, _color.b, alpha);
	
	ofRectangle bounds = _model->getBoundsFromSize(_img.getWidth(), _img.getHeight());
	
	_img.draw(bounds.x, bounds.y, bounds.width, bounds.height);
	
	/*ofFill();
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(),_model->getHeight());
	ofNoFill();
	ofEllipse(_model->getCenterX(), _model->getCenterY(), _model->getWidth(), _model->getHeight());*/
	
	ofDisableAlphaBlending();
}

/* Midi note on / off
 ___________________________________________________________ */

void BalloonControllerCircle::noteOn()
{
	timer.setState(1);
}

void BalloonControllerCircle::noteOff()
{
	timer.setState(-1);
}

/* Destroy
 ___________________________________________________________ */

void BalloonControllerCircle::destroy()
{	
	
}