/* 
Simple sketch to read Temperature from DHT11 sensor
Written by Javier Montaner @tumaku_ for Makespace Madrid 
http://www.makespacemadrid.org

Based on YourDuino.com Example Software Sketch
DHT11 Humidity and Temperature Sensor test
Credits: Rob Tillaart
http://arduino-direct.com/sunshop/index.php?l=product_detail&p=162
terry@yourduino.com */

#include <dht11.h>
#include <SoftwareSerial.h>

dht11 DHT11;

#define DHT11PIN 2
SoftwareSerial eImpSerial(7, 8); // RX, TX

void setup()   
{
   Serial.begin(9600);
   eImpSerial.begin(9600);
   Serial.println("DHT11 TEST PROGRAM ");
   Serial.print("LIBRARY VERSION: ");
   Serial.println(DHT11LIB_VERSION);
   Serial.println();
}

void loop()  
{
   int chk = DHT11.read(DHT11PIN);
   Serial.print("Temperature (oC): ");
   Serial.println((float)DHT11.temperature, 2);
   eImpSerial.write(0xFB);
   eImpSerial.print((float)DHT11.temperature, 2);
   eImpSerial.write(0xFC);
   delay(60000);
}
