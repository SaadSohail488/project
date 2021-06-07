#include <Adafruit_DHT.h>

#include <Adafruit_DHT.h>
#define DHTPIN 2 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int led2 = D7;

int analogValue;
string temperature = "";

void setup() 
{
    
    serial.begin(9600);
    dht.begin();
    pinMode(led2, OUTPUT);
    pinMode(temperature, INPUT);
    Particle.variable("temperature", temperature);
}

void loop() {

float h = dht.getTemperature();
temperature = string(h);
particle.publish("temperature", temperature, PRIVATE);
if (temperature > "30")
{
    //turn air conditioner on
}
else
{
    //turn air conditioner off
}

delay(10000);

}