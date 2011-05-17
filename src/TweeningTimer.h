//
//  TweeningTimer.h
//
//  Created by Andreas Müller on 17/05/2011.
//

#pragma once

// ---------------------------------------------------------------------------------------------------------------------------------------------------
//
class TweeningTimer
{
	
public:
	
	TweeningTimer()
	{
		startTime = 0.0f;
	}
	
	~TweeningTimer() 
	{
	}
	
	void start()
	{
		startTime = ofGetElapsedTimef();
	}
	
	float elapsedSec()
	{
		return ofGetElapsedTimef() - startTime;
	}
	
	float startTime;
	
private:
	
};
