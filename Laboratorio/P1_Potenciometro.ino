// Define el pin analógico donde está conectado el potenciómetro
const int potPin = A0;

// Variable para almacenar el valor leído del potenciómetro
int sensorValue = 0;

void setup() {
  // Inicia la comunicación serial a 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Lee el valor del potenciómetro (valor entre 0 y 1023)
  sensorValue = analogRead(potPin);
  
  // Convierte el valor digital a voltaje (0V a 5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Imprime el valor digital
  Serial.print("Valor digital: ");
  Serial.print(sensorValue);
  
  // Imprime el valor de voltaje
  Serial.print(" | Voltaje: ");
  Serial.print(voltage);
  Serial.println(" V");
  
  // Pausa de 500 milisegundos antes de la siguiente lectura
  delay(500);
}