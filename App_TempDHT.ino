#include <DHT.h>
#include <DHT_U.h>
//Sensor
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
//Bluetooth
char buff[32];
float t = 0;
int i;
void setup() {
 Serial.begin(9600);
 dht.begin();
 pinMode(3, OUTPUT);
}
void loop() {
  t=dht.readTemperature();
    char ch;
  int c;
  int flg = 0;
  if (Serial.available()){
    ch = Serial.read();
    //Serial.print(ch);
    buff[i++] = ch;
    if(ch == '.'){
      flg = 1;
      i = 0;
    }
  }
  if(flg){
   flg = 0;
   digitalWrite(3, HIGH);
   Serial.print(t); 
   //Serial.print(""); 
   delay(250);
  }
  else
  digitalWrite(3, LOW);
} 
