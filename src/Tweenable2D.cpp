/*
 *  Tweenable2D.cpp
 *  JagermeisterApp
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
	
	alpha = 1.0f;
	
	
	timer.start();
	enableAutoTweenUpdate();
}


//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::enableAutoTweenUpdate()
{
	ofAddListener(ofEvents.update, this, &Tweenable2D::_update);	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::disableAutoTweenUpdate()
{
	ofRemoveListener(ofEvents.update, this, &Tweenable2D::_update);	
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
	
	// Alpha
	if( alphaTweenProps.active ) 
	{
		alphaTweenProps.update( tmpSec );
	}
	else 
	{ 
		if ( alphaTweenProps.backWhenDone )
		{
			tweenAlphaTo(alphaTweenProps.startX, alphaTweenProps.tweenTime, alphaTweenProps.easeType, false );
		}
	}

	// Angle
	if( angleTweenProps.active ) 
	{
		angleTweenProps.update( tmpSec );
		//angle = AngleMath::wrapAngle180( angle ); 
		if( angle > 180.0f ) { angle -= 360.0f; } else if ( angle < -180.0f ) { angle += 360.0f; }
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
		
		//AColor tmpCol = colorInterpolator.interpolateAlphaBlendingRGB( colorTweeningVal );
		//color.setRGB( tmpCol.rgb.red, tmpCol.rgb.green, tmpCol.rgb.blue );
		
		interpolateAlphaBlendingRGB( &startColor, &endColor, colorTweeningVal, &color );
		
	}
	else 
	{ 
		if ( colorTweenProps.backWhenDone )
		{
			//AColor tmpCol( endColor.rgb.red, endColor.rgb.green, endColor.rgb.blue );
			//tweenColorTo( &tmpCol,	colorTweenProps.tweenTime, colorTweenProps.easeType, false );
			
			tweenColorTo( &endColor, colorTweenProps.tweenTime, colorTweenProps.easeType, false );			
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
void Tweenable2D::tweenAlphaTo( float _alphaTarget, float _timeSecs,  EasingEquations::EaseType _easeType, float _startDelay, bool _backWhenDone, bool _fireEventWhenDone )
{
	//cout << " Tweenable2D::tweenAlphaTo  _alphaTarget: " << _alphaTarget << "  _timeSecs: " << _timeSecs << "  _easeType: " << _easeType << endl; 

	alphaTweenProps.eventID = eventID;
	alphaTweenProps.animType = TweenDoneEventArgs::ANIM_ALPHA;	
	
	alphaTweenProps.startTime = timer.elapsedSec() + _startDelay;
	alphaTweenProps.endTime = alphaTweenProps.startTime + _timeSecs;
	
	alphaTweenProps.tweenTime = _timeSecs;		
	
	alphaTweenProps.easeType = _easeType;
	
	alphaTweenProps.startX = alpha;
	alphaTweenProps.endX = _alphaTarget;
	
	alphaTweenProps.targetValRef = &alpha;
	
	alphaTweenProps.active = true;
	
	alphaTweenProps.backWhenDone = _backWhenDone;
	
	alphaTweenProps.fireEventWhenDone = _fireEventWhenDone;		
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
	//angleTweenProps.endX = _angleTarget;	
	
	angleTweenProps.targetValRef = &angle;
	
	angleTweenProps.active = true;
	
	angleTweenProps.backWhenDone = _backWhenDone;	
	
	angleTweenProps.fireEventWhenDone = _fireEventWhenDone;	
}


//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::tweenColorTo(	ofPoint* _targetCol, float _timeSecs, EasingEquations::EaseType _easeType, float _startDelay, bool _backWhenDone, bool _fireEventWhenDone )
{
	colorTweenProps.eventID = eventID;
	colorTweenProps.animType = TweenDoneEventArgs::ANIM_COLOR;
	
	//startColor.setRGB( color.rgb.red, color.rgb.green, color.rgb.blue );
	//endColor.setRGB( _targetCol->rgb.red, _targetCol->rgb.green, _targetCol->rgb.blue );	
	
	startColor.set( color.x, color.y, color.z );
	endColor.set( _targetCol->x, _targetCol->y, _targetCol->z );		
	
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
	
	//colorInterpolator.setStart( &startColor );
	//colorInterpolator.setEnd( &endColor );	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Tweenable2D::interpolateAlphaBlendingRGB( ofPoint* _startColor, ofPoint* _endColor, float _frac, ofPoint* _targetColor )
{
	_targetColor->x = (_endColor->x * _frac) + (_startColor->x * (1.0f-_frac) );
	_targetColor->y = (_endColor->y * _frac) + (_startColor->y * (1.0f-_frac) );
	_targetColor->z = (_endColor->z * _frac) + (_startColor->z * (1.0f-_frac) );
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
float Tweenable2D::getAngleDiff( float rot, float rotTarget)
{
	float tmp1 = fmodf( ((360.0f - rot) + rotTarget) , 360.0f) ;
	float tmp2 = (rot - rotTarget);
	
	//printf( " rot: %f rotTarget: %f \n", rot, rotTarget );
	
	if (tmp2 < 0.0f ) 
	{
		tmp2 = 360.0f - (-tmp2);
	}
	
	//printf( " tmp1: %f tmp2: %f \n", tmp1, tmp2 );
	
	if (tmp1 < tmp2 ) 
	{
		return tmp1;
	} 
	else 
	{
		return -tmp2;
	}	
}

