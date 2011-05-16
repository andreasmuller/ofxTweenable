/*
 *  Tweenable1DValue.h
 *
 *  Created by Andreas Muller on 08/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#pragma once

#include "TweenProperties.h"
#include "../AOfTimer.h"

#include "../../Math/Easing/AEasingEquations.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
class Tweenable1DValue
{
		
	public:

		Tweenable1DValue();
	
		void updateTweening();
	
		void tweenValueTo(	float _valueTarget,			float _timeSecs, AEaseType _easeType = EASE_LINEAR, bool _backWhenDone = false, float _startDelay = 0.0f );		
	
		float value;
	
		AOfTimer timer;
		TweenProperties1D valueTweenProps;		
	
};

