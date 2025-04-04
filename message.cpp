/*_______________________________________________________________
//
//                   ASME SDC 2025 Ardunio Code
//_______________________________________________________________*/
//https://maxpromer.github.io/LCD-Character-Creator/
//https://chareditor.com/

#include <Wire.h>
#define TCAADDR 0x70
#include "Adafruit_TCS34725.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);


//test change 

//=======MUST UPDATE THIS EVERY TIME SURROUNDING CHANGES===========//
//                     R                  G                  B     //  HOW TO UPDATE:
const int Brass_R_S1 = 2910, Brass_G_S1 = 4463, Brass_B_S1 = 2877; //    
const int Steel_R_S1 = 2910, Steel_G_S1 = 4463, Steel_B_S1 = 2877; //
const int Nylon_R_S1 = 2456, Nylon_G_S1 = 4356, Nylon_B_S1 = 3148; //   
const int  Room_R_S1 = 2456,  Room_G_S1 = 4356,  Room_B_S1 = 3148; //    
const int Brass_R_L1 = 2910, Brass_G_L1 = 4463, Brass_B_L1 = 2877; //    
const int Steel_R_L1 = 2910, Steel_G_L1 = 4463, Steel_B_L1 = 2877; //
const int Nylon_R_L1 = 2456, Nylon_G_L1 = 4356, Nylon_B_L1 = 3148; //   
const int  Room_R_L1 = 2456,  Room_G_L1 = 4356,  Room_B_L1 = 3148; //   
                                                                   //
const int Brass_R_S2 = 2910, Brass_G_S2 = 4463, Brass_B_S2 = 2877; //    
const int Steel_R_S2 = 2456, Steel_G_S2 = 4356, Steel_B_S2 = 3148; //    
const int  Room_R_S2 = 2456,  Room_G_S2 = 4356,  Room_B_S2 = 3148; //    
const int Brass_R_L2 = 2910, Brass_G_L2 = 4463, Brass_B_L2 = 2877; //    
const int Steel_R_L2 = 2456, Steel_G_L2 = 4356, Steel_B_L2 = 3148; //    
const int  Room_R_L2 = 2456,  Room_G_L2 = 4356,  Room_B_L2 = 3148; // 
//=================================================================//

const int Solenoid_Brass_S1 = 0; //Solenoid Pins (doesnt matter which wire), all other wires go to ground
const int Solenoid_Nylon_S1 = 1; 
const int Solenoid_Brass_L1 = 2; 
const int Solenoid_Nylon_L1 = 3;
const int Solenoid_Brass_S2 = 4; 
const int Solenoid_Nylon_S2 = 5; 
const int Solenoid_Brass_L2 = 6; 
const int Solenoid_Nylon_L2 = 7;
const int Screw = 4;             //DC motor Pins (swap with ground to change direction)

int Dis_Brass_S1, Dis_Steel_S1, Dis_Nylon_S1, Dis_Room_S1; //other integers
int Dis_Brass_L1, Dis_Steel_L1, Dis_Nylon_L1, Dis_Room_L1;
int Dis_Brass_S2, Dis_Steel_S2, Dis_Room_S2;
int Dis_Brass_L2, Dis_Steel_L2, Dis_Room_L2;

uint16_t r, g, b, c;
/*
byte main0x0[] = {0x00,0x00,0x03,0x07,0x07,0x07,0x06,0x6};
byte main0x1[] = {0x00,0x00,0x11,0x19,0x1B,0x1B,0x0B,0x0B};
byte main0x2[] = {0x00,0x00,0x18,0x1C,0x05,0x01,0x01,0x19};
byte main0x3[] = {0x00,0x00,0x11,0x1B,0x1F,0x1F,0x15,0x15};
byte main0x4[] = {0x00,0x00,0x07,0x0F,0x0E,0x0C,0x0C,0x0F};
byte main0x5[] = {0x00,0x00,0x10,0x18,0x08,0x00,0x00,0x10};
byte main0x6[] = {0x01,0x03,0x03,0x06,0x05,0x04,0x0D,0x0D};
byte main0x7[] = {0x11,0x00,0x1B,0x0D,0x12,0x1B,0x12,0x12};
byte main0x8[] = {0x00,0x10,0x18,0x18,0x08,0x08,0x0C,0x16};
byte main0x9[] = {0x02,0x04,0x0D,0x0D,0x07,0x03,0x06,0x0C};
byte main0x10[] = {0x08,0x18,0x12,0x12,0x04,0x1C,0x18,0x00};
byte main0x11[] = {0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x06};
byte main0x12[] = {0x00,0x00,0x10,0x10,0x11,0x1B,0x1B,0x1A};
byte main0x13[] = {0x00,0x00,0x00,0x0C,0x1E,0x12,0x00,0x01};
byte main0x14[] = {0x00,0x00,0x10,0x18,0x08,0x18,0x18,0x10};
byte main0x15[] = {0x00,0x00,0x08,0x18,0x10,0x18,0x08,0x0C};
byte main1x0[] = {0x07,0x07,0x06,0x06,0x06,0x00,0x00,0x00};
byte main1x1[] = {0x19,0x18,0x0A,0x0B,0x09,0x00,0x00,0x00};
byte main1x2[] = {0x1D,0x0D,0x05,0x05,0x19,0x00,0x00,0x00};
byte main1x3[] = {0x11,0x11,0x11,0x11,0x13,0x00,0x00,0x00};
byte main1x4[] = {0x0C,0x0C,0x0C,0x0F,0x07,0x00,0x00,0x00};
byte main1x5[] = {0x00,0x08,0x08,0x10,0x10,0x00,0x00,0x00};
byte main1x6[] = {0x0C,0x03,0x02,0x01,0x00,0x00,0x00,0x00};
byte main1x7[] = {0x17,0x10,0x0F,0x07,0x18,0x07,0x00,0x00};
byte main1x8[] = {0x0A,0x1C,0x14,0x09,0x13,0x03,0x06,0x06};
byte main1x9[] = {0x0C,0x18,0x10,0x10,0x00,0x00,0x00,0x00};
byte main1x10[] = {0x06,0x03,0x00,0x00,0x00,0x00,0x01,0x00};
byte main1x11[] = {0x0C,0x18,0x1E,0x0F,0x1C,0x18,0x10,0x00};
byte main1x12[] = {0x1E,0x0F,0x0D,0x1C,0x1F,0x03,0x00,0x00};
byte main1x13[] = {0x0F,0x1B,0x11,0x01,0x03,0x1F,0x1C,0x00};
byte main1x14[] = {0x10,0x10,0x18,0x1C,0x0F,0x03,0x00,0x00};
byte main1x15[] = {0x0C,0x0C,0x18,0x18,0x18,0x10,0x00,0x00};
*/
void setup(){
  pinMode(Solenoid_Brass_S1, OUTPUT); //Solenoid Setup
  pinMode(Solenoid_Nylon_S1, OUTPUT);
  pinMode(Solenoid_Brass_L1, OUTPUT); 
  pinMode(Solenoid_Nylon_L1, OUTPUT);
  pinMode(Solenoid_Brass_S2, OUTPUT); 
  pinMode(Solenoid_Nylon_S2, OUTPUT);
  pinMode(Solenoid_Brass_L2, OUTPUT); 
  pinMode(Solenoid_Nylon_L2, OUTPUT);
  pinMode(Screw, OUTPUT);
  Serial.begin(9600); 
  /*
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.createChar(0, main0x0);
  lcd.createChar(1, main0x1);
  lcd.createChar(2, main0x2);
  lcd.createChar(3, main0x3);
  lcd.createChar(4, main0x4);
  lcd.createChar(5, main0x5);
  lcd.createChar(6, main0x6);
  lcd.createChar(7, main0x7);
  lcd.createChar(8, main0x8);
  lcd.createChar(9, main0x9);
  lcd.createChar(10, main0x10);
  lcd.createChar(11, main0x11);
  lcd.createChar(12, main0x12);
  lcd.createChar(13, main0x13);
  lcd.createChar(14, main0x14);
  lcd.createChar(15, main1x15);
  lcd.createChar(16, main1x0);
  lcd.createChar(17, main1x1);
  lcd.createChar(18, main1x2);
  lcd.createChar(19, main1x3);
  lcd.createChar(20, main1x4);
  lcd.createChar(21, main1x5);
  lcd.createChar(22, main1x6);
  lcd.createChar(23, main1x7);
  lcd.createChar(24, main1x8);
  lcd.createChar(25, main1x9);
  lcd.createChar(26, main1x10);
  lcd.createChar(27, main1x11);
  lcd.createChar(28, main1x12);
  lcd.createChar(29, main1x13);
  lcd.createChar(30, main1x14);
  lcd.createChar(31, main1x15);
  */
  checkColorSensors();
}

void loop(){
  calibrate();
  //moveScrew();
  //moveSolenoids();
}

void checkColorSensors(){
  char SensorNames[4] = {'S1','L1','S2','L2'};
  for(int j=0; j<=3; j++){
    TCAselect(j);
    if(tcs.begin()){
      Serial.println("Found Sensor "); Serial.print(SensorNames[j]); Serial.print(", starting program");
    }
    else{
      Serial.println("Sensor "); Serial.print(SensorNames[j]); Serial.print(" not found, check connections");
      while (1);
    }
  }
}

void calibrate(){
  char SensorNames[4] = {'S1','L1','S2','L2'};
  for(int k=0; k<=3; k++){
    TCAselect(k);
    tcs.getRawData(&r, &g, &b, &c);
    Serial.println("Sensor " );
    Serial.print(SensorNames[k]); Serial.print("--> R:"); Serial.print(r,DEC); Serial.print(" G:"); Serial.print(g, DEC); Serial.print(" B:"); Serial.print(b, DEC);
    Serial.println("---------------------------------------------------------------------------");
    delay(1500);
  }
}

void moveScrew(){
}

void moveSolenoids(){
  Dis_Brass_S1 = getColorDistance(Brass_R_S1, Brass_G_S1, Brass_B_S1, 0); //Reads Color Distances
  Dis_Steel_S1 = getColorDistance(Steel_R_S1, Steel_G_S1, Steel_B_S1, 0); 
  Dis_Nylon_S1 = getColorDistance(Nylon_R_S1, Nylon_G_S1, Nylon_B_S1, 0);
  Dis_Room_S1  = getColorDistance(Room_R_S1, Room_G_S1, Room_B_S1, 0);
  Dis_Brass_L1 = getColorDistance(Brass_R_L1, Brass_G_L1, Brass_B_L1, 1); 
  Dis_Steel_L1 = getColorDistance(Steel_R_L1, Steel_G_L1, Steel_B_L1, 1); 
  Dis_Nylon_L1 = getColorDistance(Nylon_R_L1, Nylon_G_L1, Nylon_B_L1, 1);
  Dis_Room_L1  = getColorDistance(Room_R_L1, Room_G_L1, Room_B_L1, 1);
  Dis_Brass_S2 = getColorDistance(Brass_R_S2, Brass_G_S2, Brass_B_S2, 2); 
  Dis_Steel_S2 = getColorDistance(Steel_R_S2, Steel_G_S2, Steel_B_S2, 2); 
  Dis_Room_S2  = getColorDistance(Room_R_S2, Room_G_S2, Room_B_S2, 2);
  Dis_Brass_L2 = getColorDistance(Brass_R_L2, Brass_G_L2, Brass_B_L2, 3); 
  Dis_Steel_L2 = getColorDistance(Steel_R_L2, Steel_G_L2, Steel_B_L2, 3); 
  Dis_Room_L2  = getColorDistance(Room_R_L2, Room_G_L2, Room_B_L2, 3);

/*
  if((ColorDistance_Brass_S < ColorDistance_Nylon_S) && (ColorDistance_Brass_S < ColorDistance_Room_S)){ //if color is closer to Brass, move Brass Solenoid
    digitalWrite(Solenoid_Brass_S, HIGH);
  }
  else if((ColorDistance_Nylon_S < ColorDistance_Brass_S) && (ColorDistance_Nylon_S < ColorDistance_Room_S)){ //if color is closer to Nylon, move Nylon Solenoid
    digitalWrite(Solenoid_Nylon_S, HIGH);
  }
  else if((ColorDistance_Room_S < ColorDistance_Brass_S) && (ColorDistance_Room_S < ColorDistance_Nylon_S)){ //if color is closer to Room, do nothing
    digitalWrite(Solenoid_Brass_S, LOW);
    digitalWrite(Solenoid_Nylon_S, LOW);
  }
  else{ 
    Serial.print("GUNK?!?!");
  }
  if((ColorDistance_Brass_L < ColorDistance_Nylon_L) && (ColorDistance_Brass_L < ColorDistance_Room_L)){ //if color is closer to Brass, move Brass Solenoid
    digitalWrite(Solenoid_Brass_L, HIGH);
  }
  else if((ColorDistance_Nylon_L < ColorDistance_Brass_L) && (ColorDistance_Nylon_L < ColorDistance_Room_L)){ //if color is closer to Nylon, move Nylon Solenoid
    digitalWrite(Solenoid_Nylon_L, HIGH);
  }
  else if((ColorDistance_Room_L < ColorDistance_Brass_L) && (ColorDistance_Room_L < ColorDistance_Nylon_L)){ //if color is closer to Room, do nothing
    digitalWrite(Solenoid_Brass_L, LOW);
    digitalWrite(Solenoid_Nylon_L, LOW);
  }
  else{ 
    Serial.print("GUNKY?!?!");
  }
  Serial.println("----------------------");
  Serial.print("ColorDistance_Brass_S:");
  Serial.println(ColorDistance_Brass_S);
  Serial.print("ColorDistance_Nylon_S:");
  Serial.println(ColorDistance_Nylon_S);
  Serial.print("ColorDistance_Brass_L:");
  Serial.println(ColorDistance_Brass_L);
  Serial.print("ColorDistance_Nylon_L:");
  Serial.println(ColorDistance_Nylon_L);
  delay(100);
  digitalWrite(Solenoid_Brass_S, LOW);  
  digitalWrite(Solenoid_Nylon_S, LOW);
  digitalWrite(Solenoid_Brass_L, LOW);  
  digitalWrite(Solenoid_Nylon_L, LOW);
  delay(250);
  */
}

/*
//Color Sensor S1 --> TCAselect(0)
//Color Sensor L1 --> TCAselect(1)
//Color Sensor S2 --> TCAselect(2)
//Color Sensor L2 --> TCAselect(3)
*/
void TCAselect(uint8_t i){                
  if(i > 7) return;   //if passed in pin number is not a valid value, return                      
  Wire.beginTransmission(TCAADDR);       
  Wire.write(1 << i);                     
  Wire.endTransmission();
} 

/*
* getColorDistance() is replacing specified color distance methods
* regular r,g,b values are global variables and can be accessed throughout the code
* pass in the specific R,G,B values depending on size and type of ball
* specificy TCA Select pin when calling
* tca_select_pin GUIDE:
*   S1 : 0
*   L1 : 1
*   S2 : 2
*   L2 : 3
*/
int getColorDistance(int specific_R_value, int specific_G_value, int specific_B_value, int tca_select_pin){
  TCAselect(tca_select_pin);
  tcs.getRawData(&r, &g, &b, &c); 
  return sqrt(pow(r - specific_R_value, 2) + pow(g - specific_G_value, 2) + pow(b - specific_B_value, 2));
}




