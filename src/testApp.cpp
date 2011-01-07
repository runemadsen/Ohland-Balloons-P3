#include "testApp.h"

/* Setup
 ___________________________________________________________ */

void testApp::setup() 
{	
	keyControl = false;
	oPressed = false;
	
	ofSetFrameRate(60);
	ofBackground( 0, 0, 0 );
	ofEnableSmoothing();
	
	sensing = new Sensing();
	maskController = new MaskController();
	
	song = new SonOfAGun();
	song->setBank(1);
	song->createAnimations();
	
	midiIn.setVerbose(false);
	midiIn.listPorts();
	midiIn.openPort(1);
	midiIn.addListener(this);
}

/* Update
 ___________________________________________________________ */

void testApp::update() 
{	
	sensing->update();
	
	if(sensing->shouldUpdateControllers())
	{
		maskController->computeMask(sensing->getBalloons());
		maskController->computeBounds(sensing->getBalloons());
		
		song->updateControllers(sensing->getBalloons());
		song->setMask(maskController->getMask());
		song->setBoundsOffset(maskController->getBounds(), sensing->getOffset());
	}
	
	song->update();
}

/* Draw
 ___________________________________________________________ */

void testApp::draw() 
{	
	song->draw();
	
	sensing->draw();
	
	if(DEBUG)
	{
		ofSetColor(255, 255, 255);
	
		ofDrawBitmapString(ofToString(ofGetFrameRate(), 0), 20, 20);
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
	
	if(!sensing->getRecordMode())
	{
		if(eventArgs.status == MIDI_PROGRAM_CHANGE || eventArgs.status == MIDI_NOTE_ON || eventArgs.status == MIDI_NOTE_OFF)
		{
			song->newMidiMessage(eventArgs);
		}
		else 
		{
			if(DEBUG)
			{
				cout << "This message was not used \n";
			}
		}
	}
}

/* Events
 ___________________________________________________________ */

void testApp::keyPressed( int key ) 
{
	sensing->keyPressed(key);
	
	if(keyControl)
	{
		// change animation manually
		if(key > '0' && key <= '9')
		{
			int convert = key - '0';
			
			convert = convert - 1;
			
			song->changeAnimation(convert);
		}
		
		// Blink all balloons in animation
		if(key == 'o')
		{
			if (!oPressed) 
			{
				song->currentAnimation()->allOn();
				
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
			song->currentAnimation()->allOff();
		
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


