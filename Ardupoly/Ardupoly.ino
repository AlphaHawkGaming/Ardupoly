#include "Ardupoly.h"

Ardupoly ardupoly;

void setup() {
    ardupoly.Init();
}

void loop() {
    ardupoly.runGame();
    delay(3000);
    Serial.println("");
    Serial.println("");
    Serial.println("");
}