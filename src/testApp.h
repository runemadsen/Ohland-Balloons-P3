#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "Sensing.h"
#include "ofxMidi.h"

#include "Song.h"
#include "VimeoAwards.h"
#include "SonOfAGun.h"
#include "WhiteNights.h"
#include "Perfection.h"
#include "Lean.h"
#include "WolfAndI.h"
#include "BreakTheChain.h"
#include "Helicopter.h"
#include "Maskerade.h"
#include "MaskController.h"
#include "ScreenSaver.h"
#include "TurnItUp.h"
#include "TurnItUpHans.h"

class testApp : public ofSimpleApp, public ofxMidiListener
{
public:
    
	void setup();
    void update();
    void draw();
	
	void changeSong(int bankNum);
	
    void keyPressed( int key );
	void keyReleased( int key );
    void mouseMoved( int x, int y );
    void mouseDragged( int x, int y, int button );
    void mousePressed( int x, int y, int button );
    void mouseReleased();
	
    void blobOn( int x, int y, int id, int order );
    void blobMoved( int x, int y, int id, int order );
    void blobOff( int x, int y, int id, int order );
	
	Sensing * sensing;
	MaskController * maskController;
	
	ofxMidiIn midiIn;
	
	void newMidiMessage(ofxMidiEventArgs& eventArgs);
	
	vector <Song *> songs;
	int currentSong;
	int oldSong;
	
	bool shouldStartSong;
	
	bool oPressed;
	bool keyControl;
};

#endif
	
