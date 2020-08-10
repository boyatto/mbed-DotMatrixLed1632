#include <mbed.h>

DigitalOut Sin1(D2);
DigitalOut Sin2(D3);
DigitalOut Sin3(D4);
DigitalOut LedClock(D5);
DigitalOut LedLatch(D6);
DigitalOut Led_Enable(D7);

void shiftout3(int data1, int data2, int data3);

 int moji1[] = {0x9c06, 0x8318, 0x40a0, 0x4040, 0x2ffe, 0x2040, 0x07fc, 0x0040, 0x27fc, 0xc444, 0x0444, 0x07fc, 0x2110, 0xcffe, 0x0110, 0};
int moji2[] = {0x0300, 0x0100, 0x0100, 0x0100, 0x0100, 0xfffe, 0x0100, 0x0180, 0x0040, 0x1fe0, 0x8004, 0x8004, 0xfffc, 0x0100, 0x0100, 0};

//int moji1[] = { 0x5555, 0xaaaa, 0x5555, 0xaaaa, 0x5555, 0xaaaa, 0x5555, 0xaaaa, 0x5555, 0xaaaa, 0x5555, 0xaaaa, 0x5555, 0xaaaa, 0x5555, 0xaaaa};

int main()
{

  // put your setup code here, to run once:

  int i;
  LedLatch = 0;
  Led_Enable = 0;

  while (1)
  {
    // put your main code here, to run repeatedly:
    for (i = 0; i < 16; i++)
    {
      LedLatch = 0;
      shiftout3((1 << (15 - i)), moji1[i], moji2[i]);
      LedLatch = 1;
      wait_us(250);
    }
  }
}

void shiftout3(int data1, int data2, int data3)
{
  int i;
  for (i = 0; i < 16; i++)
  {
    LedClock = 0;
    Sin1 = ((data1 >> i) & 1);
    Sin2 = ((data2 >> i) & 1);
    Sin3 = ((data3 >> i) & 1);
    LedClock = 1;
  }
}