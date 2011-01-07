#include "AnimationFullVideo.h"

/* Constructor
 ___________________________________________________________ */

AnimationFullVideo::AnimationFullVideo(string videoName)
{
	_vid.loadMovie(videoName);
	
	_shouldPlay = false;
	_shouldStop = false;
}

/* Update
 ___________________________________________________________ */

void AnimationFullVideo::update()
{	
	_vid.idleMovie();
	
	/*if(_shouldStop)
	{
		cout << "Video stopping \n";
		
		_vid.stop();
		
		_shouldStop = false;
	}*/
	
	if(_shouldPlay)
	{
		_vid.play();
		
		_shouldPlay = false;
	}
}

/* Draw
 ___________________________________________________________ */

void AnimationFullVideo::draw()
{	
	ofSetColor(255, 255, 255);
	
	_vid.draw(_bounds->x, _bounds->y, _bounds->width, _bounds->height);
	
	if(_useMask)
	{
		ofEnableAlphaBlending();
		_mask->draw(0, 0);
		ofDisableAlphaBlending();
	}
}

/* Was selected
 ___________________________________________________________ */

void AnimationFullVideo::wasSelected()
{		
	_shouldPlay = true;
	
	//_vid.play();
}

void AnimationFullVideo::wasDeselected()
{		
	//_shouldStop = true;
	
	_vid.stop();
}

/* Destroy
 ___________________________________________________________ */

void AnimationFullVideo::destroy()
{	
	_vid.closeMovie();
}
