/*
 *  Tweenable1DValue.cpp
 *
 *  Created by Andreas Muller on 08/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#include "Tweenable1DValue.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
Tweenable1DValue::Tweenable1DValue()
{
	value = 0.0f;
	timer.start();
	enableAutoTweenUpdate();	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable1DValue::_update(ofEventArgs &e)
{
	updateTweening();
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable1DValue::updateTweening()
{
	float tmpSec = timer.elapsedSec();
	
	
	if( valueTweenProps.active ) 
	{
		valueTweenProps.update( tmpSec );
	}
	else 
	{ 
		if ( valueTweenProps.backWhenDone )
		{
			tweenValueTo(valueTweenProps.startX, valueTweenProps.tweenTime, valueTweenProps.easeType, false );
		}
	}
	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable1DValue::tweenValueTo( float _valueTarget, float _timeSecs,  EasingEquations::EaseType _easeType, bool _backWhenDone, float _startDelay )
{
	valueTweenProps.startTime = timer.elapsedSec() + _startDelay;
	valueTweenProps.endTime = valueTweenProps.startTime + _timeSecs;
	
	valueTweenProps.tweenTime = _timeSecs;		
	
	valueTweenProps.easeType = _easeType;
	
	valueTweenProps.startX = value;
	valueTweenProps.endX = _valueTarget;
	
	valueTweenProps.targetValRef = &value;
	
	valueTweenProps.active = true;
	
	valueTweenProps.backWhenDone = _backWhenDone;
}


//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable1DValue::enableAutoTweenUpdate()
{
	ofAddListener(ofEvents.update, this, &Tweenable1DValue::_update);	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable1DValue::disableAutoTweenUpdate()
{
	ofRemoveListener(ofEvents.update, this, &Tweenable1DValue::_update);	
}

