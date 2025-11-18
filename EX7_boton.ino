//Código principalmente extraído de la práctica.

//Variables, del botón y el tiempo.
#define BUTTON_PIN 1  // GPIO21 pin connected to button
#define DEBOUNCE_TIME  50 // debounce time in milliseconds

// Variables for debounce logic
int lastSteadyState = LOW;
int lastFlickerableState = LOW;
int currentState;
unsigned long lastDebounceTime = 0;

int contador = 0; //Esto es el contador, que es lo necesario para hacer la práctica.

void setup() {
 Serial.begin(9600);
 pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool button() { //Esto es el código del botón, para determinar si se ha dado o no.
 currentState = digitalRead(BUTTON_PIN);

 if (currentState != lastFlickerableState) {
   lastDebounceTime = millis();
   lastFlickerableState = currentState;
 }

 if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
   if (lastSteadyState != currentState) {
     lastSteadyState = currentState;
     // Retorna true si el botó està premut (LOW per INPUT_PULLUP)
     return (currentState == LOW);
   }
 }

 // Retorna false si no hi ha canvi o el botó no està premut
 return false;
}

void loop() {
 if (button()) { //Esto llama a la función del botón para comprobar si está siendo presionado o no.
   //He dejado esta línea porque está chula, y no hace daño a nadie ;)
   Serial.println("Botó premut");
  contador++; //Esto suma el contador en cada vuelta, pues si entra aquí es porque el botón está presionado.
   Serial.print("Contador de pulsación: ");
   Serial.println(contador);
 }
}
