#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int main(){
   char ch;
   int gd = DETECT,gm;  //gdriver,gmode
   int i,x,y,x1,y1,x2,y2,rad=100;
   float alpha=0.0;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;
   x1=x,y1=y,x2=x+rad*cos(alpha),y2=y+rad*sin(alpha);
   while(1)
   {
	outtextxy(x-50, 50, "De Ghumake :P");
	circle(x,y,rad);
	line(x1,y1,x2,y2);
	ch=getch();
	if(ch==27)	exit(0);
	if(ch==0)
	{
		ch=getch();
		if(ch==77)	//Right Key
		{
			alpha+=0.05;
			x2=x+rad*cos(alpha);
			y2=y+rad*sin(alpha);
		}
		if(ch==75)	//Left Key
		{
			alpha-=0.05;
			x2=x+rad*cos(alpha);
			y2=y+rad*sin(alpha);
		}

	}
	delay(1);
	cleardevice();
   }
}
