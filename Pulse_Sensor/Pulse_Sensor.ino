#include <Adafruit_SSD1306.h>
 
#define OLED_Address 0x3C  // Set the address of the OLED
Adafruit_SSD1306 oled(1);
 
int x=0; // current point on x axis
int lastx=0; // last point on x axis
int lasty=0; // last point on y axis
int LastTime=0; // last measurement in milliseconds
bool BPMTiming=false; //Is LastTime the correct starting timing point of the pulse?
bool BeatComplete=false; //Whether a beating is completed = whether the calculation of the next beating can be started (depending on whether the starting timing point is correct and whether it is the beating interval)
int BPM=0; //Pulse beats
 
#define UpperThreshold 550
#define LowerThreshold 500
 
void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address); //Initialize the communication address of the OLED screen to OLED_Address (that is, 0x3C)
  oled.clearDisplay(); // clear OLED
  oled.setTextSize(2); // Set up the display size on OLED
}
 
 
void loop() 
{
  if(x>127)  //If the OLED display is full, clear
  {
    oled.clearDisplay(); // clear OLED
    x=0;
    lastx=x;
  }
 
  int value=analogRead(0);
  oled.setTextColor(WHITE); // Set up the display color is white
  int y=20-(value/45); //The ordinate of the current point (depending on the voltage value obtained by the pin)
  oled.writeLine(lastx,lasty,x,y,WHITE);
  lasty=y; //Assign the current point coordinates to the previous point, and the current point becomes the previous point
  lastx=x;
  // calc bpm
 
  if(value>UpperThreshold) //If it beats
  {
    if(BeatComplete) //If the last beating is completed, you can start to calculate the next beating
    {
      BPM=millis()-LastTime;
      BPM=int(60/(float(BPM)/1000)); //Calculate BPM (bounce number = total time/bounce time interval)
      BPMTiming=false; // The BPM value of this jump has been calculated, and the next BPM calculation is to be entered, and the starting timing point is still the original starting timing point
      BeatComplete=false; // The starting timing point is wrong, and the beating is not completed
    }
    if(BPMTiming==false) // Change the starting timing point to the correct starting timing point
    {
      LastTime=millis(); // Assign the current milliseconds to the last milliseconds
      BPMTiming=true;
    }
  }
  if((value<LowerThreshold)&(BPMTiming)) // If the starting timing point is correct and the beating interval is entered
    BeatComplete=true; // Beat complete
    // display bpm
  oled.writeFillRect(0,19,128,20,BLACK); // Draw a filled rectangle
  oled.setCursor(0,19); // Set position
  oled.print(BPM); // print BPM
  oled.print(" BPM");
  oled.display();
  x++; //enter the next cycle
}
