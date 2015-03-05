/*
 *  TweenProperties.h
 *  AccelerometerTest
 *
 *  Created by Andreas Muller on 11/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

#include "EasingEquations.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
class TweenDoneEventArgs : public ofEventArgs 
{
	public:
	
		TweenDoneEventArgs() 
		{
			eventID = 0;
			type = ANIM_NONE;
		}
	
		int eventID;
		enum AnimType { ANIM_NONE, ANIM_1D_VALUE, ANIM_POS, ANIM_SIZE, ANIM_ALPHA, ANIM_ANGLE, ANIM_COLOR };
		
		AnimType type;
		
};

//-------------------------------------------------------------------------------------------------------------------------------------
//
class TweenProperties
{
	public:
	
		TweenProperties()
		{
			eventID = 0;
			animType = TweenDoneEventArgs::ANIM_NONE;
			
			active = false;
			startTime = 0.0f;
			endTime = 0.0f;	
			
			easeType = EasingEquations::EASE_LINEAR;
			easeTypeBack = EasingEquations::EASE_LINEAR;				
			
			backWhenDone = false;
			fireEventWhenDone = false;
			
			tweenTime = 0.0f;			
		}
	
		static TweenDoneEventArgs tweenDoneEventArgs;
		static ofEvent<TweenDoneEventArgs> tweenDoneEvent;	
	
		int eventID;
		TweenDoneEventArgs::AnimType animType;
	
		bool active;
		
		float startTime;
		float endTime;
		float tweenTime;	
		EasingEquations::EaseType easeType;
		EasingEquations::EaseType easeTypeBack;		
	
		bool backWhenDone;	
		bool fireEventWhenDone;	
};

//-------------------------------------------------------------------------------------------------------------------------------------
//
class TweenProperties1D : public TweenProperties
{
	public:
		
		TweenProperties1D()
		{
			startX = 0.0f;
			endX = 0.0f;
			targetValRef = NULL;
		}
		
		bool update( float _timeSecs )
		{
			if( _timeSecs < startTime ) 
			{ 
				*targetValRef = startX; 
			}
			else if ( _timeSecs >= endTime ) 
			{ 
				*targetValRef = endX; 
				active = false;
				
				if( fireEventWhenDone && !backWhenDone )
				{
					TweenProperties::tweenDoneEventArgs.eventID = eventID;
					TweenProperties::tweenDoneEventArgs.type = animType;
					ofNotifyEvent( TweenProperties::tweenDoneEvent, TweenProperties::tweenDoneEventArgs );
				}
				
				return true; // done
			}
			else 
			{
				float tmpFrac = (_timeSecs - startTime) / (endTime - startTime);
				setVal( tmpFrac, easeType );
			}
			
			return false; // not done yet
		}
		
		void setVal( float _frac, EasingEquations::EaseType _easeType )
		{
			_frac = EasingEquations::ease( _frac, _easeType );			
			*targetValRef = startX + ((endX-startX) * _frac);		
		}
		
		EasingEquations::EaseType easeType;
		EasingEquations::EaseType easeTypeBack;	
		float startX;
		float endX;
		float* targetValRef;
		
};


//-------------------------------------------------------------------------------------------------------------------------------------
//
class TweenProperties2D : public TweenProperties
{
	public:
	
		TweenProperties2D()
		{		
			startX = 0.0f;
			startY = 0.0f;
			endX = 0.0f;
			endY = 0.0f;
			targetValXRef = NULL;
			targetValYRef = NULL;
		}
		
		
		bool update( float _timeSecs )
		{
			if( _timeSecs < startTime ) 
			{ 
				*targetValXRef = startX;
				*targetValYRef = startY; 
			}
			else if ( _timeSecs >= endTime ) 
			{ 
				*targetValXRef = endX; 
				*targetValYRef = endY; 
				active = false; 
				
				if( fireEventWhenDone && !backWhenDone )
				{
					TweenProperties::tweenDoneEventArgs.eventID = eventID;
					TweenProperties::tweenDoneEventArgs.type = animType;
					ofNotifyEvent( TweenProperties::tweenDoneEvent, TweenProperties::tweenDoneEventArgs );
				}				
				
				return true; // done
			}
			else 
			{
				float tmpFrac = (_timeSecs - startTime) / (endTime - startTime);
				setVal( tmpFrac, easeType );
			}
			
			return false;  // not done yet
		}
		
		void setVal( float _frac, EasingEquations::EaseType _easeType )
		{
			_frac = EasingEquations::ease( _frac, _easeType );				
			*targetValXRef = startX + ((endX-startX) * _frac);
			*targetValYRef = startY + ((endY-startY) * _frac);		
		}		
		

		float startX;
		float startY;	
		float endX;
		float endY;		
		float* targetValXRef;
		float* targetValYRef;
		
};
