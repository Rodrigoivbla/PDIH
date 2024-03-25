#include "P1.h"

int main(){

    int m;
    BYTE ctexto = 0;
    BYTE cfondo = 1;

    cprintf("\r\nFuncion gotoxy\r\n");
	gotoxy(15,7);
    pausa();

    cprintf("\r\nFuncion setcursortype\r\n");
    setcursortype(2);
    pausa();    

    setvideomode(MODOGRAFICO);
    printf("\r\nFuncion setvideomode\r\n");
    pausa();

    setvideomode(MODOTEXTO);
    pausa();

    cprintf("\r\nFuncion getvideomode\r\n");
    m = getvideomode();
    pausa();

    if(m == 3)
        printf("Modo texto\n");

    if(m == 4)
        printf("Modo video\n");

    cprintf("\r\nFuncion textcolor\r\n");
    textcolor(ctexto);
    pausa();

    cprintf("\r\nFuncion textbackground\r\n");
    textbackground(cfondo);
    pausa();

    cprintf("\r\nFuncion clrscr\r\n");
    pausa();
    clrscr();
    pausa();

    cprintf("\r\nFuncion cputchar\r\n");
    cputchar('c', 2);
    pausa();

    cprintf("\r\nFuncion getche\r\n");
    getche();
    pausa();

    cprintf("\r\nFuncion paintrectangle\r\n");
    paintrectangle(5, 10, 20, 50, 2, 3);
    pausa();

    drawfigure();
    pausa();

    setvideomode(MODOTEXTO);
    pausa();

	return 0;
}