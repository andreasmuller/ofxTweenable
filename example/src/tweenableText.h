//
//  tweenableText.h
//  ofxTweenableExample
//
//  Created by Andreas Müller on 25/05/2011.
//


#pragma once


#include "ofxTweenable.h"

class tweenableText : public Tweenable2D  
{
	
public:
	
	//--------------------------------------------------------------
	void init( float _x, float _y, string _text, ofTrueTypeFont* _font, ofPoint* _color )
	{
		pos.set( _x, _y, 0.0f );
		text = _text;
		myFont = _font;
		color.set( _color->x, _color->y, _color->z );
	}	
	
	//--------------------------------------------------------------
	void draw()
	{
		ofEnableAlphaBlending();
	
			glColor4f( color.x, color.y, color.z, alpha );
			
			myFont->drawString( text, pos.x, pos.y );
		
		ofDisableAlphaBlending();
	}
	
	ofTrueTypeFont* myFont;
	string text;
};

