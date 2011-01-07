#include "TurnItUp.h"

TurnItUp::TurnItUp()
{
	_name = "Turn It Up";
}

void TurnItUp::createAnimations()
{	
	vector <int> midiNotes;
	midiNotes.push_back(60);
	midiNotes.push_back(61);
	midiNotes.push_back(62);
	midiNotes.push_back(63);
	midiNotes.push_back(64);
	midiNotes.push_back(65);
	midiNotes.push_back(66);
	midiNotes.push_back(67);
	midiNotes.push_back(68);
	midiNotes.push_back(69);
	midiNotes.push_back(70);
	midiNotes.push_back(71);
	midiNotes.push_back(72);
	midiNotes.push_back(73);
	midiNotes.push_back(74);
	
	/*-------------------------------------------------------------
	 Colored balloons (triggered by Nanna)
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
	animation1->setFadeTime(10);
	//animation2->setContrainRatio(false);
	_animations.push_back(animation1);
	
	_loaded = true;	
}