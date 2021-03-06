/*
 *  Tweenable1DValue.h
 *
 *  Created by Andreas Muller on 08/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#pragma once

#include "TweenProperties.h"

#include "TweeningTimer.h"

#include "EasingEquations.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
class Tweenable1DValue
{
		
	public:

		Tweenable1DValue();
	
		void updateTweening();
	
		void tweenValueTo(	float _valueTarget,	float _timeSecs, 
							EasingEquations::EaseType _easeType = EasingEquations::EASE_LINEAR, 
						    float _startDelay = 0.0f, 
						    bool _backWhenDone = false,
						    bool _fireEventWhenDone = false );		
		
		void _update(ofEventArgs &e);
		
		void enableAutoTweenUpdate();	
		void disableAutoTweenUpdate();	
	
		float value;
	
		TweeningTimer timer;
		TweenProperties1D valueTweenProps;		
	
		int eventID;
};

