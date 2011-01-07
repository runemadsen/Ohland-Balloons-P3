#pragma once

#include "ofMain.h"
#include "BalloonController.h"
#include "Balloon.h"
#include "Constants.h"
#include "Tools.h"
#include "Expo.h"

class BalloonControllerCircle : public BalloonController
{
	
public:
	
	BalloonControllerCircle(Balloon * model);
	
	void setColor(ofColor color);
	
	void update();
	void draw();
	void destroy();
	
	void noteOn();
	void noteOff();
	
	
	
private:
	
	ofImage _img;
	ofColor _color;
	PTimer timer;
};