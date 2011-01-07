#pragma once

#include "Song.h"
#include "AnimationEmpty.h"
#include "AnimationSweep.h"
#include "AnimationBlinker.h"


class VimeoAwards : public Song
{
public:
    
	VimeoAwards();
	
	void createAnimations();
};


