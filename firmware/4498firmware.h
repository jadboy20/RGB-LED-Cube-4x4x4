#ifndef _4498FIRMWARE_H__
#define _4498FIRMWARE_H__

#define BIT_DEPTH 8
#define X_SIZE 4
#define Y_SIZE 4
#define Z_SIZE 4

#define open_line0	{PORTB=0x01;}
#define open_line1	{PORTB=0x02;}
#define open_line2	{PORTB=0x04;}
#define open_line3	{PORTB=0x08;}
#define open_line4	{PORTB=0x10;}
#define open_line5	{PORTB=0x20;}
#define open_line6	{PORTD=0x08;}
#define open_line7	{PORTD=0x10;}
#define close_all_lines	{PORTD=0x00;PORTB=0x00;}

#define RST_BIT 0x04
#define LAT_BIT 0x02
#define SLB_BIT 0x01
#define SCL_BIT 0x40
#define SDA_BIT 0x80

#define RST PORTC
#define LAT PORTC
#define SLB PORTC
#define SDA PORTD
#define SCL PORTD

#define LED_RST_SET RST|=RST_BIT
#define LED_RST_CLR RST&=~RST_BIT
#define LED_SDA_SET SDA|=SDA_BIT
#define LED_SDA_CLR SDA&=~SDA_BIT
#define LED_SCL_SET SCL|=SCL_BIT
#define LED_SCL_CLR SCL&=~SCL_BIT
#define LED_LAT_SET LAT|=LAT_BIT
#define LED_LAT_CLR LAT&=~LAT_BIT
#define LED_SLB_SET SLB|=SLB_BIT
#define LED_SLB_CLR SLB&=~SLB_BIT

class Pixel {
public:
  unsigned short red;
  unsigned short grn;
  unsigned short blu;

  Pixel(unsigned short r, unsigned short g, unsigned short b):
  (blu=b,grn=g,red=r){};

  Pixel(){
    red = 0; grn = 0; blu = 0;
  };

  Pixel(Pixel* otherpixel){
    red = otherpixel.red;
    grn = otherpixel.grn;
    blu = otherpixel.blu;
  }

};


class RGBCube4_class {
  public:
    Pixel bufA[X_SIZE*Y_SIZE*Z_SIZE];
    Pixel bufB[X_SIZE*Y_SIZE*Z_SIZE];

    RGBCube4(){
    }

    void setPage

    void swapBuffers();

  private:
    void init();
    void ledInit();
    void ioInit();
    void timerInit();
};

extern RGBCube4_class RGBCube4;

#endif
