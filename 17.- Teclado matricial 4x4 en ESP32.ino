
//El código nace del ejemplo que se ha dado en la práctica, pues es la base
//para poder interactuar con el KeyPad y no considero necesario volver a hacerlo.
//El objetivo del código es introducir un código y, si se introduce, sale un mensaje.

// importa libreria Keypad
#include <Keypad.h>
// define numero de filas
const uint8_t ROWS = 4;
// define numero de columnas
const uint8_t COLS = 4;
// define la distribucion de teclas
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
// pines correspondientes a las filas
uint8_t colPins[COLS] = { 16, 4, 2, 15 };
// pines correspondientes a las columnas
uint8_t rowPins[ROWS] = { 19, 18, 5, 17 };
// crea objeto con los prametros creados previamente
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // obtiene tecla presionada y asigna a variable
  char key = keypad.getKey();
  // comprueba que se haya presionado una tecla
  if (key == '1') {
    // envia a monitor serial la tecla presionada
    Serial.println(key);
    // ESPERA HASTA QUE SE PULSE OTRA TECLA
    char key2 = 0;
    while (key2 == 0) {
      key2 = keypad.getKey();
    }

    Serial.println(key2);

    if (key2 == '2') { //cuando se pulsa otra tecla, si es "2", entra aquí (pues la combinación,
    //"12", es correcta.)
      Serial.println("Código correcto.");
    } else {//todo otro código es incorrecto.
      Serial.println("Código incorrecto.");
    }
  }
}