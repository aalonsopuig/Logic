/* Programa en C que representa la se¤al digital que entra por el pin 15  */
/* del puerto paralelo. La representaci¢n comienza cuando la se¤al cambia */
/* de nivel. El pin 15 es el bit n£mero 3 del puerto 379h (status port).  */
/*                  El programa finaliza al pulsar ESC.                   */

#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <dos.h>

void retardo(int ret);

main()
{
	int dispgraf=DETECT,modograf;
	int i,j,y1,y2,tecla;
	char grafica[6][640];	/* Array en el que guardaremos los datos. */
	char ini;

	/* Iniciamos el modo gr fico: */
	initgraph(&dispgraf,&modograf,"..\\bgi");

	/* Selecciona los colores de las l¡neas y el fondo: */
	setbkcolor(BLACK);
	setcolor(WHITE);

	do {
		ini = inportb(0x379) & 8;
		outtextxy(10,10,"Esperando se¤al...");

		/* Esperamos a que la se¤al en el pin 15 cambie de valor. */
		while ((inportb(0x379) & 8) == ini);

		/* Muestreamos la se¤al del pin 15 y la vamos guandando. */
		for (i=0;i<6;i++)
			for(j=0;j<640;j++) {
				retardo(10);
				grafica[i][j] = inportb(0x379);
			}

		cleardevice();	/* Borramos la pantalla. */

		/* Representamos la se¤al almacenada en el array. */
		for (i=0;i<6;i++)
			for (j=0;j<640;j++) {
				y1 = i*70 + 100 - (grafica[i][j] & 8)*2;
				line(j-1, y2,j-1, y1);
				y2 = y1;
			}

		/* Si hay una tecla pulsada, la guardamos. */
		if(kbhit()) tecla = getch();

	/* Si la tecla es ESC, salimos. */
	} while(tecla != 27);

	closegraph();		/* Volvemos a modo texto. */
}

/* Un peque¤o retardo por bucle: */
void retardo(int ret)
{
	int i;
	for(i=0;i<=ret;i++) {}
}