/*
  Project: Blink (El "Hello, World!" dels microcontroladors)
  Description: Fa parpellejar un LED connectat al pin 23.
*/
// Definim una constant per al pin on hem connectat el LED
const int LED_PIN = 1; //Así se declaran los pines, para que no hayan problemas

// La funció setup() s'executa un cop quan la placa arrenca
void setup() {
  // Configurem el pin del LED com una SORTIDA (OUTPUT)
  pinMode(LED_PIN, OUTPUT); //Esto es la declaración de que, la luz, va a iluminar porque la 
  //electricidad le llegará, por eso es output, porque produce una respuesta del circuito eléctrico
  //hacia afuera.
}

// La funció loop() s'executa contínuament
void loop() {
  int delay_alumbrado = 1000; //Esto declara el tiempo el que estará encendido
  int delay_siniestro = 2000; //Y esto el tiempo que permanecerá apagado.
  digitalWrite(LED_PIN, HIGH);  // Envia 3.3V al pin (encén el LED)
  delay(delay_alumbrado);    
  
  digitalWrite(LED_PIN, LOW);   // Envia 0V al pin (apaga el LED)
  delay(delay_siniestro);   //IMPORTANTE, el valor dentro del Delay es un
  //int, no es ninguna otra variante extraña ni similar.
}