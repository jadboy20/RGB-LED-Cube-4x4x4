#include <Wire.h>

#define I2C_ADDR 0x05

void setup()
{
  //unsigned char whiteBalVal[3] = {33,63,63}; // for LEDSEE 6x6cm round matrix
  //Colorduino.SetWhiteBal(whiteBalVal);
  Wire.begin(I2C_ADDR); 
  //Wire.onReceive(receiveEvent); 
}

/****************************************************
Main Functions zone
****************************************************/

void loop()
{
  //1 pixel = 3 bytes B00000000 B00000000 B00000000. 
  //We send R then G then B bytes as 3 separate transfers
  //This is because if we make the I2C buffer too large, we run out of SRAM for other things on our master Arduino

  if (Wire.available()) { //when buffer full, process data. 66 =  start byte + colour + 64 pixel data + end byte

    // error check - make sure our data starts with the right byte
    if (Wire.receive() != START_OF_DATA) {
      //else handle error by reading remaining data until end of data marker (if available)
      while (Wire.available()>0 && Wire.receive()!=END_OF_DATA)
			;
      return;
    }

    byte c = Wire.receive(); //read our color byte so we know if these are the R, G or B pixels.
    if (c == 0){
      for (byte x = 0; x < 8; x++){
        for (byte y = 0; y < 8; y++){
           //PixelRGB *p = &(*Colorduino.curWriteFrame)[x][y];
           //p->r = Wire.receive();
        }
      }
    } //etc etc etc
    //read end of data marker
    if (Wire.receive()==END_OF_DATA) {
    }
  }
}


//=============HANDLERS======================================

//get data from master - HINT: this is a ISR call!
//HINT2: do not handle stuff here!! this will NOT work
//collect only data here and process it in the main loop!
void receiveEvent(int numBytes) {
  //do nothing here
}
