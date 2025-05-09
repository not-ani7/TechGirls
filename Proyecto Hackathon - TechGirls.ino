#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección del módulo I2C (ajusta si es necesario)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int water; // Variable para almacenar el estado del sensor de humedad

void setup() {
  pinMode(8,OUTPUT); // Pin de salida para el módulo de relé
  pinMode(6,INPUT); // Pin de entrada para el sensor de humedad
  
  // Inicia la comunicación serie
  Serial.begin(9600); 

  // Inicia el LCD I2C
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistema de Riego");
  delay(2000);
  lcd.clear();
}

void loop() { 
  water = digitalRead(6);  // Lee el estado del sensor de humedad

  if(water == HIGH) { // Si el suelo está húmedo
    digitalWrite(8,LOW); // Apaga el relé, corta el suministro de agua
    Serial.println("El suelo está húmedo, se corta el riego.");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tierra Seca");
  }
  else { // Si el suelo está seco
    digitalWrite(8,HIGH); // Enciende el relé, activa el suministro de agua
    Serial.println("El suelo está seco, se activa el riego.");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tierra Humeda");
  }
  
  delay(400); // Espera 400 ms antes de verificar nuevamente
