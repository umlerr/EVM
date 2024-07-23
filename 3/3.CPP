#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<iostream.h>


const double pi = 3.1415926535;
const double a = pi / 2;
const double b = pi * 5;
const double size = 32;

double f(double x)
{
	return (pow(sin(x), 2) - pow(cos(x), 3));
}

int set_screen()
{
	int graph_driver = DETECT;
	int graph_mode;
	initgraph(&graph_driver, &graph_mode, "C:\\TC\\BGI");
	int error_code;
	error_code = graphresult();
	if (error_code != grOk)
	{
		char* error = grapherrormsg(error_code);
		getch();
		printf("%s\n", error);
		return error_code;
	}
	setviewport(0, 0, getmaxx(), getmaxy(), 0);
	return 0;
}

void print_cross()
{
	const int centerX = getmaxx()/10, centerY = getmaxy()/2;
	char *str;

	settextstyle(SANS_SERIF_FONT, HORIZ_DIR , 1);
	setlinestyle(0,0,3);

	line(centerX, 0, centerX, getmaxy());
	line(0, centerY, getmaxx(), centerY);

	outtextxy(centerX - 15, centerY, "0");

	for(int i = 1; i < 20;i++)
	{
		outtextxy(centerX-5, getmaxy() - i*size + 3,"-");
		outtextxy(centerX + i*size*pi/2, centerY - 13,"|");
	}
	for(i = 1; i < 8; i++)
	{
		sprintf(str,"%d",i);
		outtextxy(centerX - 20, centerY - i*size - 15,str);
	}
	for(i = -1; i > -8; i--)
	{
		sprintf(str,"%d",i);
		outtextxy(centerX - 30, centerY - i*size -10,str);
	}
	settextstyle(DEFAULT_FONT, VERT_DIR, 1);
	for(i = 1; i < 10; i=i+2)
	{
		if (i!=1) sprintf(str, "%dpi/2",i);
		else sprintf(str, "pi/2",i);
		outtextxy(centerX + i*size*pi/2, centerY + 15, str);
		if (i!=1) sprintf(str, "%dpi",i);
		else sprintf(str, "pi",i);
		outtextxy(centerX + i*size*pi, centerY + 15, str);
	}
}

float print_f()
{
	char *str;
	const int centerX = getmaxx()/10, centerY = getmaxy()/2;
	double step = (b - a) / 50000;
	double currentX = a, currentY = f(currentX);
	double previousX = currentX, previousY = currentY;
	float maxY = currentY;

	setviewport(centerX, centerY, getmaxx(), getmaxy(),0);

	while (currentX < b)
	{
		currentX += step;
		currentY = f(currentX);
		if (currentY > maxY) maxY = currentY;
		line(previousX * size, -previousY * size, currentX * size, -currentY * size);
		previousX = currentX;
		previousY = currentY;
	}
	return maxY;
}

void print_maxY(float maxY)
{
	char *str;
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR , 1);
	setviewport(getmaxx()-120, 0, getmaxx(), 120,0);
	sprintf(str,"Max: y(x)%.2f",maxY);
	outtextxy(0, 0,str);
}

int main(void)
{
	clrscr();
	float maxY;
	int error_code = set_screen();

	if (error_code<0) return error_code;

	print_cross();
	maxY = print_f();
	print_maxY(maxY);

	getch();
	closegraph();
	return 0;
}
