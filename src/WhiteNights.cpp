#include "WhiteNights.h"

WhiteNights::WhiteNights()
{
	_name = "White Nights";
}

void WhiteNights::createAnimations()
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
		City sunset video
	 --------------------------------------------------------------*/
	
	_animations.push_back(new AnimationFullVideo("sunsetcity.mov"));
	
	/*-------------------------------------------------------------
		Colored balloons (triggered by drum pads)
	 --------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("balloon3.png");
	
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
	
	AnimationBlinker * animation1 = new AnimationBlinker(imgNames);
	animation1->setMidiNotes(midiNotes);
	//animation1->setContrainRatio(false);
	animation1->setColors(colors);
	_animations.push_back(animation1);
	
	/*-------------------------------------------------------------
		White lights on balloons
	--------------------------------------------------------------*/
	
	AnimationBlinker * animation2 = new AnimationBlinker(imgNames);
	animation2->setMidiNotes(midiNotes);
	animation2->setFadeTime(200);
	animation2->setRandomAlpha(true);
	//animation2->setContrainRatio(false);
	_animations.push_back(animation2);
	
	/*-------------------------------------------------------------
		Heads singing "There is no silence"
	 --------------------------------------------------------------*/
	
	AnimationHeadsSilence * animation3 = new AnimationHeadsSilence();
	animation3->setUseOffset(true);
	_animations.push_back(animation3);
	
	/*-------------------------------------------------------------
		Video of city by night
	 --------------------------------------------------------------*/
	
	_animations.push_back(new AnimationFullVideo("newyork.mov"));
	
	_loaded = true;
}