/*
 *  LoopAnimatable2D.h
 *  AccelerometerTest
 *
 *  Created by Andreas Muller on 11/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#ifndef _A_LOOP_ANIMATABLE_2D_H
#define _A_LOOP_ANIMATABLE_2D_H

#include "TweenProperties.h"

#include "SpriteProperties2D.h"

#include "../AOfTimer.h"

#include "../../Math/Easing/AEasingEquations.h"


//-------------------------------------------------------------------------------------------------------------------------------------
//
class LoopAnimatable2D : public virtual SpriteProperties2D
{
	
public:
	
	LoopAnimatable2D();
	
	void updateLoopAnimation();
	
	void startSizeAnimationLoop( ofPoint* _start, ofPoint* _end, float _time, AEaseType _easeType = EASE_LINEAR, AEaseType _easeTypeBack = EASE_LINEAR );
	void startPosAnimationLoop( ofPoint* _start, ofPoint* _end, float _time, AEaseType _easeType = EASE_LINEAR, AEaseType _easeTypeBack = EASE_LINEAR  );
	void startAlphaAnimationLoop( float _start, float _end, float _time, AEaseType _easeType = EASE_LINEAR, AEaseType _easeTypeBack = EASE_LINEAR  );

	
	// Stop the looping animation
	void stopSizeAnimationLoop();
	void stopPosAnimationLoop();
	void stopAlphaAnimationLoop();
	
	
	float timetoLoopingFraction( float _currTime, float _timespan, int* _direction );
	
	AOfTimer timer;
	
	TweenProperties2D posAnimLoopProps;
	TweenProperties2D sizeAnimLoopProps;
	TweenProperties1D alphaAnimLoopProps;		

};


#endif //_A_LOOP_ANIMATABLE_2D_H