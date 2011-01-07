#include "Helicopter.h"

Helicopter::Helicopter()
{
	_name = "Helicopter";
}

void Helicopter::createAnimations()
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
		Colored balloons (triggered by drum pads)
	 --------------------------------------------------------------*/
	
	vector <string> imgNames2;
	imgNames2.push_back("balloon3.png");
	
	vector <ofColor> colors;
	
	ofColor aColor;
	
	aColor.r = 232;
	aColor.g = 102;
	aColor.b = 140;
	colors.push_back(aColor);
	
	aColor.r = 29;
	aColor.g = 159;
	aColor.b = 115;
	colors.push_back(aColor);
	
	aColor.r = 145;
	aColor.g = 76;
	aColor.b = 45;
	colors.push_back(aColor);
	
	aColor.r = 206;
	aColor.g = 90;
	aColor.b = 90;
	colors.push_back(aColor);
	
	aColor.r = 122;
	aColor.g = 166;
	aColor.b = 193;
	colors.push_back(aColor);
	
	aColor.r = 198;
	aColor.g = 176;
	aColor.b = 38;
	colors.push_back(aColor);
	
	AnimationBlinker * animation2 = new AnimationBlinker(imgNames2);
	animation2->setMidiNotes(midiNotes);
	animation2->setColors(colors);
	//animation2->setContrainRatio(false);
	_animations.push_back(animation2);
	
	/*-------------------------------------------------------------
		Sweeping lights on all balloons
	 --------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("balloon3.png");
	
	AnimationSweep * animation1 = new AnimationSweep(imgNames);
	animation1->setMidiNotes(midiNotes);
	_animations.push_back(animation1);
	
	_loaded = true;
}