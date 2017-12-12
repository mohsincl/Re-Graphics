#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main(){
   char ch;
   int gd = DETECT,gm;  //gdriver,gmode
   int i,x,y,dx=50,dy=20;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;
   outtextxy(x-70, 50, "Ghus Jao Andar :P");
   rectangle(x-dx,y-dy,x+dx,y+dy);
   for(i=0;i<2;i++)
   {
	dx*=2;dy*=2;
	line(x-dx,y,x,y-dy);
	line(x,y-dy,x+dx,y);
	line(x+dx,y,x,y+dy);
	line(x,y+dy,x-dx,y);
	rectangle(x-dx,y-dy,x+dx,y+dy);
   }
   getch();
   closegraph();
   return 0;
}