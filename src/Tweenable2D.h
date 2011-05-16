/*
 *  Tweenable2D.h
 *  JagermeisterApp
 *
 *  Created by Andreas Muller on 08/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#ifndef _A_TWEENABLE_2D_H
#define _A_TWEENABLE_2D_H



#include "TweenProperties.h"

#include "SpriteProperties2D.h"

#include "../AOfTimer.h"

#include "../Color/AColorInterpolator.h"

//#include "../../Math/AngleMath.h"
#include "../../Math/Easing/AEasingEquations.h"



//-------------------------------------------------------------------------------------------------------------------------------------
//
class Tweenable2D : public virtual SpriteProperties2D
{
		
	public:

		Tweenable2D();
	
		void updateTweening();
	
		void tweenPosTo(	float _x, float _y,		float _timeSecs, AEaseType _easeType = EASE_LINEAR, bool _backWhenDone = false, float _startDelay = 0.0f, bool _fireEventWhenDone = false );
		void tweenSizeTo(	float _w, float _h,		float _timeSecs, AEaseType _easeType = EASE_LINEAR, bool _backWhenDone = false, float _startDelay = 0.0f, bool _fireEventWhenDone = false );
		void tweenAlphaTo(	float _alpha,			float _timeSecs, AEaseType _easeType = EASE_LINEAR, bool _backWhenDone = false, float _startDelay = 0.0f, bool _fireEventWhenDone = false );		
		void tweenAngleTo(	float _angle,			float _timeSecs, AEaseType _easeType = EASE_LINEAR, bool _backWhenDone = false, float _startDelay = 0.0f, bool _fireEventWhenDone = false );
		void tweenColorTo(	AColor* _targetCol,		float _timeSecs, AEaseType _easeType = EASE_LINEAR, bool _backWhenDone = false, float _startDelay = 0.0f, bool _fireEventWhenDone = false );

		void enableAutoTweenUpdate();	
		void disableAutoTweenUpdate();
	
		void _update(ofEventArgs &e);
	
		AOfTimer timer;

		TweenProperties2D posTweenProps;
		TweenProperties2D sizeTweenProps;
		TweenProperties1D alphaTweenProps;		
		TweenProperties1D angleTweenProps;	
		TweenProperties1D colorTweenProps;
	
		AColor startColor;
		AColor endColor;	
		AColorInterpolator colorInterpolator;	
		float colorTweeningVal;
			
		int myID;
	
	private:
		float getAngleDiff( float rot, float rotTarget);
};


#endif //_A_TWEENABLE_2D_H
