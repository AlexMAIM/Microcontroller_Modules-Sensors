#include <Wire.h>
#include <SSD1306Wire.h>
SSD1306Wire display(0x3C, 25, 26);
int lcx=32,rcx=96,cy=32;
void setup ()
{
  Wire.begin(25,26);
  display.init();
  display.flipScreenVertically();
  display.clear();
  display.display();
}
void drawEyes(int x1, int x2, int y)
{
  display.clear();
  display.setColor(WHITE);
  display.fillCircle(x1,y,25);
  display.fillCircle(x2,y,25);
}

void initEyes(int x1, int x2, int y)
{
  //Middle
  display.clear();
  drawEyes(x1,x2,y);
  display.setColor(BLACK);
  display.fillCircle(x1,y,6);
  display.fillCircle(x2,y,6);
  display.display();
  delay(900);
}

void Blink(int x1, int x2, int y)
{ 
  //Init
  display.clear();
  initEyes(x1,x2,y);
  display.display();
  delay(350);
  //Blink
  display.clear();
  drawEyes(x1,x2,y);
  display.display();
  delay(200);
  //Init
  display.clear();
  initEyes(x1,x2,y);
  display.display();
  delay(350);
  //Blink
  display.clear();
  drawEyes(x1,x2,y);
  display.display();
  delay(200);
}

void fastBlink(int x1, int x2, int y)
{
  //Init
  display.clear();
  initEyes(x1,x2,y);
  display.display();
  delay(20);
  //Blink
  display.clear();
  drawEyes(x1,x2,y);
  display.display();
  delay(30);
  //Init
  display.clear();
  initEyes(x1,x2,y);
  display.display();
  delay(20);
  //Blink
  display.clear();
  drawEyes(x1,x2,y);
  display.display();
  delay(30);
  //Init
  display.clear();
  initEyes(x1,x2,y);
  display.display();
  delay(20);
  //Blink
  display.clear();
  drawEyes(x1,x2,y);
  display.display();
  delay(30);
}

void moveIris(int x1, int x2, int y)
{ int a=12,b=x1,c=x2;
  //Middle
  initEyes(x1,x2,y);
  //Look Left
  display.clear();
  drawEyes(x1,x2,y);
  b=b-a;
  c=c-a;
  display.setColor(BLACK);
  display.fillCircle(b,y,6);
  display.fillCircle(c,y,6);
  display.display();
  delay(900);
  //Look Right
  display.clear();
  drawEyes(x1,x2,y);
  b=b+(a*2);
  c=c+(a*2);
  display.setColor(BLACK);
  display.fillCircle(b,y,6);
  display.fillCircle(c,y,6);
  display.display();
  delay(900);
}

void loop()
{
  moveIris(lcx,rcx,cy);
  Blink(lcx,rcx,cy);
  fastBlink(lcx,rcx,cy);
}