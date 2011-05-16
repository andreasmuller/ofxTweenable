/*
 *  TweenProperties.h
 *  AccelerometerTest
 *
 *  Created by Andreas Muller on 11/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#ifndef _A_TWEEN_PROPERTIES_H
#define _A_TWEEN_PROPERTIES_H

#include "ofMain.h"

#include "../../Math/Easing/AEasingEquations.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
class TweenDoneEventArgs : public ofEventArgs 
{
	public:
	
		TweenDoneEventArgs() 
		{
			myID = 0;
			type = ANIM_NONE;
		}
	
		int myID;
		enum AnimType { ANIM_NONE, ANIM_POS, ANIM_SIZE, ANIM_ALPHA, ANIM_ANGLE, ANIM_COLOR };
		
		AnimType type;
		
};

//-------------------------------------------------------------------------------------------------------------------------------------
//
class TweenProperties
{
	public:
	
		TweenProperties()
		{
			myID = 0;
			animType = TweenDoneEventArgs::ANIM_NONE;
			
			active = false;
			startTime = 0.0f;
			endTime = 0.0f;	
			
			easeType = EASE_LINEAR;
			easeTypeBack = EASE_LINEAR;				
			
			backWhenDone = false;
			fireEventWhenDone = false;
			
			tweenTime = 0.0f;			
		}
	
		static TweenDoneEventArgs tweenDoneEventArgs;
		static ofEvent<TweenDoneEventArgs> tweenDoneEvent;	
	
		int myID;
		TweenDoneEventArgs::AnimType animType;
	
		bool active;
		
		float startTime;
		float endTime;
		float tweenTime;	
		AEaseType easeType;
		AEaseType easeTypeBack;		
	
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
					TweenProperties::tweenDoneEventArgs.myID = myID;
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
		
		void setVal( float _frac, AEaseType _easeType )
		{
			_frac = AEasingEquations::ease( _frac, _easeType );			
			*targetValRef = startX + ((endX-startX) * _frac);		
		}
		
		AEaseType easeType;
		AEaseType easeTypeBack;	
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
					TweenProperties::tweenDoneEventArgs.myID = myID;
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
		
		void setVal( float _frac, AEaseType _easeType )
		{
			_frac = AEasingEquations::ease( _frac, _easeType );				
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


#endif //_A_TWEEN_PROPERTIES_H

