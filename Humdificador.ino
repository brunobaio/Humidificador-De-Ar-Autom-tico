#include <SoftwareSerial.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>


SoftwareSerial bluetooth(2, 3); 
#define DHTPIN 7
#define DHTTYPE DHT22


#define LED_VERMELHO 12
#define LED_VERDE 13
#define RELE 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);
  Serial.println("Iniciando...");
  
  
  bluetooth.begin(9600);
  Serial.println("Bluetooth iniciado. Esperando conexão...");
  

  dht.begin();
  Serial.println("DHT iniciado.");
  

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(RELE, OUTPUT);

 
  bluetooth.println("Teste de comunicação Bluetooth.");
  
  Serial.println("Setup completo.");
}

void loop() {
  
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C, Umidade: ");
  Serial.print(umidade);
  Serial.println("%");
  
  
  bluetooth.print("Temperatura: ");
  bluetooth.print(temperatura);
  bluetooth.print("°C, Umidade: ");
  bluetooth.print(umidade);
  bluetooth.print("% - ");

  
  if (temperatura < 10.0) {
    Serial.print("Temperatura muito baixa. ");
    bluetooth.print("Temperatura muito baixa. ");
  } else if (temperatura >= 10.0 && temperatura <= 15.0) {
    Serial.print("Temperatura baixa. ");
    bluetooth.print("Temperatura baixa. ");
  } else if (temperatura > 15.0 && temperatura <= 27.0) {
    Serial.print("Temperatura confortável. ");
    bluetooth.print("Temperatura confortável. ");
  } else if (temperatura > 27.0 && temperatura <= 32.0) {
    Serial.print("Temperatura alta. ");
    bluetooth.print("Temperatura alta. ");
  } else {
    Serial.print("Temperatura muito alta. ");
    bluetooth.print("Temperatura muito alta. ");
  }

  
  if (umidade < 30.0) {
    Serial.println("Umidade muito baixa.");
    bluetooth.println("Umidade muito baixa.");
  } else if (umidade >= 30.0 && umidade <= 50.0) {
    Serial.println("Umidade baixa.");
    bluetooth.println("Umidade baixa.");
    digitalWrite(RELE, HIGH); 
    digitalWrite(LED_VERDE, HIGH); 
    digitalWrite(LED_VERMELHO, LOW); 
  } else if (umidade > 50.0 && umidade <= 70.0) {
    Serial.println("Umidade confortável.");
    bluetooth.println("Umidade confortável.");
    digitalWrite(RELE, HIGH); 
    digitalWrite(LED_VERDE, HIGH); 
    digitalWrite(LED_VERMELHO, LOW); 
  } else if (umidade > 70.0 && umidade <= 90.0) {
    Serial.println("Umidade alta.");
    bluetooth.println("Umidade alta.");
    digitalWrite(RELE, LOW); 
    digitalWrite(LED_VERDE, LOW); 
    digitalWrite(LED_VERMELHO, HIGH); 
  } else {
    Serial.println("Umidade muito alta.");
    bluetooth.println("Umidade muito alta.");
  }

  
  delay(2000);
}
