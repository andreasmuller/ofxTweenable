/*
 *  LoopAnimatable2D.cpp
 *  AccelerometerTest
 *
 *  Created by Andreas Muller on 11/09/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */

#include "LoopAnimatable2D.h"

//-------------------------------------------------------------------------------------------------------------------------------------
//
LoopAnimatable2D::LoopAnimatable2D()
{
	timer.start();
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void LoopAnimatable2D::updateLoopAnimation()
{
	float tmpSec = timer.elapsedSec();

	if( sizeAnimLoopProps.active )
	{
		int direction = 0;
		float tmpTimeInLoop = tmpSec - sizeAnimLoopProps.startTime;		
		float tmpFraction = timetoLoopingFraction( tmpTimeInLoop, sizeAnimLoopProps.tweenTime, &direction );
		
		if( direction == 0 ) 
		{ 
			sizeAnimLoopProps.setVal( tmpFraction, sizeAnimLoopProps.easeType ); 
		}
		else 
		{ 
			sizeAnimLoopProps.setVal( tmpFraction, sizeAnimLoopProps.easeTypeBack ); 
		}
	}

	if( posAnimLoopProps.active )
	{
		int direction = 0;		
		float tmpTimeInLoop = tmpSec - posAnimLoopProps.startTime;		
		float tmpFraction = timetoLoopingFraction( tmpTimeInLoop, posAnimLoopProps.tweenTime, &direction );

		if( direction == 0 ) 
		{ 
			posAnimLoopProps.setVal( tmpFraction, posAnimLoopProps.easeType ); 
		}
		else 
		{ 
			posAnimLoopProps.setVal( tmpFraction, posAnimLoopProps.easeTypeBack ); 
		}
	}
	
	if( alphaAnimLoopProps.active )
	{
		int direction = 0;		
		float tmpTimeInLoop = tmpSec - alphaAnimLoopProps.startTime;		
		float tmpFraction = timetoLoopingFraction( tmpTimeInLoop, alphaAnimLoopProps.tweenTime, &direction );
		
		if( direction == 0 ) 
		{ 
			alphaAnimLoopProps.setVal( tmpFraction, alphaAnimLoopProps.easeType ); 
		}
		else 
		{ 
			alphaAnimLoopProps.setVal( tmpFraction, alphaAnimLoopProps.easeTypeBack ); 
		}
	}	

}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void LoopAnimatable2D::startSizeAnimationLoop( ofPoint* _start, ofPoint*_end, float _timeSecs, EasingEquations::EaseType _easeType, EasingEquations::EaseType _easeTypeBack )
{
	sizeAnimLoopProps.startTime = timer.elapsedSec();
	sizeAnimLoopProps.endTime = sizeAnimLoopProps.startTime + _timeSecs;
	
	sizeAnimLoopProps.tweenTime = _timeSecs;
	
	sizeAnimLoopProps.easeType = _easeType;
	sizeAnimLoopProps.easeTypeBack = _easeTypeBack;		
	
	sizeAnimLoopProps.startX = _start->x;
	sizeAnimLoopProps.endX = _end->x;
	
	sizeAnimLoopProps.startY = _start->y;
	sizeAnimLoopProps.endY = _end->y;	
	
	sizeAnimLoopProps.targetValXRef = &width;
	sizeAnimLoopProps.targetValYRef = &height;		
	
	sizeAnimLoopProps.active = true;
	sizeAnimLoopProps.backWhenDone = false;	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void LoopAnimatable2D::startPosAnimationLoop( ofPoint* _start, ofPoint* _end, float _timeSecs, EasingEquations::EaseType _easeType, EasingEquations::EaseType _easeTypeBack )
{
	posAnimLoopProps.startTime = timer.elapsedSec();
	posAnimLoopProps.endTime = posAnimLoopProps.startTime + _timeSecs;
	
	posAnimLoopProps.tweenTime = _timeSecs;	
	
	posAnimLoopProps.easeType = _easeType;
	posAnimLoopProps.easeTypeBack = _easeTypeBack;	
	
	posAnimLoopProps.startX = _start->x;
	posAnimLoopProps.endX = _end->x;
	
	posAnimLoopProps.startY = _start->y;
	posAnimLoopProps.endY = _end->y;	
	
	posAnimLoopProps.targetValXRef = &pos.x;
	posAnimLoopProps.targetValYRef = &pos.y;	
	
	posAnimLoopProps.active = true;	
	posAnimLoopProps.backWhenDone = false;	
}


// Stop the looping animation

//-------------------------------------------------------------------------------------------------------------------------------------
//
void LoopAnimatable2D::stopSizeAnimationLoop()
{	
	sizeAnimLoopProps.active = false;
	sizeAnimLoopProps.backWhenDone = false;		
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void LoopAnimatable2D::stopPosAnimationLoop()
{
	posAnimLoopProps.active = false;
	posAnimLoopProps.backWhenDone = false;	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void LoopAnimatable2D::stopAlphaAnimationLoop()
{
	alphaAnimLoopProps.active = false;
	alphaAnimLoopProps.backWhenDone = false;	
}


//-------------------------------------------------------------------------------------------------------------------------------------
//
float LoopAnimatable2D::timetoLoopingFraction( float _currTime, float _timespan, int* _direction )
{
	float tmpTimeInLoop = fmodf( _currTime, _timespan );	
	float tmpFraction   = tmpTimeInLoop / _timespan;
	
	if( fmodf( _currTime, _timespan*2.0f ) < _timespan ) 
	{ 
		*_direction = 0;
		//cout << "0" << endl; 
	} 
	else 
	{ 
		*_direction = 1;		
		//cout << "1" << endl; 
		tmpFraction =  1.0f - tmpFraction;		
	}
	
	//cout << "tmpTimeInLoop " << tmpTimeInLoop << "  tmpFraction: " << tmpFraction << endl;		

	return tmpFraction;
}

