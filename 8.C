#include <graphics.h>
#include <dos.h>
union REGS i,o;
void detect_mouse ()
{
	i.x.ax = 0;
	int86 (0X33,&i,&o);   //invoke interrupt
	if (o.x.ax == 0)
		printf ("\nMouse Failed To Initialize");
	else
		printf ("\nMouse was Succesfully Initialized");
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
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	detect_mouse ();
	outtextxy(230,400,"Press any key to exit....");
	while(!kbhit())
	{
		show_mouse();
		get_mouse_pos(&x1,&y1,&button);
		x2=x1;
		y2=y1;
		while(button==1)
		{
			hide_mouse();
			line(x1,y1,x2,y2) ;
			x1=x2;
			y1=y2;
			get_mouse_pos(&x2,&y2,&button);
		}
	}
}