#include "Lean.h"

Lean::Lean()
{
	_name = "Lean";
}

void Lean::createAnimations()
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
		Falling stars
	 --------------------------------------------------------------*/
	
	AnimationStars * animation1 = new AnimationStars();
	animation1->setMidiNotes(midiNotes);
	_animations.push_back(animation1);
	
	_loaded = true;
}