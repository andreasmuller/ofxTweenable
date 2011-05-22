/*
 *  LoopAnimatable2D.h
 *  AccelerometerTest
 *
 *  Created by Andreas Muller on 11/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#pragma once

#include "TweenProperties.h"

#include "SpriteProperties2D.h"

#include "TweeningTimer.h"

#include "EasingEquations.h"


//-------------------------------------------------------------------------------------------------------------------------------------
//
class LoopAnimatable2D : public virtual SpriteProperties2D
{
	
public:
	
	LoopAnimatable2D();
	
	void updateLoopAnimation();
	
	void startSizeAnimationLoop( ofPoint* _start, ofPoint* _end, float _time, 	
								 EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
								EasingEquations::EaseType _easeTypeBack = EasingEquations::EASE_LINEAR );
	
	void startPosAnimationLoop( ofPoint* _start, ofPoint* _end, float _time, 	
							    EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
							    EasingEquations::EaseType _easeTypeBack = EasingEquations::EASE_LINEAR  );
	
	void startAlphaAnimationLoop( float _start, float _end, float _time, 		
								  EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
								  EasingEquations::EaseType _easeTypeBack = EasingEquations::EASE_LINEAR  );

	
	// Stop the looping animation
	void stopSizeAnimationLoop();
	void stopPosAnimationLoop();
	void stopAlphaAnimationLoop();
	
	
	float timetoLoopingFraction( float _currTime, float _timespan, int* _direction );
	
	TweeningTimer timer;
	
	TweenProperties2D posAnimLoopProps;
	TweenProperties2D sizeAnimLoopProps;
	TweenProperties1D alphaAnimLoopProps;		

};

