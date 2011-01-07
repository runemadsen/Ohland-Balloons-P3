#include "ScreenSaver.h"

ScreenSaver::ScreenSaver()
{
	_name = "Screensaver";
}

void ScreenSaver::createAnimations()
{
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
	
	AnimationSweep * animation1 = new AnimationSweep(imgNames);
	
	_animations.push_back(animation1);
	
	_loaded = true;
}