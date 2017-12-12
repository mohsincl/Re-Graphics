#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main(){
   char ch;
   int gd = DETECT,gm;
   int x,y,radius=50;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;

   while(1)
   {
	outtextxy(x-170, 50, "CIRCLE Zoom in-Zoom out Using Graphics.h in C");
	circle(x, y, radius);
	ch=getch();
	if(ch==27)	exit(0);
	if(ch=='a')	{radius+=1;}
	if(ch=='z')     {radius-=1;}
	cleardevice();
	delay(1);
   }
}