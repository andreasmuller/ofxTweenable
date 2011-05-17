/*
 *  SpriteProperties2D.h
 *  JagermeisterApp
 *
 *  Created by Andreas Muller on 28/08/2009.
 *  Copyright 2009 Nanika. All rights reserved.
 *
 */


#ifndef _A_SPRITE_PROPERTIES_2D_H
#define _A_SPRITE_PROPERTIES_2D_H

#include "ofMain.h"
//#include "../Color/AColor.h"

class SpriteProperties2D
{
		
	public:
		
		ofPoint pos;
		
		float width;
		float height;
	
		float angle;
	
		float alpha;
	
		//AColor color;
		ofPoint color;	
};


#endif //_A_SPRITE_PROPERTIES_2D_H
