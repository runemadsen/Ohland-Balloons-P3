#include "VimeoAwards.h"

VimeoAwards::VimeoAwards()
{
	_name = "Vimeo Awards";
}

void VimeoAwards::createAnimations()
{	
	/*-------------------------------------------------------------
		Sweep
	 --------------------------------------------------------------*/
	
	vector <string> imgNames;
	imgNames.push_back("vimeoletters/v.png");
	imgNames.push_back("vimeoletters/i.png");
	imgNames.push_back("vimeoletters/m.png");
	imgNames.push_back("vimeoletters/e.png");
	imgNames.push_back("vimeoletters/o.png");
	imgNames.push_back("vimeoletters/a.png");
	imgNames.push_back("vimeoletters/w.png");
	imgNames.push_back("vimeoletters/a.png");
	imgNames.push_back("vimeoletters/r.png");
	imgNames.push_back("vimeoletters/d.png");
	imgNames.push_back("vimeoletters/s.png");
	imgNames.push_back("vimeoletters/2.png");
	imgNames.push_back("vimeoletters/0.png");
	imgNames.push_back("vimeoletters/1.png");
	imgNames.push_back("vimeoletters/0.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	
	AnimationSweep * animation1 = new AnimationSweep(imgNames);
	
	_animations.push_back(animation1);
	
	/*-------------------------------------------------------------
		Blink
	 --------------------------------------------------------------*/
	
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
	midiNotes.push_back(75);
	midiNotes.push_back(76);
	
	/*imgNames.clear();
	
	imgNames.push_back("vimeoletters/v.png");
	imgNames.push_back("vimeoletters/i.png");
	imgNames.push_back("vimeoletters/m.png");
	imgNames.push_back("vimeoletters/e.png");
	imgNames.push_back("vimeoletters/o.png");
	imgNames.push_back("vimeoletters/a.png");
	imgNames.push_back("vimeoletters/w.png");
	imgNames.push_back("vimeoletters/a.png");
	imgNames.push_back("vimeoletters/r.png");
	imgNames.push_back("vimeoletters/d.png");
	imgNames.push_back("vimeoletters/s.png");
	imgNames.push_back("vimeoletters/2.png");
	imgNames.push_back("vimeoletters/0.png");
	imgNames.push_back("vimeoletters/1.png");
	imgNames.push_back("vimeoletters/0.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");*/
	
	AnimationBlinker * animation2 = new AnimationBlinker(imgNames);
	animation2->setMidiNotes(midiNotes);
	animation2->setFadeTime(500);
	_animations.push_back(animation2);
	
	/*-------------------------------------------------------------
	 Logo blink
	 --------------------------------------------------------------*/

	imgNames.clear();
	
	imgNames.push_back("vimeoletters/logo.png");
	
	AnimationBlinker * animation3 = new AnimationBlinker(imgNames);
	animation3->setMidiNotes(midiNotes);
	_animations.push_back(animation3);
	
	_loaded = true;	
}