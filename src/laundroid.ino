/*-----( Import needed libraries )-----*/

/*-----( Declare Constants and Pin Numbers )-----*/
#define TEMP  0   // define the temp input pin
#define SOUND  A0   // define the SOUND input pin

/*-----( Declare Variables )-----*/
int    tempValue ;  // read temp value
int    soundValue ;    // read analog value
char publishString[40] ;
bool dryer_status = FALSE;
void setup()   /****** SETUP: RUNS ONCE ******/
{
  pinMode (TEMP, INPUT) ;// temp input signal (Not actually required; INPUT is default)
  pinMode (SOUND, INPUT) ;// temp input signal (Not actually required; INPUT is default)
  Serial.begin(9600);              // Start the Serial Monitor connection
}//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
/*----------( Read the temp data)---------------------*/
  tempValue = digitalRead (TEMP);
  //Particle.publish(tempValue);
  if (tempValue == HIGH)// When the sensor value exceeds the set point, LED/Buzzer is turned on
  {
    if (dryer_status == FALSE)
    {
      dryer_status = TRUE;
      Particle.publish("temp_switch", "ON");
      Particle.variable("temp_switch", "ON");
    }
  }
  else if (dryer_status == TRUE)
  {
    dryer_status = FALSE;
    Particle.variable("temp_switch", "OFF");
    delay(180000); // wait for cooldown cycle to finish
    Particle.publish("temp_switch", "OFF");
  }
  /*----------( Read the sound data)---------------------
  soundValue = analogRead(SOUND);
  sprintf(publishString, "%d", soundValue);
  //Particle.publish("analog_sound", publishString);

  if (soundValue == HIGH)
  {
    //Particle.publish("sound_switch", "ON");
    Particle.variable("sound_switch", "ON");
  }
  else
  {
    //Particle.publish("sound_switch", "OFF");
    Particle.variable("sound_switch", "OFF");
  }
  */
  delay(1500);
}//--(end main loop )---
