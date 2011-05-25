#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup()
{

	myFont.loadFont("DIN.otf", 24 );
	
	float squareWidth  = 50.0f;
	float squareHeight = 50.0f;	
	
	ofPoint tmpPos;
	ofPoint tmpCol;	
	
	// create some squares
	for( int i = 0; i < 10; i++ )
	{
		tweenableSquare* tmpSquare = new tweenableSquare();
		
		tmpCol.set( ofRandomuf(), ofRandomuf(), ofRandomuf() );
	
		tmpSquare->init( -100.0f, -100.0f, squareWidth, squareHeight, &tmpCol );
		tmpSquare->alpha = 0.0f;
	
		squares.push_back( tmpSquare );
	}
	
	
	// fade the squares up and move them into position
	tmpPos.set( 45.0f, 130.0f, 0.0f );
	for( unsigned int i = 0; i < squares.size(); i++ )
	{
		squares.at(i)->tweenAlphaTo( 1.0f,	i * 0.5f ); // fade to 1.0f alpha, taking longer and longer to do it.
		squares.at(i)->tweenPosTo( tmpPos.x, tmpPos.y,	i * 0.1f );
		tmpPos.x += squareWidth + 5.0f;
	}
	
	
	toTop = false;
	
	
	
	tmpCol.set( 0.0f, 0.0f, 0.0f );
	
	tweenableText* topText = new tweenableText();
	topText->init( 30.0f, 50.0f, "ofxTweenable", &myFont, &tmpCol );

	tweenableText* bottomText = new tweenableText();
	bottomText->init( 30.0f, 80.0f, "Hello tweened world!", &myFont, &tmpCol );	
	
	tmpCol.set( 1.0f, 1.0f, 1.0f );
	textBG.init( 190.0f, 55.0f, 0.0f, 0.0f, &tmpCol );
	
	textLines.push_back( topText );
	textLines.push_back( bottomText );
	
	// set up the intro animation
	textBG.tweenSizeTo(	340.0f, 70.0f, 0.8f, EasingEquations::EASE_OUT_ELASTIC, 1.0f ); // wait one second before animating
	
	topText->alpha = 0.0f;
	topText->tweenAlphaTo( 1.0f, 1.0f, EasingEquations::EASE_LINEAR, 2.0f );
	
	bottomText->alpha = 0.0f;	
	bottomText->tweenAlphaTo( 1.0f, 1.0f, EasingEquations::EASE_LINEAR, 3.0f );
	
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{

	// Generally in a super simple situation you would just derive all your objects from the same 
	// baseclass (that inherits from Tweenable2D) and then push them all into one big list
	
	for( unsigned int i = 0; i < squares.size(); i++ )
	{
		squares.at(i)->draw();
	}
	
	textBG.draw();
	
	for( unsigned int i = 0; i < textLines.size(); i++ )
	{
		textLines.at(i)->draw();
	}	

}


//--------------------------------------------------------------
void testApp::moveAll()
{
	float targetY = 470.0f;
	
	if( toTop )
	{
		targetY = 130.0f;
		toTop = false;
	}
	else
	{
		toTop = true;
	}
	
	
	squares.at(0)->tweenPosTo( squares.at(0)->pos.x, targetY, 2.0f );
	squares.at(1)->tweenPosTo( squares.at(1)->pos.x, targetY, 2.0f, EasingEquations::EASE_INOUT_QUART );
	squares.at(2)->tweenPosTo( squares.at(2)->pos.x, targetY, 2.0f, EasingEquations::EASE_IN_QUART );
	squares.at(3)->tweenPosTo( squares.at(3)->pos.x, targetY, 2.0f, EasingEquations::EASE_IN_SINE );
	squares.at(4)->tweenPosTo( squares.at(4)->pos.x, targetY, 2.0f, EasingEquations::EASE_INOUT_SINE );
	squares.at(5)->tweenPosTo( squares.at(5)->pos.x, targetY, 2.0f, EasingEquations::EASE_INOUT_EXPO );
	squares.at(6)->tweenPosTo( squares.at(6)->pos.x, targetY, 2.0f, EasingEquations::EASE_INOUT_CIRCULAR );
	squares.at(7)->tweenPosTo( squares.at(7)->pos.x, targetY, 2.0f, EasingEquations::EASE_OUT_ELASTIC );	
	squares.at(8)->tweenPosTo( squares.at(8)->pos.x, targetY, 2.0f, EasingEquations::EASE_OUT_BACK );
	squares.at(9)->tweenPosTo( squares.at(9)->pos.x, targetY, 2.0f, EasingEquations::EASE_OUT_BOUNCE );	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{


}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
	moveAll();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
	
}

