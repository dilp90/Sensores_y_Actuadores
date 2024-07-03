// Define el pin analógico donde está conectado el TMP36
const int tempPin = A0;

// Variable para almacenar el valor leído del TMP36
int sensorValue = 0;

void setup() {
  // Inicia la comunicación serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Lee el valor del TMP36 (valor entre 0 y 1023)
  sensorValue = analogRead(tempPin);
  
  // Convierte el valor digital a voltaje (0V a 5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Convierte el voltaje a temperatura en Celsius
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Imprime el valor digital
  Serial.print("Valor digital: ");
  Serial.print(sensorValue);
  
  // Imprime el valor de voltaje
  Serial.print(" | Voltaje: ");
  Serial.print(voltage);
  Serial.println(" V");
  
   // Imprime la temperatura en Celsius
  Serial.print(" | Temperatura: ");
  Serial.print(temperatureC, 2); // 2 decimales para precisión
  Serial.println(" °C");
  
  // Pausa de 500 milisegundos antes de la siguiente lectura
  delay(500);
}
