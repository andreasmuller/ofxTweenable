#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#include "tweenableSquare.h"
#include "tweenableText.h"

class testApp : public ofBaseApp  {

	public:

		void setup();
		void update();
		void draw();
	
		void moveAll();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		vector< tweenableSquare* > squares;

		tweenableSquare textBG;
		vector< tweenableText* > textLines;	
	
		bool toTop;
	
		ofTrueTypeFont myFont;
};

#endif
