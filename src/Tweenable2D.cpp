/*
 *  Tweenable2D.cpp
 *
 *  Created by Andreas Muller on 08/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#include "Tweenable2D.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
Tweenable2D::Tweenable2D()
{
	eventID = 0;
	
	// set some defaults
	width  = 100.0f;
	height = 100.0f;

	angle = 0.0f;
	
	timer.start();
	enableAutoTweenUpdate();
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::enableAutoTweenUpdate()
{
	ofAddListener(ofEvents().update, this, &Tweenable2D::_update);
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::disableAutoTweenUpdate()
{
	ofRemoveListener(ofEvents().update, this, &Tweenable2D::_update);
}


//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::_update(ofEventArgs &e)
{
	updateTweening();
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::updateTweening()
{
	float tmpSec = timer.elapsedSec();
	
	// Position
	if( posTweenProps.active )
	{
		posTweenProps.update( tmpSec );
	} 
	else 
	{ 
		if ( posTweenProps.backWhenDone )
		{
			tweenPosTo(posTweenProps.startX, posTweenProps.startY, posTweenProps.tweenTime, posTweenProps.easeType, false );
		}
	}
	
	// Size
	if( sizeTweenProps.active ) 
	{
		sizeTweenProps.update( tmpSec );
	}
	else 
	{ 
		if ( sizeTweenProps.backWhenDone )
		{
			tweenSizeTo(sizeTweenProps.startX, sizeTweenProps.startY, sizeTweenProps.tweenTime, sizeTweenProps.easeType, false );
		}
	}
	

	// Angle
	if( angleTweenProps.active ) 
	{
		angleTweenProps.update( tmpSec );
		angle = ofWrapDegrees( angle );
	}
	else 
	{ 
		if ( angleTweenProps.backWhenDone )
		{
			tweenAngleTo(angleTweenProps.startX, angleTweenProps.tweenTime, angleTweenProps.easeType, false );
		}
	}	

	// Color
	if( colorTweenProps.active ) 
	{
		colorTweenProps.update( tmpSec );
		
		interpolateAlphaBlendingRGB( &startColor, &endColor, colorTweeningVal, &color );
		//color.a = alpha;		
		//cout << "Updating color " << color << endl;
	}
	else 
	{ 
		if ( colorTweenProps.backWhenDone )
		{
			tweenColorTo( endColor, colorTweenProps.tweenTime, colorTweenProps.easeType, false );
		}
	}		
	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::tweenPosTo( float _xTarget, float _yTarget, float _timeSecs, EasingEquations::EaseType _easeType, float _startDelay, bool _backWhenDone, bool _fireEventWhenDone )
{
	posTweenProps.eventID = eventID;
	posTweenProps.animType = TweenDoneEventArgs::ANIM_POS;
	
	posTweenProps.startTime = timer.elapsedSec() + _startDelay;
	posTweenProps.endTime = posTweenProps.startTime + _timeSecs;
	
	posTweenProps.tweenTime = _timeSecs;
	
	posTweenProps.easeType = _easeType;
	
	posTweenProps.startX = pos.x;
	posTweenProps.endX = _xTarget;
	
	posTweenProps.startY = pos.y;
	posTweenProps.endY = _yTarget;	
	
	posTweenProps.targetValXRef = &pos.x;
	posTweenProps.targetValYRef = &pos.y;	
	
	posTweenProps.active = true;
	
	posTweenProps.backWhenDone = _backWhenDone;		
	
	posTweenProps.fireEventWhenDone = _fireEventWhenDone;			
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::tweenSizeTo( float _xTarget, float _yTarget, float _timeSecs,  EasingEquations::EaseType _easeType, float _startDelay, bool _backWhenDone, bool _fireEventWhenDone  )
{
	sizeTweenProps.eventID = eventID;
	sizeTweenProps.animType = TweenDoneEventArgs::ANIM_SIZE;
	
	sizeTweenProps.startTime = timer.elapsedSec() + _startDelay;
	sizeTweenProps.endTime = sizeTweenProps.startTime + _timeSecs;
	
	sizeTweenProps.tweenTime = _timeSecs;	
	
	sizeTweenProps.easeType = _easeType;
	
	sizeTweenProps.startX = width;
	sizeTweenProps.endX = _xTarget;

	sizeTweenProps.startY = height;
	sizeTweenProps.endY = _yTarget;	
	
	sizeTweenProps.targetValXRef = &width;
	sizeTweenProps.targetValYRef = &height;	

	sizeTweenProps.active = true;	

	sizeTweenProps.backWhenDone = _backWhenDone;	
	
	sizeTweenProps.fireEventWhenDone = _fireEventWhenDone;		
}


//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::tweenAngleTo( float _angleTarget, float _timeSecs, EasingEquations::EaseType _easeType, float _startDelay, bool _backWhenDone, bool _fireEventWhenDone )
{
	angleTweenProps.eventID = eventID;
	angleTweenProps.animType = TweenDoneEventArgs::ANIM_ANGLE;
	
	angleTweenProps.startTime = timer.elapsedSec() + _startDelay;
	angleTweenProps.endTime = angleTweenProps.startTime + _timeSecs;
	
	angleTweenProps.tweenTime = _timeSecs;		
	
	angleTweenProps.easeType = _easeType;
		
	float tmpAngDiff = getAngleDiff( angle, _angleTarget );		
	
	angleTweenProps.startX = angle;
	angleTweenProps.endX = angle + tmpAngDiff;
	
	angleTweenProps.targetValRef = &angle;
	
	angleTweenProps.active = true;
	
	angleTweenProps.backWhenDone = _backWhenDone;	
	
	angleTweenProps.fireEventWhenDone = _fireEventWhenDone;	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::tweenColorTo(	ofFloatColor _targetCol, float _timeSecs, EasingEquations::EaseType _easeType, float _startDelay, bool _backWhenDone, bool _fireEventWhenDone )
{
	colorTweenProps.eventID = eventID;
	colorTweenProps.animType = TweenDoneEventArgs::ANIM_COLOR;

	//cout << "Tween from " << color << " to " << _targetCol << endl;

	startColor = color;
	endColor = _targetCol; 
	
	colorTweeningVal = 0.0f;
	
	colorTweenProps.startTime = timer.elapsedSec() + _startDelay;
	colorTweenProps.endTime = colorTweenProps.startTime + _timeSecs;
	
	colorTweenProps.tweenTime = _timeSecs;		
	
	colorTweenProps.easeType = _easeType;
	
	colorTweenProps.startX	= 0.0f;
	colorTweenProps.endX	= 1.0f;
	
	colorTweenProps.targetValRef = &colorTweeningVal;
	
	colorTweenProps.active = true;
	
	colorTweenProps.backWhenDone = _backWhenDone;
	
	colorTweenProps.fireEventWhenDone = _fireEventWhenDone;	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::interpolateAlphaBlendingRGB( ofFloatColor* _startColor, ofFloatColor* _endColor, float _frac, ofFloatColor* _targetColor )
{
	_targetColor->r = (_endColor->r * _frac) + (_startColor->r * (1.0f-_frac) );
	_targetColor->g = (_endColor->g * _frac) + (_startColor->g * (1.0f-_frac) );
	_targetColor->b = (_endColor->b * _frac) + (_startColor->b * (1.0f-_frac) );
	_targetColor->a = ofLerp( _startColor->a, _endColor->a, _frac );
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
float Tweenable2D::getAngleDiff( float rot, float rotTarget)
{
	float tmp1 = fmodf( ((360.0f - rot) + rotTarget), 360.0f);
	float tmp2 = (rot - rotTarget);	
	if (tmp2 < 0.0f )  { tmp2 = 360.0f - (-tmp2); }
	if (tmp1 < tmp2 ) { return tmp1; } else { return -tmp2; }	
}

