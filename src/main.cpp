#include <iostream>
#include "argon.h"
using namespace std;
int sx, sy;
void eventHandler(Argon* argon, Event e) {
	/*
	EVENTS
	EVENT LAYOUT
	{
		EventType type (enum listed below)
		Mouse mouse {x,y,which,down}
		Keyboard keyboard {key, lshift, rshift, lctrl, rctrl, lalt, ralt, lmeta, rmeta, numlock, capslock, ctrl, shift, alt, meta};
		Wheel wheel {x,y.dir} (x & y are deltas and dir is a bool where false is normal and 1 is inverted)
	}
	=======================
	LOAD
	SHOWN
	HIDDEN
	EXPOSED
	MOVED
	RESIZED
	SIZE_CHANGED
	MINIMIZED
	MAXIMIZED
	RESTORED
	MOUSEENTER
	MOUSELEAVE
	KEYBOARDFOCUS
	KEYBOARDBLUR
	CLOSE
	TAKE_FOCUS
	HIT_TEST
	MOUSEUP
	MOUSEDOWN
	MOUSEMOVE
	MOUSEWHEEL
	CLICK
	DBLCLICK
	KEYUP
	KEYDOWN
	QUIT
	*/
	//ECHO EVEnt
	switch(e.type) {
		case LOAD: {
			argon->setColor(255,255,255);
			break;
		}
		case KEYDOWN: {
			if(strncmp(e.keys.key,"SPACE",100)) {
				cout << "Taking Screenshot" << endl;
				argon->screenshot();
			}
			break;
		}
		case MOUSEMOVE: {
			if(e.mouse.down) {
				argon->line(sx, sy, e.mouse.x,e.mouse.y);
				sx = e.mouse.x;
				sy = e.mouse.y;
			}
			break;
		}
		case MOUSEDOWN: {
			sx = e.mouse.x;
			sy = e.mouse.y;
		}
		default: break;
	}
}
void program(Argon* argon) {

}
int main(int argc, char* argv[]) {
	Argon argon("Test Window",					//WINDOW NAME
	 						60,											//FPS
							ARGON_BASIC|ARGON_RESIZEABLE,						//FLAGS
							&eventHandler,
							&program
						);
	return 0;
}
