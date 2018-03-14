/*-----( Import needed libraries )-----*/

/*-----( Declare Constants and Pin Numbers )-----*/
#define TEMP  0   // define the temp input pin

/*-----( Declare Variables )-----*/
int      tempValue ;  // read temp value
String   tempSwitch = "OFF" ;

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Particle.variable("tempValue", tempValue) ;
  Particle.variable("tempSwitch", tempSwitch) ;
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
    Particle.publish("tempSwitch", tempSwitch);
  }
  else if (tempValue != HIGH && tempSwitch == "ON" )
  {
    tempSwitch = "OFF" ;
    /*----------( Delay for cooldown cycle to finish)---------------------*/
    //delay(180000);
    Particle.publish("tempSwitch", tempSwitch) ;
  }

/*----------( Delay next loop for particle API)---------------------*/
  delay(3000);

//--(end main loop )---
}
