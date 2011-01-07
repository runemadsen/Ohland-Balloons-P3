#include "BreakTheChain.h"

BreakTheChain::BreakTheChain()
{
	_name = "Break the Chain";
}

void BreakTheChain::createAnimations()
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
		Colored lights (following the marimba)
	 --------------------------------------------------------------*/
	
	/*vector <string> imgNames;
	imgNames.push_back("balloon3.png");
	
	vector <ofColor> colors;
	
	ofColor aColor;
	aColor.r = 255;
	aColor.g = 0;
	aColor.b = 0;
	colors.push_back(aColor);
	
	aColor.g = 255;
	colors.push_back(aColor);
	
	aColor.b = 255;
	colors.push_back(aColor);
	
	AnimationBlinker * animation1 = new AnimationBlinker(imgNames);
	animation1->setMidiNotes(midiNotes);
	animation1->setColors(colors);
	_animations.push_back(animation1);*/
	
	/*-------------------------------------------------------------
		Video of flocking birds
	 --------------------------------------------------------------*/
	
	_animations.push_back(new AnimationFullVideo("birds.mov"));
	
	/*-------------------------------------------------------------
		Image of a tree top
	 --------------------------------------------------------------*/
	
	/*AnimationFullImage * animation3 = new AnimationFullImage("tree.jpg");
	animation3->setUseMidi(false);
	_animations.push_back(animation3);*/
	
	_loaded = true;
}