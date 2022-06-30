
void Ardupoly::propertyEvent() {

    uint8_t index;
    uint8_t exponent = propertyReference - 65;

    if(exponent < 24 && exponent >= 16) {
        index = 2;
        exponent = propertyReference - 16;
    }
    else if(exponent < 16 && exponent >= 8) {
        index = 1;
        exponent = propertyReference - 8;
    }
    else {
        index = 0;
    }   

    uint8_t returnVal = propertyOwner(index, exponent);

    if(returnVal != 5) {
        Serial.print("Property owned by ");
        Serial.println(gameObjects[returnVal]);
    }
    else {
        Serial.println("Property on sale");
    }
    
}

uint8_t Ardupoly::propertyOwner(uint8_t& index, uint8_t& exponent) {
    uint8_t propertyOwner = 5;
    
    uint8_t propertyState = pow(2, exponent);
    propertyState++; 

    for(int i=0; i<numberOfPlayers; i++) {

        if((players[i].propertyOwned[index] & propertyState) == propertyState) {
            propertyOwner = i;
        }
    }

    return propertyOwner;
}