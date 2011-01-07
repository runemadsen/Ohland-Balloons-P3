#include "MaskController.h"

MaskController::MaskController()
{

}

void MaskController::drawConvex()
{
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	_mask.draw(0, 0);
	ofDisableAlphaBlending();
}

void MaskController::computeMask(vector <Balloon *> balloons)
{
	ofFill();
	
	convertToPoints(balloons);
	
	_numConvex = nearHull_2D(_points, _numPoints, 10, _convex);
	
	drawMask(balloons);
	
	convertToAlpha();
}

/* Detect bounds
 ___________________________________________________________ */

void MaskController::computeBounds(vector <Balloon *> balloons)
{	
	_bounds.x = 9999;
	_bounds.y = 9999;
	_bounds.width = 0;
	_bounds.height = 0;
	
	for(int i = 0; i < balloons.size(); i++)
	{
		if(balloons[i]->getTopLeftX() < _bounds.x)
		{
			_bounds.x = balloons[i]->getTopLeftX();
		}
		
		if(balloons[i]->getTopLeftY() < _bounds.y)
		{
			_bounds.y = balloons[i]->getTopLeftY();
		}
		
		if(balloons[i]->getTopLeftX() + balloons[i]->getWidth() > _bounds.width)
		{
			_bounds.width = balloons[i]->getTopLeftX() + balloons[i]->getWidth();
		}
		
		if(balloons[i]->getTopLeftY() + balloons[i]->getHeight() > _bounds.height)
		{
			_bounds.height = balloons[i]->getTopLeftY() + balloons[i]->getHeight();
		}
	}
	
	_bounds.width = _bounds.width - _bounds.x;
	_bounds.height = _bounds.height - _bounds.y;
	
	// put margin in
	_bounds.x -= MARGIN;
	_bounds.y -= MARGIN;
	_bounds.width += MARGIN * 2;
	_bounds.height += MARGIN * 2;
}


ofImage * MaskController::getMask()
{
	return &_mask;
}

ofRectangle * MaskController::getBounds()
{
	return &_bounds;
}

/* Convert to points
 ___________________________________________________________ */

void MaskController::convertToPoints(vector <Balloon *> balloons)
{
	_numPoints = balloons.size();
	
	_points = new ofPoint [_numPoints];
	_convex = new ofPoint [_numPoints];
	
	for(int i = 0; i < balloons.size(); i++)
	{
		_points[i].x = balloons[i]->getCenterX();
		_points[i].y = balloons[i]->getCenterY();
	}
}

/* Draw mask in texture
 ___________________________________________________________ */

void MaskController::drawMask(vector <Balloon *> balloons)
{
	_drawTexture.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	
	_drawTexture.begin();
	
	ofSetColor(255, 255, 255);
	
	ofBeginShape();
	
	for(int i = 0; i < _numConvex; i++)
	{
		ofVertex(_convex[i].x, _convex[i].y);
	}
	
	ofEndShape();
	
	for (int j = 0; j < balloons.size(); j++) 
	{
		ofEllipse(_points[j].x, _points[j].y, balloons[j]->getWidth(), balloons[j]->getHeight());
	}
	
	_drawTexture.end();	
}

/* Convert mask to alpha
 ___________________________________________________________ */

void MaskController::convertToAlpha()
{
	_maskPixels = (unsigned char *) _drawTexture.getPixels();
	
	_mask.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
	
	for (int m = 0; m < ofGetWidth() * ofGetHeight(); m++)
	{
		if(_maskPixels[m * 4] == 255)
		{
			_maskPixels[m * 4 + 3] = 0; 	// alpha
		}
		else {
			_maskPixels[m * 4 + 3] = 255; 	// alpha
		}
		
		_maskPixels[m * 4 + 0] = 0;	// r
		_maskPixels[m * 4 + 1] = 0;	// g
		_maskPixels[m * 4 + 2] = 0;   // b
	}
	
	_mask.setFromPixels(_maskPixels, ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
	
	_mask.mirror(false, true);
	
}

/* Helper Methods
 ___________________________________________________________ */

inline float MaskController::isLeft( ofPoint P0, ofPoint P1, ofPoint P2 )
{
    return (P1.x - P0.x)*(P2.y - P0.y) - (P2.x - P0.x)*(P1.y - P0.y);
}

/* convex Hull Algorithm
 ___________________________________________________________ */

int MaskController::nearHull_2D( ofPoint* P, int n, int k, ofPoint* H )
{
    int    minmin=0,  minmax=0;
    int    maxmin=0,  maxmax=0;
    float  xmin = P[0].x,  xmax = P[0].x;
    ofPoint * cP;                 // the current point being considered
    int    bot=0, top=(-1);  // indices for bottom and top of the stack
	
    // Get the points with (1) min-max x-coord, and (2) min-max y-coord
    for (int i=1; i<n; i++) {
        cP = &P[i];
        if (cP->x <= xmin) {
            if (cP->x < xmin) {        // new xmin
                xmin = cP->x;
                minmin = minmax = i;
            }
            else {                      // another xmin
                if (cP->y < P[minmin].y)
                    minmin = i;
                else if (cP->y > P[minmax].y)
                    minmax = i;
            }
        }
        if (cP->x >= xmax) {
            if (cP->x > xmax) {        // new xmax
                xmax = cP->x;
                maxmin = maxmax = i;
            }
            else {                      // another xmax
                if (cP->y < P[maxmin].y)
                    maxmin = i;
                else if (cP->y > P[maxmax].y)
                    maxmax = i;
            }
        }
    }
    if (xmin == xmax) {      // degenerate case: all x-coords == xmin
        H[++top] = P[minmin];           // a point, or
        if (minmax != minmin)           // a nontrivial segment
            H[++top] = P[minmax];
        return top+1;                   // one or two points
    }
	
    // Next, get the max and min points in the k range bins
    Bin*   B = new Bin[k+2];   // first allocate the bins
    B[0].min = minmin;         B[0].max = minmax;        // set bin 0
    B[k+1].min = maxmin;       B[k+1].max = maxmax;      // set bin k+1
    for (int b=1; b<=k; b++) { // initially nothing is in the other bins
        B[b].min = B[b].max = NONE;
    }
    for (int b, i=0; i<n; i++) {
        cP = &P[i];
        if (cP->x == xmin || cP->x == xmax) // already have bins 0 and k+1 
            continue;
        // check if a lower or upper point
        if (isLeft( P[minmin], P[maxmin], *cP) < 0) {  // below lower line
            b = (int)( k * (cP->x - xmin) / (xmax - xmin) ) + 1;  // bin #
            if (B[b].min == NONE)       // no min point in this range
                B[b].min = i;           // first min
            else if (cP->y < P[B[b].min].y) // P[B[b].min]->y
                B[b].min = i;           // new min
            continue;
        }
        if (isLeft( P[minmax], P[maxmax], *cP) > 0) {  // above upper line
            b = (int)( k * (cP->x - xmin) / (xmax - xmin) ) + 1;  // bin #
            if (B[b].max == NONE)       // no max point in this range
                B[b].max = i;           // first max
            else if (cP->y > P[B[b].max].y) // P[B[b].max]->y
                B[b].max = i;           // new max
            continue;
        }
    }
	
    // Now, use the chain algorithm to get the lower and upper hulls
    // the output array H[] will be used as the stack
    // First, compute the lower hull on the stack H
    for (int i=0; i <= k+1; ++i)
    {
        if (B[i].min == NONE)  // no min point in this range
            continue;
        cP = &P[ B[i].min ];   // select the current min point
		
        while (top > 0)        // there are at least 2 points on the stack
        {
            // test if current point is left of the line at the stack top
            if (isLeft( H[top-1], H[top], *cP) > 0)
                break;         // cP is a new hull vertex
            else
                top--;         // pop top point off stack
        }
        H[++top] = *cP;        // push current point onto stack
    }
	
    // Next, compute the upper hull on the stack H above the bottom hull
    if (maxmax != maxmin)      // if distinct xmax points
        H[++top] = P[maxmax];  // push maxmax point onto stack
    bot = top;                 // the bottom point of the upper hull stack
    for (int i=k; i >= 0; --i)
    {
        if (B[i].max == NONE)  // no max point in this range
            continue;
        cP = &P[ B[i].max ];   // select the current max point
		
        while (top > bot)      // at least 2 points on the upper stack
        {
            // test if current point is left of the line at the stack top
            if (isLeft( H[top-1], H[top], *cP) > 0)
                break;         // current point is a new hull vertex
            else
                top--;         // pop top point off stack
        }
        H[++top] = *cP;        // push current point onto stack
    }
    if (minmax != minmin)
        H[++top] = P[minmin];  // push joining endpoint onto stack
	
    delete B;                  // free bins before returning
    return top+1;              // # of points on the stack
}


