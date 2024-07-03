// Define el pin analógico donde está conectada la fotorresistencia
const int ldrPin = A0;
// Define el pin digital donde está conectado el LED
const int ledPin = 13;
// Umbral de luz para encender el LED
const int lightThreshold = 900;  // Ajusta según tus necesidades

// Variable para almacenar el valor leído de la fotorresistencia
int ldrValue = 0;

void setup() {
  // Inicia la comunicación serial a 9600 bps
  Serial.begin(9600);
  // Configura el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Lee el valor de la fotorresistencia (valor entre 0 y 1023)
  ldrValue = analogRead(ldrPin);
  
  // Convierte el valor digital a voltaje (0V a 5V)
  float voltage = ldrValue * (5.0 / 1023.0);
  
  // Muestra el valor digital y el voltaje en el monitor serial
  Serial.print("Valor digital: ");
  Serial.print(ldrValue);
  Serial.print(" | Voltaje: ");
  Serial.print(voltage, 4); // 4 decimales para mayor precisión
  Serial.println(" V");
  
  // Comprueba si el valor supera el umbral
  if (ldrValue > lightThreshold) {
    // Enciende el LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Apaga el LED
    digitalWrite(ledPin, LOW);
  }
  
  // Pausa de 500 milisegundos antes de la siguiente lectura
  delay(500);
}
