#pragma once

#include "Animation.h"

class AnimationVideoHeads : public Animation
{
public:
    
	AnimationVideoHeads();
	
    void update();
	void draw();
	void destroy();
	
private:
	
	ofVideoPlayer head;
};


