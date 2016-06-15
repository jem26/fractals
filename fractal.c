//Jamie Maher
//Lab9
//fractals.c
#include <stdio.h>
#include <math.h>
#include "gfx4.h"
#define PI 3.14159265358979323846

void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);
void mytriangledrawingfunction(int x1, int y1, int x2, int y2, int x3, int y3 );
void shrinking(int x1, int y1, int size);
void spiralsquare(int r, double theta);
void circularlace(int xc, int yc, int r);
void snowflake(int xc, int yc, int r);
void tree(int x, int y, int l, double theta);
void fern(int xc, int yc, int l, double theta);
void manyspiral(int r, double theta, int xc, int yc);

int main()
{
	int wd=800, ht=800;
	gfx_open(wd, ht, "Fractals");
	char c;

	while (c!='q')
	{
		c=gfx_wait();
		gfx_clear();
		switch (c)
		{
			case '1':
			sierpinski(wd*0.9, ht*0.1, wd*0.1, ht*0.1, wd*0.5, ht*0.9);
			break;
			case '2':
			shrinking(wd/4, ht/4, wd/2);
			break;
			case '3':
			spiralsquare(350, 0);
			break;
			case '4':
			gfx_circle(400, 400, 250);
			circularlace(400, 400, 250);
			break;
			case '5':
			snowflake(400, 400, 250);
			break;
			case '6':
			gfx_line(400, 700, 400, 400);
			tree(400, 400, 100, -PI/2);
			break;
			case '7':
			fern(400, 700, 400, -PI/2);
			break;
			case '8':
			manyspiral(500, 1, 400, 400);
			break;

		}
	}
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
   // Base case 
   if( abs(x2-x1) < 2 ) return;

   // Draw the triangle
   mytriangledrawingfunction( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
   sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
   sierpinski((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
   sierpinski((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);
}

void mytriangledrawingfunction(int x1, int y1, int x2, int y2, int x3, int y3)
{
	gfx_line(x1, y1, x2, y2);
	gfx_line(x1, y1, x3, y3);
	gfx_line(x2, y2, x3, y3);
}

void shrinking(int x1, int y1, int size)
{
	//Base case
	if(abs(size)<1) return;

	// Draw the squares
	gfx_rectangle(x1, y1, size, size);

	//Recursive Calls
	shrinking(x1-size/5, y1-size/5, size/2.5);
	shrinking(x1+size-size/5, y1-size/5, size/2.5);
	shrinking(x1-size/5, y1+size-size/5, size/2.5);
	shrinking(x1+size-size/5, y1+size-size/5, size/2.5);
}

void spiralsquare(int r, double theta)
{
	//Base case
	if(abs(r)<3) return;

	//draw the squares
	gfx_rectangle(400+(r*cos(theta)), 400+(r*sin(theta)), r/5, r/5);
	
	//recursive calls
	spiralsquare(r/1.05, theta+0.5);
}

void circularlace(int xc, int yc, int r)
{
	//base case
	if(r<2) return;

	//draw the circles
	double theta=(2*PI)/6;
	int x, y, i;
	for (i=0; i<6; i++)
	{
		x=xc+r*cos(theta*i);
		y=yc+r*sin(theta*i);
		gfx_circle(x, y, r/3);
		circularlace(x, y, r/3);
	}

}

void snowflake(int xc, int yc, int r)
{
	//base case
	if(r<1) return;
	double theta=(2*PI)/5;
	int x, y, i;

	//draw flakes and recurse
	for (i=0; i<5; i++)
	{
		x=xc+r*cos(theta*i);
		y=yc+r*sin(theta*i);
		gfx_line(xc, yc, x, y);
		snowflake(x, y, r/3);
	}
}

void tree(int x, int y, int l, double theta)
{
	//base case
	if(l<1) return;
	int x1, y1, x2, y2;

	//draw branches
	x1=x+l*cos(theta-(PI/5));
	y1=y+l*sin(theta-(PI/5));
	x2=x+l*cos(theta+(PI/5));
	y2=y+l*sin(theta+(PI/5));
	gfx_line(x, y, x1, y1);
	gfx_line(x, y, x2, y2);

	//recursive calls
	tree(x1, y1, l/1.4, theta-(PI/4));
	tree(x2, y2, l/1.4, theta+(PI/4));
}

void fern(int xc, int yc, int l, double theta)
{
	//base case
	if(l<2) return;
	int i, x, y; 

	//draw branches
	for (i=1; i<=4; i++)
	{
		x=xc+(i*l/4)*cos(theta);
		y=yc+(i*l/4)*sin(theta);
		if (i==4)
		{
			gfx_line(x, y, xc, yc);
		}

		//recursive calls
		fern(x, y, l/3, theta-(PI/5));
		fern(x, y, l/3, theta+(PI/5));

	}

}

void manyspiral(int r, double theta, int xc, int yc)
{
	int x, y;
	gfx_point(xc, yc);
	//Base case
	if(abs(r)<1) return;

	//draw the points
	x=xc+r*cos(theta);
	y=yc+r*sin(theta);
	gfx_point(x, y);
	
	//recursive calls
	manyspiral(r/3, theta, x, y);
	manyspiral(r/1.1, theta+.5, xc, yc);
}




