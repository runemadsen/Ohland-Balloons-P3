#include "TurnItUpHans.h"

TurnItUpHans::TurnItUpHans()
{
	_name = "Turn It Up Hans";
}

void TurnItUpHans::createAnimations()
{	
	vector <int> midiNotes;
	
	midiNotes.push_back(40);
	midiNotes.push_back(41);
	midiNotes.push_back(42);
	midiNotes.push_back(43);
	midiNotes.push_back(44);
	midiNotes.push_back(45);
	midiNotes.push_back(46);
	midiNotes.push_back(47);
	midiNotes.push_back(48);
	midiNotes.push_back(49);
	midiNotes.push_back(50);
	
	/*-------------------------------------------------------------
	 Colored balloons (triggered by drum pads)
	 --------------------------------------------------------------*/
	
	vector <string> imgNames1;
	imgNames1.push_back("balloon3.png");
	
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
	
	AnimationBlinker * animation1 = new AnimationBlinker(imgNames1);
	animation1->setMidiNotes(midiNotes);
	animation1->setColors(colors);
	//animation2->setContrainRatio(false);
	_animations.push_back(animation1);
	
	_loaded = true;	
}