
/* A simple tool to test shutter speed of film cameras to ensure accuracy.
 *  Built by Cyrus Rupa in 2022.
 *  
 *  This system makes use of a simple trick that LED's can also sense light, (I used a blue one).
 *  
 *  **********************************
 *     ***     How to use   ***
 *  
 *  Make the default LED blink circuit. 
 *  
 *  1. A0 to 10K ohm resistor -> LED +
 *  2. LED - to ground
 *  3.  Open the back of the film camera and position the LED behind the shutter curtain.
 *  4. Take the lens off it is easy
 *  5. Place a flashlight shining   into the camera from the other side.
 *  6. Run the script to get threshold baseline.
   *  7. Run the script Serial monitor will show you how long each shutter opening was.
 *  8. Do a few runs to get an average. +-5% is about normal.  I have tested   up to 1/1000th with good results.
 *  **********************************
 */

 

int volatile sensorValue; //light level value read by LED
long volatile t1;
long volatile t2;
int timer;

/* Take a few readings of   the flashlight shining through and adjust this to be the threshold 
of the LED   seeing the flashlight. */
int threshold = 390; 


void setup() {
  Serial.begin(9600); // Use to view sensor value
  pinMode(A0, INPUT); //Change   A0 back to an Analog input pin
  Serial.println("Shutter Speed Measurement by   Cyrus Rupa");

}

void loop() {
  sensorValue = analogRead(A0);   //Read LED as a sensor

  /* Turn this on to get baseline for threshold. Comment   out lines below. */
  // Serial.println(sensorValue); 

  if (sensorValue   > threshold) {
    t1 = micros();
    sensorValue = analogRead(A0); //Read   LED as a sensor
    while (sensorValue > threshold) {
      sensorValue =   analogRead(A0); //Read LED as a sensor
    }
    t2 = micros();

    timer   = (t2 - t1) / 1000;
    Serial.print("Shutter speed recorded as "); Serial.print(timer);   Serial.println(" milliseconds");
  }
}
