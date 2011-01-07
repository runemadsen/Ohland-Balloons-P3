#pragma once

#include "ofMain.h"
#include "Balloon.h"
#include "ofxFBOTexture.h"
#include "ofxImage.h"

#define NONE  (-1)
#define MARGIN 20

typedef struct range_bin Bin;
struct range_bin {
    int    min;    // index of min point P[] in bin (>=0 or NONE)
    int    max;    // index of max point P[] in bin (>=0 or NONE)
};

class MaskController
{
	
public:
	
	MaskController();
	
	void drawConvex();
	
	void computeMask(vector <Balloon *> balloons);
	void computeBounds(vector <Balloon *> balloons);
	
	ofImage * getMask();
	ofRectangle * getBounds();
	
private:
		
	ofxFBOTexture _drawTexture;
	ofxImage _mask;
	ofRectangle _bounds;
	
	unsigned char * _maskPixels;
	
	ofPoint * _points;
	int _numPoints;
	ofPoint * _convex;
	int _numConvex;
	
	inline float isLeft( ofPoint P0, ofPoint P1, ofPoint P2 );
	int nearHull_2D( ofPoint * P, int n, int k, ofPoint * H );
	
	void convertToPoints(vector <Balloon *> balloons);
	void drawMask(vector <Balloon *> balloons);
	void convertToAlpha();
};





