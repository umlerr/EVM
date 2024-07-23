#include <dos.h>
#include <iostream.h>
#include <conio.h>

const char *colors(int i)
{
	const char *vocabulary[] = {"BLACK", "BLUE", "GREEN", "CYAN",
	"RED", "MAGENTA", "BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE",
	"LIGHTGREEN", "LIGHTCYAN","LIGHTRED", "LIGHTMAGENTA","YELLOW","WHITE"};
	return vocabulary[i];
}

void scroll(int lr,int lc,int rr, int rc)
{
    int S = 1;
	union REGS r;
	r.h.ah = 6;
	r.h.al = S;
	r.h.ch = lc;
	r.h.cl = lr;
	r.h.dh = rc;
	r.h.dl = rr;
	int86(0x10,&r,&r);

}

void print(int x1,int y1,int x2,int y2)
{
    const char *text, *back;
    int text_mask=15, back_mask=112;
    float T = 0.3;
    for(int i=0;i<255;i++)
    {
        delay(T*1000);
        textattr(i);

        back = colors((i&back_mask)>>4);
        text = colors(i&text_mask);

        cprintf(back);
        cprintf("  ");
        cprintf(text);
        cprintf("                                                            \r");
        scroll((x1-1),(y1-1),x2,y2);
    }
}

int main()
{
    int x1 = 10, y1 = 12, x2 = 70, y2 = 23;
    clrscr();
    scroll(0,0,100,100);
    window(x1,y1,x2,y2);
    print(x1,y1,x2,y2);
    return 0;
}


