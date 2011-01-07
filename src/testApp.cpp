#include "testApp.h"

/* Setup
 ___________________________________________________________ */

void testApp::setup() 
{	
	keyControl = false;
	oPressed = false;
	shouldStartSong = true;
	currentSong = 0;
	oldSong = 0;
	
	ofSetFrameRate(60);
	ofBackground( 0, 0, 0 );
	ofEnableSmoothing();
	
	sensing = new Sensing();
	maskController = new MaskController();

	//songs.push_back(new VimeoAwards());
	//songs[0]->setBank(1);
	
	songs.push_back(new SonOfAGun());
	songs[0]->setBank(1);
	songs[0]->createAnimations();
	
	songs.push_back(new WhiteNights());
	songs[1]->setBank(2);
	
	songs.push_back(new Perfection());
	songs[2]->setBank(3);
	
	songs.push_back(new Lean());
	songs[3]->setBank(4);
	
	songs.push_back(new WolfAndI());
	songs[4]->setBank(5);
	
	songs.push_back(new BreakTheChain());
	songs[5]->setBank(6);
	
	songs.push_back(new Helicopter());
	songs[6]->setBank(7);
	
	songs.push_back(new Maskerade());
	songs[7]->setBank(8);
	
	songs.push_back(new TurnItUp());
	songs[8]->setBank(9);
	
	songs.push_back(new TurnItUpHans());
	songs[9]->setBank(10);
	
	songs.push_back(new ScreenSaver());
	songs[10]->setBank(20);
	
	midiIn.setVerbose(false);
	midiIn.listPorts();
	midiIn.openPort(1);
	midiIn.addListener(this);
}

/* Update
 ___________________________________________________________ */

void testApp::update() 
{	
	
	if(shouldStartSong)
	{
		songs[oldSong]->destroyAnimations();
		songs[currentSong]->createAnimations();
		sensing->forceUpdateControllers();
	}
	
	sensing->update();
	
	if(sensing->shouldUpdateControllers())
	{
		maskController->computeMask(sensing->getBalloons());
		maskController->computeBounds(sensing->getBalloons());
		
		songs[currentSong]->updateControllers(sensing->getBalloons());
		
		songs[currentSong]->setMask(maskController->getMask());
		songs[currentSong]->setBoundsOffset(maskController->getBounds(), sensing->getOffset());
	}
	
	if(shouldStartSong)
	{
		songs[currentSong]->changeAnimation(0);
		shouldStartSong = false;
	}
	
	songs[currentSong]->update();
}

/* Draw
 ___________________________________________________________ */

void testApp::draw() 
{	
	songs[currentSong]->draw();
	
	sensing->draw();
	
	if(DEBUG)
	{
		ofSetColor(255, 255, 255);
	
		ofDrawBitmapString(ofToString(ofGetFrameRate(), 0), 20, 20);
	}
}

/* Change song
___________________________________________________________ */

void testApp::changeSong(int bankNum)
{	
	//if (bankNum >= 0 && bankNum != currentSong) 
	if (bankNum >= 0) 
	{
		for(int i = 0; i < songs.size(); i++)
		{
			if(bankNum == songs[i]->getBank())
			{
				//songs[currentSong]->destroyAnimations();
				oldSong = currentSong;
				currentSong = i;
				shouldStartSong = true;
				
				cout << "-----> SONG CHANGED: " << songs[currentSong]->getName() << endl;
				
				break;
			}
		}
	}
}

/* MIDI Message
 ___________________________________________________________ */

void testApp::newMidiMessage(ofxMidiEventArgs& eventArgs)
{	
	if(DEBUG)
	{
		cout << "-----------------------------------------" << "\n";
		cout << "New Midi Message" << "\n";
		cout << "Status: " << eventArgs.status << "\n";
		cout << "Byte One: " << eventArgs.byteOne << "\n";
		cout << "Byte Two: " << eventArgs.byteTwo << "\n";
	}
	
	if(eventArgs.status == MIDI_CONTROL_CHANGE && eventArgs.byteOne == 0)
	{	
		changeSong(eventArgs.byteTwo);
	}
	else if(eventArgs.status == MIDI_PROGRAM_CHANGE || eventArgs.status == MIDI_NOTE_ON || eventArgs.status == MIDI_NOTE_OFF)
	{
		songs[currentSong]->newMidiMessage(eventArgs);
	}
	else 
	{
		if(DEBUG)
		{
			cout << "This message was not used \n";
		}
	}
}

/* Events
 ___________________________________________________________ */

void testApp::keyPressed( int key ) 
{
	sensing->keyPressed(key);
	
	// Only do this stuff if keyControl is enabled
	if(keyControl)
	{
		// change song manually
		if (key == 356) // left arrow
		{
			int prevSong = currentSong - 1 < 0 ? 0 : currentSong - 1; 
			
			changeSong(songs[prevSong]->getBank());
		}
		else if(key == 358) // right arrow
		{
			int nextSong = currentSong + 1 >= songs.size() ? songs.size() - 1 : currentSong + 1;
			
			changeSong(songs[nextSong]->getBank());
		}
		
		// change animation manually
		if(key > '0' && key <= '9')
		{
			int convert = key - '0';
			
			convert = convert - 1;
			
			songs[currentSong]->changeAnimation(convert);
		}
		
		// Blink all balloons in animation
		if(key == 'o')
		{
			if (!oPressed) 
			{
				songs[currentSong]->currentAnimation()->allOn();
				
				oPressed = true;
			}
		}
	}
	
	// fullscreen
	if (key =='f' || key=='F') 
	{
		ofToggleFullscreen();
	} 
	
	// Enable keyControl
	if (key =='k') 
	{
		keyControl = !keyControl;
		
		string output = keyControl ? "Enabled" : "Disabled";
		
		cout << ":::::::::::: KeyControl " << output << " ::::::::::::" << endl;
		
	}
}

void testApp::keyReleased( int key ) 
{
	// Blink all balloons in animation
	if(key == 'o')
	{
		if(oPressed)
		{
			songs[currentSong]->currentAnimation()->allOff();
		
			oPressed = false;
		}
	}
}

void testApp::mouseMoved( int x, int y ) {}

void testApp::mouseDragged( int x, int y, int button ) 
{
	sensing->mouseDragged(x, y, button);
}

void testApp::mousePressed( int x, int y, int button ) 
{
	sensing->mousePressed(x, y, button);
}

void testApp::mouseReleased() {}


