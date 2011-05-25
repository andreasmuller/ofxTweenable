//
//  tweenableSquare.h
//  ofxTweenableExample
//
//  Created by Andreas Müller on 25/05/2011.
//


#pragma once

#include "ofxTweenable.h"

class tweenableSquare : public Tweenable2D  
{
	
public:
	
	//--------------------------------------------------------------
	void init( float _x, float _y, float _w, float _h, ofPoint* _color )
	{
		pos.set( _x, _y, 0.0f );
		width  = _w;
		height = _h;	
		color.set( _color->x, _color->y, _color->z );
	}	
	
	//--------------------------------------------------------------
	void draw()
	{
		ofEnableAlphaBlending();
	
			glColor4f( color.x, color.y, color.z, alpha );
			
			// let's draw from the middle
			ofRect( pos.x - (width/2.0f), pos.y - (height/2.0f), width, height );
		
		ofDisableAlphaBlending();
	}
	
	
};

