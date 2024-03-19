#include <stdio.h>
#include <dos.h>

unsigned char cfondo=0;
unsigned char ctexto=1;

void escribir_char_con_color(){
	union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = '*';    //una funcion más general debe recibir el caracter a imprimir
	inregs.h.bl = cfondo << 4 | ctexto;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
	return;
}

int main(){

	printf("\nc.fondo=rojo, c.texto=azul => ");
	cfondo=4; ctexto=1; // cfondo=4=rojo , ctexto=1=azul
	escribir_char_con_color(); 

	printf("\nc.fondo=verde, c.texto=negro => ");
	cfondo=2; ctexto=0; // cfondo=2=verde , ctexto=0=negro
	escribir_char_con_color(); 
	
	//printf("cosas en color");

	return 0;
}
