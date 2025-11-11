//Las variables son globales. En este caso, la función es solo mostrar todo los tipos de
//variables, esto no está recomendado si se pretende que una variable no siempre sea accesible
//o se trabaja con objetos (en este caso, desconozco si C++ es tan enrrevesado como Java.)

//EXPLICACIÓN VARIABLES.
int numero = 1; //Esta variable puede tener como valor un número, sea positivo o negativo.

long numeroLargo = 672671; //Esto, básicamente, es un int, pero cuyo valor
  //puede ser más grande que el int. Si el int era de $-32.768$ a $32.767$,
  //el long va desde el 2 billones (aproximadamente) negativo y positivo. Difícilmente
  //se vayan a usar este tipo de número tan luengos.

float numeroComa = 1.6; //Esta variable puede contener números con decimales.

char caracter[30] = "hola, ¿qué tal? ^^"; //Esto sería el equivalente al string de otros
  //lenguaje de programación. Básicamente, son cadenas de carácteres.
  //Es importante que, para que funcione bien, hay que poner corchetes después del nombre
  //de la variable y, posteriormente, poner el largo del texto que queramos que tenga.
  
bool sioNo = true; //Es un booleano, simplemente dice true o false, como en cualquier
  //otro idioma de programación.
const int numeroConstante = 5; //Este es asaz interesante, es como el "final" de Java,
  //marca que, el siguiente dato es invariable y, tal y como se asigna la primera vez, así
  // se queda como valor. Por ejemplo, si se le intenta asignar un 6, al printarlo, printará un 5.

void setup() {
  // put your setup code here, to run once:

//Este comentario está aquí, y permanecerá aquí por el resto de los tiempos, para evidenciar
//que al principio puse aquí las variables pero, en el void loop no me funcionaba porque
//eran innacesibles (por eso ahora son globales).

//Variables a comentar.
//  int (Integer)
//  long (Long Integer)
//  float
//  char (Character)
//  bool (Boolean)
//  const (Qualificador)

  Serial.begin(115200); //Si no está esto, el texto está en ebreo, y yo no sé ebreo por más arcaico que sea mi léxico.
  Serial.println("Hello, ESP32-S2!");

  }

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  while(sioNo == true){ //Cuando el sioNo sea false, se para. Es un bucle simple y que, además,
  //profesores como Martí tacharían y harían suspender un examen o práctica, pero como es de prueba
  //, mientras no se entere, no pasa nada ;)
    Serial.print(numero); //el print normal es sin LN, el que va con ln es salto de línea.
    Serial.print(" es el número, y ");
    Serial.print(numeroLargo);
    Serial.println(" el número largo.");
    Serial.print("También hay un número en coma ");
    Serial.print(numeroComa);
    Serial.print(", e incluso una cadena de texto «");
    Serial.print(caracter);
    Serial.println("».");
  
    numero = numero + 2; //esto le suma 2 a la variable, obvio :v

    Serial.print("Fíjate, el número «"); //Más texto.
    Serial.print(numero);
    Serial.println("» ya no es un «1» como antes.");
    Serial.print("Tenemos también un «");
    Serial.print(numeroConstante);
    Serial.println("», pero por más que lo sume, sigue igual.");

    //numeroConstante = numeroConstante+5;
    //No se puede poner porque da error de compilación por su naturaleza.

    Serial.print("¿Lo ves?, «"); //Y más texto, solo que es el final ;)
    Serial.print(numeroConstante);
    Serial.println("», ¡sigue igual!");
    Serial.print("Y aquí se termina este código, pues el booleano ");
    Serial.print(sioNo);
    Serial.println(" ahora es:");
    sioNo = false; //aquí se pone false.
    Serial.println(sioNo);
  } //Y, como ahora el sioNo es falso, no se vuelve a ejecutar esto.
//«Vet aquí un gos, vet aquí un gat, aquest codi s'acabat», y yo me voy a dormir, que son las 3 de la
//mañana. ;-;
}
