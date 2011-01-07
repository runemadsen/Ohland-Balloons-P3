#include "SonOfAGun.h"

SonOfAGun::SonOfAGun()
{
	_name = "Son of a Gun";
}

void SonOfAGun::createAnimations()
{	
	vector <int> midiNotes;
	
	/*-------------------------------------------------------------
		Flashing "Ohland" letters 
	--------------------------------------------------------------*/
	
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
	
	vector <string> imgNames;

	imgNames.push_back("letters/o.png");
	imgNames.push_back("letters/h.png");
	imgNames.push_back("letters/l.png");
	imgNames.push_back("letters/a.png");
	imgNames.push_back("letters/n.png");
	imgNames.push_back("letters/d.png");
	imgNames.push_back("letters/empty.png");
	imgNames.push_back("letters/empty.png");
	AnimationBlinker * animation1 = new AnimationBlinker(imgNames);
	animation1->setMidiNotes(midiNotes);
	_animations.push_back(animation1);
	
	/*-------------------------------------------------------------
		Singing heads (doh / ohh)
	--------------------------------------------------------------*/
	
	/*midiNotes.clear();
	
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
	
	AnimationSingingHeads * animation2 = new AnimationSingingHeads(34, 37, "doh.mov");
	animation2->setMidiNotes(midiNotes);
	_animations.push_back(animation2);
	
	AnimationSingingHeads * animation3 = new AnimationSingingHeads(37, 39, "ohh.mov");
	animation3->setMidiNotes(midiNotes);
	_animations.push_back(animation3);*/
	
	AnimationSingingHeadsSingle * animation2 = new AnimationSingingHeadsSingle(34, 37, "doh.mov");
	animation2->setUseOffset(true);
	animation2->setMidiNote(60);
	_animations.push_back(animation2);
	
	AnimationSingingHeadsSingle * animation3 = new AnimationSingingHeadsSingle(37, 39, "ohh.mov");
	animation3->setUseOffset(true);
	animation3->setMidiNote(60);
	_animations.push_back(animation3);
	
	/*-------------------------------------------------------------
		Blinking white lights
	--------------------------------------------------------------*/
	
	midiNotes.clear();
	
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
	
	midiNotes.push_back(12); //C1
	midiNotes.push_back(14); //D1
	midiNotes.push_back(16); //E1
	midiNotes.push_back(17); //F1
	midiNotes.push_back(18); //G1
	
	//imgNames.clear();
	vector <string> imgNames2;
	imgNames2.push_back("balloon3.png");
	AnimationBlinker * animation4 = new AnimationBlinker(imgNames2);
	//animation4->setContrainRatio(false);
	animation4->setMidiNotes(midiNotes);
	_animations.push_back(animation4);
	
	/*-------------------------------------------------------------
		Sunset video over beach
	--------------------------------------------------------------*/
	
	_animations.push_back(new AnimationFullVideo("sunriseAUS.mov"));
	
	/*-------------------------------------------------------------
		Extra stuff we don't use right now
	 --------------------------------------------------------------*/
	
	/*_animations.push_back(new AnimationFullVideo("OH_ballet.mov"));
	_animations.push_back(new AnimationFullVideo("OH_moon.mov"));
	_animations.push_back(new AnimationFullImage("tree.jpg"));
	_animations.push_back(new AnimationFullVideo("OH_water.mov"));*/
	
	_loaded = true;	
}