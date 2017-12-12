#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main(){
   char ch;
   int gd = DETECT,gm;  //gdriver,gmode
   int i,x,y,xrad=200,yrad=100;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;
   outtextxy(x-100, 50, "Ellipse Using Graphics in C");
   line(x-220,y,x+220,y);
   line(x,y-120,x,y+120);
   ellipse(x,y,0,360,xrad,yrad);
   for(i=EMPTY_FILL;i<USER_FILL;i++)
   {
	setfillstyle(i,RED);  //getmaxcolor()
	fillellipse(x,y,xrad,yrad);
	getch();
   }
   closegraph();
   return 0;
}