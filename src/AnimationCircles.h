#pragma once

#include "Animation.h"
#include "BalloonControllerCircle.h"

class AnimationCircles : public Animation
{
public:
    
	AnimationCircles();
	
    void update();
	void draw();
	void destroy();
	
	BalloonController * getNewController(Balloon * model);
	
private:
	
	vector <ofColor> _colors;
	
};


