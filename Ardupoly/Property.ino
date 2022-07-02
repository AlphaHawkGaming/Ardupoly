
Property::Property(Ardupoly* core) 
    : ardupolyCore(core)
{
    exponent = ardupolyCore->propertyReference - 65;

    if(exponent < 24 && exponent >= 16) {
        index = 2;
        exponent -= 16;
    }
    else if(exponent < 16 && exponent >= 8) {
        index = 1;
        exponent -= 8;
    }
    else {
        index = 0;
    }   

    propertyState = pow(2, exponent);
    propertyState++; 

    uint8_t gameObjectIndex = propertyOwner();

    if(gameObjectIndex != 5) {
        Serial.print("Property owned by ");
        
        if(gameObjectIndex != ardupolyCore->playerIndex)
            Serial.println(ardupolyCore->gameObjects[gameObjectIndex]);
        else
            Serial.println("you");
    }
    else {
        Serial.println("Do you wanna buy this property? y/n");

        Utility::clearBuffer();
        while(Serial.available() == 0) {}

        String response = Serial.readString();

        if(response == "y\n") {         
            propertyBuy();
        }
    }
}

void Property::propertyBuy() {
    ardupolyCore->currentPlayer->propertyOwned[index] |= propertyState;
    Serial.println("You bought this property!");
}

uint8_t Property::propertyOwner() {
    uint8_t propertyOwner = 5;

    for(int i=0; i<ardupolyCore->numberOfPlayers; i++) {
        if((ardupolyCore->players[i].propertyOwned[index] & propertyState) == propertyState) {
            propertyOwner = i;
        }
    }

    return propertyOwner;
}

Property::~Property() {}