/*
 Project Name   : HUMIDITY AND TEMPERATURE CONTROLLED PLANT IRRIGATION SYSTEM
 Revision Date  : 25.12.2020
 Author         : MELİH GÜNEŞ
 // ---------------------------------------------------------------------------------------------------------------------------
 Purpose        : It is aimed to develop a system that irrigates our plants instead of us when we go on a long journey.
 // ---------------------------------------------------------------------------------------------------------------------------
 System Input   : 
                  1) Soil Humidity Sensor : To measure the humidity in the soil
                  2) LM35                 : To measure the temperature of the environment in which the plant is located.
 System Output  : 
                  1) Water pomp              : To irrigate plant
 // ---------------------------------------------------------------------------------------------------------------------------
 System Work    :A system was developed that measures the temperature and humidity values, which are important for adequate and
                 accurate irrigation of plants. With the proposed system, a system that irrigates when the plant needs water was
                 designed and irrigation was provided in a proper manner
 // ---------------------------------------------------------------------------------------------------------------------------          
 */

// ---------------------------------------------------------------------------------------------------------------------------          

// DEFINITIONS
int waterPump=2;                              // Water pomp is connected to the Digital 9 pin.

int humiditySensor=A0;                        // Humidity sensor is connected to Analog 0 pin.
int temperatureSensor=A1;                     // LM35 is connected to Analog 1 pin.

int limitValueForHumidity = 50;               // To determine the limit humidity value.
int limitValueForTemperature = 30;            // To determine the limit temperature value.

int mappedValueForHumidity;                   // For mapping the analog value of humidity.
int mappedValueForTemperature;                // For mapping the analog value of temperature.
// ---------------------------------------------------------------------------------------------------------------------------

// SETUP CODE AREA
void setup() {

  pinMode(humiditySensor,INPUT);              // Humidity sensor defined as INPUT.
  pinMode(temperatureSensor,INPUT);           // LM35 defined as INPUT.

  pinMode(waterPump,OUTPUT);                  // Water pomp defined as OUTPUT.

  digitalWrite(waterPump,LOW);                // When power is ON, water pomp is LOW.

  Serial.begin(9600);                         // Sets the baud rate for serial data transmission. 
}
// ---------------------------------------------------------------------------------------------------------------------------

// MAIN CODE AREA
void loop() {
  
  int humidity = analogRead(humiditySensor);                                         // Read the analog humidity sensor value.    
  mappedValueForHumidity = map(humiditySensor, 0, 1023 ,0 ,100);                     // To map.
  Serial.println(mappedValueForHumidity);                                            // Write the mapped value to the Serial Monitor.

  int temperature = analogRead(temperatureSensor);                                   // Read the analog LM35 value.
  mappedValueForTemperature = map(temperatureSensor, 0, 1023, 0, 100);               // To map.
  Serial.println(mappedValueForTemperature );                                        // Write the mapped value to the Serial Monitor.

  // If humidity is between 50-100 and temperature is between 30-75 water pomp is ON for 5 second, OFF for 3 second.
  if(100>mappedValueForHumidity && mappedValueForHumidity>limitValueForHumidity && 75>=mappedValueForTemperature && mappedValueForTemperature>limitValueForTemperature)
  {
   digitalWrite(waterPump,HIGH);                  // Water pomp is ON.
   delay(5000);                                   // Wait for a 5 seconds.
   
   digitalWrite(waterPump,LOW);                   // Water pomp is OFF.
   delay(3000);                                   // Wait for a 3 seconds.
  }
  // If the humidity and temperature values are not within the desired range, water pomp is OFF.
  else
  {
    digitalWrite(waterPump,LOW);                  // Water pomp is OFF.
   }
  }
  
