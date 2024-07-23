#include <dos.h>
#include <stdio.h>
#include <conio.h>

void interrupt (*Old) (...);

class UpperKeys
{
	private:
		int status_shift;
		int status_caps;
	public:
		void status_set(int k);
		int status_get() { return (status_shift ^ status_caps); }
};


void UpperKeys::status_set(int key)
{
	if (key == 42) status_shift = 1;
	if (key == 58) status_caps = 1;
	if (key == 42 + 128) status_shift = 0;
	if (key == 58 + 128) status_caps = 0;
}

int getAscii(int scancode, int status)
{
    int row, column;
	int toAscii[4][16] = {
	{0,0,49,50,51,52,53,54,55,56,57,48,0,0,0,0},
	{81,87,69,82,84,89,85,73,79,80,0,0,0,0,65,83},
	{68,70,71,72,74,75,76,0,0,0,0,0,90,88,67,86},
	{66,78,77,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	row = scancode / 16;
	column = scancode - 16 * row;
	if (status == 0)
	{
		if (scancode>=2 && scancode <=11) return toAscii[row][column];
		return (toAscii[row][column] + 32);
	}
	else return toAscii[row][column];
}

void interrupt New (...)
{
	UpperKeys UpKeys;
	int key = 0, status = 0;
	if (UpKeys.status_get() != 1 && UpKeys.status_get() != 0)
	{
		UpKeys.status_set(42+128);
		UpKeys.status_set(58+128);
	}
	key = inportb(0x60);
	if (key == 1)
	{
		setvect(0x09, Old);
		outportb(0x20, 0x20);
	}
	if (key == 28)
	{
		printf("\n");
	}
	UpKeys.status_set(key);
	status = UpKeys.status_get();
	if ((key >= 44 && key <= 50) || (key >= 30 && key <= 38) || (key >= 16 && key <=25) || (key >= 2 && key <=11)) {
		printf("%c", getAscii(key, status));
		delay(100);
		printf("%c", getAscii(key, status));
	}
	outportb(0x20, 0x20);
}

int main ()
{
	clrscr();
	Old = getvect(0x09);
	setvect(0x09, New);
	getch();
	clrscr();
	printf("Thats all");
	getch();
	return 0;
}
