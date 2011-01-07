#include "Maskerade.h"

Maskerade::Maskerade()
{
	_name = "Maskerade";
}

void Maskerade::createAnimations()
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
		Blinking harlequin masks
	 --------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("harlequin2.png");
	
	AnimationBlinker * animation1 = new AnimationBlinker(imgNames);
	animation1->setMidiNotes(midiNotes);
	_animations.push_back(animation1);
	
	/*-------------------------------------------------------------
		White lights
	 --------------------------------------------------------------*/
	
	imgNames.clear();
	imgNames.push_back("balloon3.png");
	
	AnimationBlinker * animation2 = new AnimationBlinker(imgNames);
	animation2->setMidiNotes(midiNotes);
	animation2->setFadeTime(10);
	//animation2->setContrainRatio(false);
	_animations.push_back(animation2);
	
	/*-------------------------------------------------------------
		White lights (longer fade)
	 --------------------------------------------------------------*/
	
	imgNames.clear();
	imgNames.push_back("balloon3.png");
	
	AnimationBlinker * animation3 = new AnimationBlinker(imgNames);
	animation3->setMidiNotes(midiNotes);
	animation3->setFadeTime(50);
	_animations.push_back(animation3);
	
	_loaded = true;
}