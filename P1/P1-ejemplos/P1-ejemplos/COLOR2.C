#include <dos.h>
#include <stdio.h>
union REGS regs;

main() {
		int x, y, offset;
		char attr, ch;
		char far *scrn = ( char far * ) 0xB8000000;
		char *message = "texto escrito directamente a la memoria de video";

		// write directly to video memory

		x = 0;
		y = 1;
		attr = 0x82; // green blinking
		offset = (( y * 0x50 + x ) * 2 ) + ( 0 * 0x1000 );
		while ( *message ) {
			scrn[offset] = *message;
			++offset;
			scrn[offset] = attr;
			++offset;
			++message;
		}
}
