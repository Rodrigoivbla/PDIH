#include <stdio.h>
#include <dos.h>

void mi_getchar(){
	 union REGS inregs, outregs;
	 //int caracter;

	 inregs.h.ah = 1;
	 int86(0x21, &inregs, &outregs);

	 //caracter = outregs.h.al;
	 //return caracter;
}

void mi_exit(){
	 union REGS inregs, outregs;
	 inregs.x.ax = 0x4C00;
	 int86(0x21, &inregs, &outregs);
}

void main(){
	printf("\nPulsa una tecla para terminar...  ");

	mi_getchar();

   	mi_exit();
}
