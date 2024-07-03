#include <Servo.h>

// Define los pines
const int potPin = A0;       // Pin analógico donde está conectado el potenciómetro
const int servoPin = 9;      // Pin PWM donde está conectado el servomotor
const int ledRedPin = 12;    // Pin digital para el LED rojo
const int ledGreenPin = 11;  // Pin digital para el LED verde

// Crea un objeto para controlar el servomotor
Servo myServo;

void setup() {
  // Inicia la comunicación serial
  Serial.begin(9600);

  // Adjunta el servomotor al pin PWM
  myServo.attach(servoPin);

  // Configura los pines de los LEDs como salida
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
}

void loop() {
  // Lee el valor del potenciómetro (0 a 1023)
  int potValue = analogRead(potPin);

  // Mapea el valor del potenciómetro a un rango de 0 a 180 grados
  int angle = map(potValue, 0, 1023, 0, 180);

  // Mueve el servomotor al ángulo correspondiente
  myServo.write(angle);

  // Muestra los valores en el monitor serial
  Serial.print("Potenciometro: ");
  Serial.print(potValue);
  Serial.print(" | Angulo: ");
  Serial.println(angle);

  // Controla los LEDs según la posición del servomotor
  if (angle == 0) {
    digitalWrite(ledRedPin, HIGH);    // Enciende el LED rojo
    digitalWrite(ledGreenPin, LOW);   // Apaga el LED verde
  } else if (angle == 180) {
    digitalWrite(ledRedPin, LOW);     // Apaga el LED rojo
    digitalWrite(ledGreenPin, HIGH);  // Enciende el LED verde
  } else {
    digitalWrite(ledRedPin, LOW);     // Apaga el LED rojo
    digitalWrite(ledGreenPin, LOW);   // Apaga el LED verde
  }

  // Pausa de 100 milisegundos
  delay(100);
}
