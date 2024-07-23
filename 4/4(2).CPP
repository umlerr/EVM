#include <dos.h>
#include <conio.h>
#include <bios.h>
#include <stdio.h>

int if_key()
{
	union REGS rg;
	rg.h.ah = 0x01;
	int86(0x16, &rg, &rg);
	unsigned int ZF = 1<<6;
	return rg.x.flags & ZF;
}

int get_key()
{
	union REGS rg;
	rg.h.ah = 0x00;
	int86(0x16, &rg, &rg);
	return rg.h.ah;
}

void print_instruction()
{
    gotoxy(5,1);
    cprintf("To move push the following keys:\n\r    Down - down arrow\n\r    Up - up arrow\n\r    To stop moving - any button except ESC\n\r    Push ESC to exit the program\n");
}

int main(){
    int x = 1,y = 1;
    char key = 0;
    clrscr();
    window(10,12,70,23);
    print_instruction();
    gotoxy(x,y);
    cprintf("*");
    while(key != 1)
    {
	if (if_key() == 0) key = get_key(); //If button pushed
	if (key == 80)
	{
	    while(if_key() != 0)
	    {
		if (if_key == 0) key = get_key();
		if (y == 11) y = 1;
		clrscr();
		y++;
		gotoxy(x, y);
		cprintf("*");
		delay(100);
	    }
	}
	else
	{
		if (key == 72)
		{
			while(if_key() != 0)
			{
				if (if_key == 0) key = get_key();
				if (y == 1) y = 11;
				clrscr();
				y--;
				gotoxy(x, y);
				cprintf("*");
				delay(100);
			}

		}
	}
    }
    clrscr();
    gotoxy(1,1);
    cprintf("That's all. Good luck!");
    key = get_key();
    return 0;
}
