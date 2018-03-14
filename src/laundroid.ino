/*-----( Import needed libraries )-----*/

/*-----( Declare Constants and Pin Numbers )-----*/
#define TEMP  0   // define the temp input pin

/*-----( Declare Variables )-----*/
int      tempValue ;  // read temp value
String   tempSwitch ;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Particle.variable("tempSwitch", tempSwitch) ;
  Particle.variable("tempValue", tempValue) ;
  tempSwitch = "OFF" ;
  //Serial.begin(9600);
}
//--(end setup )---

/****** BEGIN MAIN LOOP ******/
void loop()
{
/*----------( Read the temp data)--------------------------*/
  tempValue = digitalRead (TEMP) ;

/*----------( Loop over the temp data)---------------------*/
  if (tempValue == HIGH && tempSwitch == "OFF") // When the sensor value exceeds the set point, LED/Buzzer is turned on
  {
    tempSwitch = "ON" ;
    Particle.publish(tempSwitch);
  }
  else if (tempSwitch == "ON" )
  {
    tempSwitch = "OFF" ;
    delay(180000); // wait for cooldown cycle to finish
    Particle.publish(tempSwitch) ;
  }

/*----------( Delay next loop for particle API)---------------------*/  
  delay(1500);

//--(end main loop )---
}
