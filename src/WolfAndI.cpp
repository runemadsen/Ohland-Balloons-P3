#include "WolfAndI.h"

WolfAndI::WolfAndI()
{
	_name = "Wolf and I";
}

void WolfAndI::createAnimations()
{
	vector <int> midiNotes;
	midiNotes.push_back(60);
	midiNotes.push_back(61);
	midiNotes.push_back(62);
	midiNotes.push_back(63);
	midiNotes.push_back(64);
	midiNotes.push_back(65);
	midiNotes.push_back(67);
	midiNotes.push_back(69);
	midiNotes.push_back(71);
	midiNotes.push_back(72);
	midiNotes.push_back(74);
	
	/*-------------------------------------------------------------
		Wolf faces
	--------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("wolf.png");
	
	AnimationImages * animation1 = new AnimationImages(imgNames);
	_animations.push_back(animation1);
	
	/*-------------------------------------------------------------
		Video of landscapes
	 --------------------------------------------------------------*/
	
	_animations.push_back(new AnimationFullVideo("landscape.mov")); 
	
	/*-------------------------------------------------------------
		Image of moon (triggered by kick drum) ac
	 --------------------------------------------------------------*/
	
	/*AnimationFullImage * animation3 = new AnimationFullImage("moon.png");
	animation3->setMidiNote(61);
	animation3->setNodeOffAlpha(30);
	//animation3->setUseEasing(false);
	_animations.push_back(animation3);*/
	
	/*-------------------------------------------------------------
		Video of moon
	 --------------------------------------------------------------*/
	
	_animations.push_back(new AnimationFullVideo("OH_moon.mov")); 
	
	_loaded = true;
}