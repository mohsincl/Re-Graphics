#include <graphics.h>
#include <dos.h>
union REGS i,o;
void detect_mouse ()
{
	i.x.ax = 0;
	int86 (0X33,&i,&o);   //invoke interrupt
	if (o.x.ax == 0)  printf ("\nMouse Failed To Initialize");
	else		  printf ("\nMouse was Succesfully Initialized");
}

show_mouse()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

hide_mouse()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}

get_mouse_pos(int *x,int *y,int *button)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*x=o.x.cx;
	*y=o.x.dx;
	*button=o.x.bx&1;
}

main()
{
	int gdriver = DETECT, gmode, errorcode,button,x1,y1,x2,y2;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	detect_mouse();

	outtextxy(175,50,"Engineering chodo, Painting Karo :P ");
	setfillstyle(SOLID_FILL,RED);
	rectangle(270,400,300,430);
	floodfill(285,415,WHITE);
	setfillstyle(SOLID_FILL,GREEN);
	rectangle(300,400,330,430);
	floodfill(315,415,WHITE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(330,400,360,430);
	floodfill(345,415,WHITE);

	while(!kbhit())
	{
		show_mouse();
		get_mouse_pos(&x1,&y1,&button);
		x2=x1;
		y2=y1;
		while(button==1)
		{
			if(x1>270 &&x1<300 && y1>400 && y1<430) {setcolor(RED);}
			if(x1>300 &&x1<330 && y1>400 && y1<430) {setcolor(GREEN);}
			if(x1>330 &&x1<360 && y1>400 && y1<430) {setcolor(BLUE);}

			hide_mouse();
			line(x1,y1,x2,y2) ;
			x1=x2;
			y1=y2;
			get_mouse_pos(&x2,&y2,&button);
		}
	}

}