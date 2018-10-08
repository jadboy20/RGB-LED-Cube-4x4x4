
#include <Wire.h>

/**
	"Wire" initially has a 32bit buffer size, previous / other libraries out there  demand patching this so that the buffer size is greater than 64.

	we want to avoid patching standard libraries, which means if we have to send each pixel individually, we will.

inspiration:
https://www.freetronics.com.au/pages/cube4-rgb-cube-command-list#.W7r8e2gzY9Y

https://code.google.com/archive/p/colorduino-i2c/

**/

void setup(){
}

void loop(){

	//todo: doStuff();
}


