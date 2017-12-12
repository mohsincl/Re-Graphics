#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main(){
   char ch;
   int gd = DETECT,gm;  //gdriver,gmode
   int i,j,x,y,max,x1,sx,ex,l,dx;
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

   /* Initialize center of circle with center of screen */
   x = getmaxx()/2;
   y = getmaxy()/2;
   max=getmaxcolor();
   sx=x-200,ex=x+200,l=5,dx=2;
   for(i=0;i<max;i++)
   {
	setcolor(WHITE);
	outtextxy(x-120, 50, "Dashed Line Using Graphics in C");
	setcolor(i+1);
	for(x1=sx;x1<=ex;x1+=(l+dx))	line(x1,y,x1+l,y);
	//setcolor((i+2)%max+1);
	//for(x1=sx;x1<=ex;x1+=(l+dx))	line(x1,y+20,x1+l,y+20);
	//setcolor((i+3)%max+1);
	//for(x1=sx;x1<=ex;x1+=(l+dx))	line(x1,y+40,x1+l,y+40);

	getch();
   }
   closegraph();
   return 0;
}
