#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main(){
   char ch;
   int gd = DETECT,gm;
   int x,y,x1,y1,radius=50,dir=0,speed=2;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   /* Initialize center of circle with center of screen */
   x1 = getmaxx()/2-100;
   y1 = getmaxy()/2;
   x=x1;
   y=y1;
   while(1)
   {
	outtextxy(x1-50, 50, "CIRCLE Rolling Using Graphics in C");
	line(x1,y1+radius,x1+200,y1+radius);
	circle(x, y, radius);
	if(dir==2)    break;
	if(dir==0)    //UP
	{
		x+=speed;
		if(x>x1+200) {dir=1;x-=speed;y+=(2*radius);}
	}
	else          //DOWN
	{
		x-=speed;
		if(x<x1) {dir=2;x+=speed;y-=(2*radius);}
	}
	delay(30);
	cleardevice();
   }
   getch();
   closegraph();
   return 0;
}