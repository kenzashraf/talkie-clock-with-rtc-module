
/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-ds1307-rtc-module
 */
 #include<PCM.h>
//#include <SPI.h>
#include <RTClib.h>
#include <Arduino.h>
#include <Wire.h>
#include "Talkie.h"
#include "Vocab_US_Clock.h"
#include "Vocab_Special.h"
#include "Vocab_US_Large.h"
Talkie voice;
RTC_DS1307 rtc;
               // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;    
  char daysOfTheWeek[7][12] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};


void setup () {
//  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);
    
  
if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while  (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT  running!");
  // SETUP RTC MODULE
 }
 

  // automatically sets the RTC to the date & time on PC this sketch was compiled
 // COMMENT IT WHEN THE RTC IS ALWYAS OPEN 
 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  // manually sets the RTC with an explicit date & time, for example to set
  // January 21, 2021 at 3am you would call:
   //rtc.adjust(DateTime(2021, 1, 21, 3, 0, 0));


}


void loop () {
//
val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
//    digitalWrite(led, HIGH);   // turn LED ON
    delay(200);                // delay 100 milliseconds 

    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
  DateTime now = rtc.now();
  int v=0;
  int h=now.hour();
  int m=now.minute();
  int s=now.second();
  int dy= now.day();


  
  if (h>11){
    v=1;
  }
 if (h>12) {
  h=h-12;
 }
 
   Serial.print(h);
 
//startplayback{SUNDAY,sizeof {SUNDAY}};
   Serial.print(":");
   Serial.print(m);
   Serial.print(":");
   Serial.print(s);
   Serial.println();
  // Serial.println(now.day(), DEC);
  //Serial.print("");
  // Serial.println(daysOfTheWeek[now.dayOfTheWeek()]);
   
    voice.say(sp3_THE);
    voice.say(sp3_TIME);
    voice.say(sp3_IS);

   
     if(now.day()==28){

        Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
        Serial.print(":");
     }

    
   if (h==1){
    voice.say(sp3_ONE);
   }
   if (h==2){
    voice.say(sp3_TWO);
   }
   if (h==3){
    voice.say(sp3_THREE);
   }
   if (h==4){
    voice.say(sp3_FOUR);
   }
   if (h==5){
    voice.say(sp3_FIVE);
   }
   if (h==6){
    voice.say(sp3_SIX);
   }
   if (h==7){
    voice.say(sp3_SEVEN);
   }
   if (h==8){
    voice.say(sp3_EIGHT);
   }
   if (h==9){
    voice.say(sp3_NINE);
   }
   if (h==10){
    voice.say(sp3_TEN);
   }
   if (h==11){
    voice.say(sp3_ELEVEN);
   }
   if (h==12){
    voice.say(sp3_TWELVE);
   }
  if (m==0){
  voice.say (sp3_OCLOCK);
}
if  (m==1){
 voice.say (sp3_ZERO);
 voice.say (sp3_ONE);
}
if (m==2){
  voice.say (sp3_ZERO);
  voice.say (sp3_TWO);
}
if (m==3){
  voice.say  (sp3_ZERO);
  voice.say (sp3_THREE);
}
if (m==4){
  voice.say (sp3_ZERO);
  voice.say (sp3_FOUR);
}
if (m==5){
  voice.say (sp3_ZERO);
  voice.say  (sp3_FIVE);
}
if (m==6){
  voice.say (sp3_ZERO);
  voice.say (sp3_SIX);
}
if  (m==7){
  voice.say (sp3_ZERO);
  voice.say (sp3_SEVEN);
}
if (m==8){
  voice.say (sp3_ZERO);
  voice.say (sp3_EIGHT);
}
if (m==9){
  voice.say  (sp3_ZERO);
  voice.say (sp3_NINE);
}
if (m==10){
 
  voice.say (sp3_TEN);
}
if  (m==11){
 
  voice.say (sp3_ELEVEN);
}
if (m==12){
 
  voice.say  (sp3_TWELVE);
}
if (m==13){
 
  voice.say (sp3_THIRTEEN);
}
if  (m==14){
 
  voice.say (sp3_FOURTEEN);
}
if (m==15){
 
  voice.say  (sp3_FIFTEEN);
}
if (m==16){
 
  voice.say (sp3_SIXTEEN);
}
if  (m==17){
 
  voice.say (sp3_SEVENTEEN);
}
if (m==18){
 
  voice.say  (sp3_EIGHTEEN);
}
if (m==19){
 
  voice.say (sp3_NINETEEN);
}
if  (m==20){
 
  voice.say (sp3_TWENTY);
}

if (m==21){
   voice.say  (sp3_TWENTY);
   voice.say (sp3_ONE);
}
if (m==22){
   voice.say (sp3_TWENTY);
   voice.say (sp3_TWO);
}
if (m==23){
   voice.say (sp3_TWENTY);
   voice.say  (sp3_THREE);
}
if (m==24){
   voice.say (sp3_TWENTY);
   voice.say (sp3_FOUR);
}
if  (m==25){
   voice.say (sp3_TWENTY);
   voice.say (sp3_FIVE);
}
if (m==26){
   voice.say (sp3_TWENTY);
   voice.say (sp3_SIX);
}
if (m==27){
   voice.say  (sp3_TWENTY);
   voice.say (sp3_SEVEN);
}
if (m==28){
   voice.say (sp3_TWENTY);
   voice.say (sp3_EIGHT);
}
if (m==29){
   voice.say (sp3_TWENTY);
   voice.say (sp3_NINE);
}
if (m==30){
 
  voice.say (sp3_THIRTY);
}

if  (m==31){
   voice.say (sp3_THIRTY);
   voice.say (sp3_ONE);
}
if (m==32){
   voice.say (sp3_THIRTY);
   voice.say (sp3_TWO);
}
if (m==33){
   voice.say  (sp3_THIRTY);
   voice.say (sp3_THREE);
}
if (m==34){
   voice.say (sp3_THIRTY);
   voice.say (sp3_FOUR);
}
if (m==35){
   voice.say (sp3_THIRTY);
   voice.say  (sp3_FIVE);
}
if (m==36){
   voice.say (sp3_THIRTY);
   voice.say (sp3_SIX);
}
if  (m==37){
   voice.say (sp3_THIRTY);
   voice.say (sp3_SEVEN);
}
if (m==38){
   voice.say (sp3_THIRTY);
   voice.say (sp3_EIGHT);
}
if (m==39){
   voice.say (sp3_THIRTY);
   voice.say (sp3_NINE);
}
if (m==40){
 
  voice.say (sp3_FOURTY);
}

if (m==41){
   voice.say (sp3_FOURTY);
   voice.say (sp3_ONE);
}
if (m==42){
   voice.say (sp3_FOURTY);
   voice.say  (sp3_TWO);
}
if (m==43){
   voice.say (sp3_FOURTY);
   voice.say (sp3_THREE);
}
if  (m==44){
   voice.say (sp3_FOURTY);
   voice.say (sp3_FOUR);
}
if (m==45){
   voice.say (sp3_FOURTY);
   voice.say (sp3_FIVE);
}
if (m==46){
   voice.say  (sp3_FOURTY);
   voice.say (sp3_SIX);
}
if (m==47){
   voice.say (sp3_FOURTY);
   voice.say (sp3_SEVEN);
}
if (m==48){
   voice.say (sp3_FOURTY);
   voice.say (sp3_EIGHT);
}
if (m==49){
 voice.say (sp3_FOURTY);
   voice.say  (sp3_NINE);
}
if (m==50){
 
  voice.say (sp3_FIFTY);
}

if  (m==51){
   voice.say (sp3_FIFTY);
   voice.say (sp3_ONE);
}
if (m==52){
   voice.say (sp3_FIFTY);
   voice.say (sp3_TWO);
}
if (m==53){
   voice.say  (sp3_FIFTY);
   voice.say (sp3_THREE);
}
if (m==54){
   voice.say (sp3_FIFTY);
   voice.say (sp3_FOUR);
}
if (m==55){
   voice.say (sp3_FIFTY);
   voice.say  (sp3_FIVE);
}
if (m==56){
   voice.say (sp3_FIFTY);
   voice.say (sp3_SIX);
}
if  (m==57){
   voice.say (sp3_FIFTY);
   voice.say (sp3_SEVEN);
}
if (m==58){
   voice.say (sp3_FIFTY);
   voice.say (sp3_EIGHT);
}
if (m==59){
   voice.say  (sp3_FIFTY);
   voice.say (sp3_NINE);
}

if (v==0){ 
  voice.say (sp3_A_M);  
}
if (v==1){
  voice.say(sp3_P_M);
    
}

      
    }
  } 
  else {
//      digitalWrite(led, LOW); // turn LED OFF
      delay(100);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
  
   
   
}
