#include "Perfection.h"

Perfection::Perfection()
{
	_name = "Perfection";
}

void Perfection::createAnimations()
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
		Video of ballerina
	 --------------------------------------------------------------*/
	
	//_animations.push_back(new AnimationFullVideo("ballerina.mov")); 
	_animations.push_back(new AnimationFullVideo("OH_ballet.mov")); 
	
	/*-------------------------------------------------------------
		White lights on balloons with random alpha (verse)
	 --------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("balloon3.png");
	
	AnimationBlinker * animation2 = new AnimationBlinker(imgNames);
	animation2->setMidiNotes(midiNotes);
	animation2->setFadeTime(200);
	animation2->setRandomAlpha(true);
	//animation2->setContrainRatio(false);
	
	_animations.push_back(animation2);
	
	/*-------------------------------------------------------------
		White lights on balloons (bridge)
	--------------------------------------------------------------*/
	
	AnimationBlinker * animation3 = new AnimationBlinker(imgNames);
	animation3->setMidiNotes(midiNotes);
	//animation3->setContrainRatio(false);
	_animations.push_back(animation3);
	
	_loaded = true;
}