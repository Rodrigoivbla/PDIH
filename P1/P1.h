#include <stdio.h>
#include <dos.h>

typedef unsigned char BYTE;

BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

// Interrupción empleada
void pausa(void){
    union REGS inregs, outregs;
    inregs.h.ah = 0;
    int86(0x16, &inregs, &outregs);
}

void gotoxy(int x, int y){
	union REGS inregs, outregs;
	inregs.h.ah = 0x02;
	inregs.h.bh = 0x00;
	inregs.h.dh = x;
	inregs.h.dl = y;
	int86(0x10,&inregs,&outregs);
	return;
}

void setcursortype(int tipo_cursor){
    union REGS inregs, outregs;
    inregs.h.ah = 0x01;
    
    switch(tipo_cursor){
        case 0: //invisible
            inregs.h.ch = 010;
            inregs.h.cl = 000;
            break;

        case 1: //normal
            inregs.h.ch = 010;
            inregs.h.cl = 010;
            break;

        case 2: //grueso
            inregs.h.ch = 000;
            inregs.h.cl = 010;
            break;
    }

    int86(0x10, &inregs, &outregs);
    return;
}

void setvideomode(BYTE modo)
{
    union REGS inregs, outregs;
    inregs.h.ah = 0x00;
    inregs.h.al = modo;
    int86(0x10, &inregs, &outregs);
    return;
}

int getvideomode()
{
    union REGS inregs, outregs;
    int m;
    inregs.h.ah = 15;
    int86(0x10, &inregs, &outregs);

    m = outregs.h.al;
    return m;
}

void textcolor(BYTE ctexto)
{
    union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = '*';
	inregs.h.bl = ctexto;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;
}

void textbackground(BYTE cfondo)
{
    union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = ' ';    
	inregs.h.bl = cfondo << 4;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;
}

void clrscr(void)
{
    union REGS inregs, outregs;
    inregs.h.ah = 6;
    inregs.h.al = 0;
    inregs.h.dh = 25;
    inregs.h.dl = 80;
    inregs.h.bh = 0x00;
    inregs.x.cx = 0x00;
    int86(0x10, &inregs, &outregs);
    return;
}

void cputchar(BYTE c, BYTE ctexto)
{
    union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = c;
	inregs.h.bl = ctexto;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;
}

void getche(void)
{
    union REGS inregs, outregs;
    inregs.h.ah = 0;
    int86(0x16, &inregs, &outregs);
    cputchar(outregs.h.al, 15);
    return;
}

void paintrectangle(int xa, int ya, int xb, int yb, BYTE ctexto, BYTE cfondo)
{
    union REGS inregs, outregs;
    int i, j;

    for(i = xa; i <= xb; ++i)
    {
        for(j = ya; j <= yb; ++j)
        {
            gotoxy(i, j);
            textcolor(ctexto);
            textbackground(cfondo);
        }
    }
    return;
}

void drawfigure(void)
{
    union REGS inregs, outregs;
    setvideomode(4);
    printf("\r\nFuncion drawfigure\r\n");
	gotoxy(10, 10); cputchar('(', 15);
    gotoxy(10, 11); cputchar('\\', 15);
    gotoxy(10, 12); cputchar('_', 15);
    gotoxy(10, 13); cputchar('_', 15);
    gotoxy(10, 14); cputchar('/', 15);
    gotoxy(10, 15); cputchar(')', 15);
    gotoxy(11, 10); cputchar('(', 15);
    gotoxy(11, 11); cputchar('=', 15);
    gotoxy(11, 12); cputchar('\'', 15);
    gotoxy(11, 13); cputchar('.', 15);
    gotoxy(11, 14); cputchar('\'', 15);
    gotoxy(11, 15); cputchar('=', 15);
    gotoxy(11, 16); cputchar(')', 15);
    gotoxy(12, 10); cputchar('(', 15);
    gotoxy(12, 11); cputchar('"', 15);
    gotoxy(12, 12); cputchar(')', 15);
    gotoxy(12, 13); cputchar('_', 15);
    gotoxy(12, 14); cputchar('(', 15);
    gotoxy(12, 15); cputchar('"', 15);
    gotoxy(12, 16); cputchar(')', 15);
	return;
}