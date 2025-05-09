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
  // Mostrar siempre "Tierra Seca"
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tierra Seca");
  Serial.println("Tierra Seca");
  
  // Activar el relé por 21 segundos
  digitalWrite(8,LOW); // Activa el suministro de agua
  delay(21000); 
  
  // Desactivar el relé y mostrar "Tierra Humeda"
  digitalWrite(8,HIGH); // Corta el suministro de agua
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tierra Humeda");
  Serial.println("Tierra Humeda");
  
  // Detener el programa después de mostrar "Tierra Humeda"
  while(true) {  
    delay(1000); // Mantiene el estado sin hacer nada
  }
}
