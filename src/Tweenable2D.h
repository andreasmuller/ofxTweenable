/*
 *  Tweenable2D.h
 *  JagermeisterApp
 *
 *  Created by Andreas Muller on 08/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#pragma once

#include "TweenProperties.h"

#include "SpriteProperties2D.h"

#include "TweeningTimer.h"

//#include "../Color/AColorInterpolator.h"

#include "EasingEquations.h"



//-------------------------------------------------------------------------------------------------------------------------------------
//
class Tweenable2D : public virtual SpriteProperties2D
{
		
	public:

		Tweenable2D();
	
		void updateTweening();
	
		void tweenPosTo(	float _x, float _y,		float _timeSecs, 
						    EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
							float _startDelay = 0.0f, bool _backWhenDone = false, bool _fireEventWhenDone = false );
	
		void tweenSizeTo(	float _w, float _h,		float _timeSecs, 
						    EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
						    float _startDelay = 0.0f, bool _backWhenDone = false, bool _fireEventWhenDone = false );
	
	
		void tweenAlphaTo(	float _alpha,			float _timeSecs, 
						  	EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
						    float _startDelay = 0.0f, bool _backWhenDone = false, bool _fireEventWhenDone = false );	
	
		void tweenAngleTo(	float _angle,			float _timeSecs, 
						  	EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
						    float _startDelay = 0.0f, bool _backWhenDone = false, bool _fireEventWhenDone = false );
	
		void tweenColorTo(	ofPoint* _targetCol,	float _timeSecs, 
						    EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
						    float _startDelay = 0.0f, bool _backWhenDone = false, bool _fireEventWhenDone = false );

		void enableAutoTweenUpdate();	
		void disableAutoTweenUpdate();
	
		void _update(ofEventArgs &e);
	
		TweeningTimer timer;

		TweenProperties2D posTweenProps;
		TweenProperties2D sizeTweenProps;
		TweenProperties1D alphaTweenProps;		
		TweenProperties1D angleTweenProps;	
		TweenProperties1D colorTweenProps;
	
		
		//AColor startColor;
		//AColor endColor;
		ofPoint startColor;
		ofPoint endColor;	
	
		//AColorInterpolator colorInterpolator;	
		float colorTweeningVal;
			
		int eventID;
	
	private:
		float getAngleDiff( float rot, float rotTarget);
		void interpolateAlphaBlendingRGB( ofPoint* _startColor, ofPoint* _endColor, float _frac, ofPoint* _targetColor );
};

