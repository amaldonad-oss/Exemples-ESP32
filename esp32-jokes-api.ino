/*
  ESP32 HTTPClient Jokes API Example

  https://wokwi.com/projects/342032431249883731

  Copyright (C) 2022, Uri Shaked
*/

//Estas son las librerías que incluye.
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

//Esto da la red Wifi a la que se debe de conectar.
const char* ssid = "LaAlexRed"; //**-** aquí se puede ver que la red
//ahora es una mía y que tiene contraseña 
const char* password = "1234";

//Esto son los pines, sin más.
#define BTN_PIN 5
#define TFT_DC 2
#define TFT_CS 15
//Este hace que la pantalla funcione.
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

//Esto simplemente es el enlace de donde consegue los chistes que muestra por pantalla.
const String url = "https://v2.jokeapi.dev/joke/Programming";


String getJoke() {
  HTTPClient http;
  http.useHTTP10(true);  // Usa HTTP 1.0 (necesario para algunas APIs en ESP32).
  http.begin(url);       // Abre la conexión HTTP con la URL.
  http.GET();            // Hace una petición GET.
  String result = http.getString(); // Lee la respuesta como texto.

  //Esto transforma el texto almacenado en la web de bromas de json a docs, para que
  //se imprima correctamente por pantalla.
  DynamicJsonDocument doc(2048);
  DeserializationError error = deserializeJson(doc, result);
  // Test if parsing succeeds.
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return "<error>";
  }

  //Esto lee el chiste en sí.
  String type = doc["type"].as<String>();
  String joke = doc["joke"].as<String>();
  String setup = doc["setup"].as<String>();
  String delivery = doc["delivery"].as<String>();
  http.end();
  //Y lo devuelve.
  return type.equals("single") ? joke : setup + "  " + delivery;
}


void nextJoke() {
  tft.setTextColor(ILI9341_WHITE);
  tft.println("\nLoading joke...");

  String joke = getJoke();  //Esto llama a la API para que funcione la broma
  tft.setTextColor(ILI9341_GREEN); //Aquí cambia el color del texto
  tft.println(joke); //Y esto muestra el chiste.
}

void setup() {
  //Esto en sí es la conexión.
  pinMode(BTN_PIN, INPUT_PULLUP);

  WiFi.begin(ssid, password); //**-** En lugar de especificar el canal, podrá hacerlo
  //por el que considere pertinente (otrora lo hacía, sí o sí, por el canal 6).

  tft.begin();
  tft.setRotation(1);

  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.print("Connecting to WiFi");

//Esto espera a que se conecte al wifi para funcionar.
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    tft.print(".");
  }

  tft.print("\nOK! IP=");
  tft.println(WiFi.localIP());

if (WiFi.status() == WL_CONNECTED){
  //Aquí se carga el chiste.
  nextJoke();
} else{
  tft.println("No hay wifi.")
}

}

void loop() {
  //Y esto es el funcionamiento en sí, cada vez que pulse el botón le da la señal
  //para cambiar el chiste.
  if (digitalRead(BTN_PIN) == LOW) {
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0, 0);
    nextJoke();
  }

  delay(100);
}