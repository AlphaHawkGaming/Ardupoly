#include "Ardupoly.h"
#include "Property.h"
#include "Utility.hpp"

Ardupoly ardupoly;

void setup() {
    ardupoly.Init();
}

void loop() {
    ardupoly.runGame();
    
    Serial.println("\n\n");
    delay(1000);
}