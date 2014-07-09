/* HD44780 Test Program *
 * 2013 Fabian Lesniak  */

#include <avr/io.h>
#include <util/delay.h>

#include "hd44780.h"

int main() {
  init();
  setMode2(true,false,false); //display on, cursor off, cursorFlash off
  setMode3(true,true,false); //8-bit mode, multi-line display, small font
  clearDisplay();
  uchar i,n = 0x21;
  while( 1 ) {
    for( i = 0; i < 32; i++, n++) {
      if( i == 0 )
        setCursorStart();
      if( i == 16 )
        setDDRAMAddress(0x40);
      _delay_ms(100);
      writeRAM(n);
    }
    if( n >= 256 )
      n = 0x21;
  }

  return 0;
}
