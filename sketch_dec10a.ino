#include <dht.h>
//REMEMBERRRR!!!!!
//temp_out = 7;
//temp_in = 8;
//waterproof_sensor = 2
//ref1 = http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
//ref2 = https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806


#include <dht.h>
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 

OneWire oneWire(ONE_WIRE_BUS); 

DallasTemperature sensors(&oneWire);

dht DHT1, DHT2;

#define DHT11_PIN 7
#define DHT11_PIN2 8

void setup(){
  Serial.begin(9600);
  sensors.begin(); 
}

void loop()
{
  int chk = DHT1.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT1.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT1.humidity);

  int chk2 = DHT2.read11(DHT11_PIN2);
  Serial.print("Temperature = ");
  Serial.println(DHT2.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT2.humidity);

 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.println("DONE"); 

 Serial.print("Temperature is: "); 
 Serial.println(sensors.getTempCByIndex(0));
 delay(1000);
}

