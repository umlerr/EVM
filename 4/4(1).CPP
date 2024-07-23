#include <dos.h>
#include <conio.h>
#include <bios.h>

int main()
{
    int key, x = 1, y = 1, status;
    window(10, 12, 70, 23);
    clrscr();
    while (1)
    {
        gotoxy(x, y);
        cprintf("*");
        while (bioskey(1) == 0);
        key = bioskey(0);
        if (key == 20480)
        {
            while(bioskey(1)==0)
            {
                if(y==11) y==0;
                clrscr();
                y++;
                gotoxy(x, y);
                cprintf("*");
                delay(100);
            }
        }
        if (key == 18432)
        {
            while(bioskey(1)==0)
            {
                if(y==1) y==12;
                clrscr();
                y--;
                gotoxy(x, y);
                cprintf("*");
                delay(100);
            }
        }
        if (key == 283) break;
    }
    return 0;
}
