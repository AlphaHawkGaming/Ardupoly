
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
            propertyBuy(ardupolyCore->currentPlayer);
            Serial.println("You bought this property");
        }
        else {
            propertyAuction();
        }
    }
}

void Property::propertyAuction() {
    uint8_t leadingBidder;
    bool auctionEnded = false;

    short int bid = 20;

    Serial.println(F("\nAuction!"));
    Serial.println(F("Enter the value next to your player name to raise the bid"));
    
    for(int i=0; i<ardupolyCore->numberOfPlayers; i++) {
        Serial.print(ardupolyCore->gameObjects[i]);
        Serial.print(" → ");
        Serial.print(i + 1);
        Serial.print(" ");
    }
    
    Serial.println("");

    unsigned long auctionTime;

    while(!auctionEnded) {
        Utility::clearBuffer();

        auctionTime = 15000 + millis();

        while(Serial.available() == 0) {
            if(millis() >= auctionTime) {
                auctionEnded = true;
                break;
            }
        }

        if(auctionEnded)
            break;

        uint8_t currentBidder = Serial.parseInt();

        if(currentBidder > ardupolyCore->numberOfPlayers || currentBidder < 1) {
            Serial.println("# Invalid input!");
        }
        else {
            leadingBidder = currentBidder;
            bid += 20;

            Serial.print(ardupolyCore->gameObjects[leadingBidder - 1]);
            Serial.print(": ");
            Serial.println(bid);
        }
    }

    if(bid == 20) {
        Serial.println("Auction ended but nobody bid!");
    }
    else {
        ardupolyCore->players[leadingBidder - 1].money += propertyValue() - bid;
        propertyBuy(&(ardupolyCore->players[leadingBidder - 1]));

        Serial.print(ardupolyCore->gameObjects[leadingBidder - 1]);
        Serial.println(" won the auction and bought the property!");
    }
}

void Property::propertyBuy(Ardupoly::player* buyer) {
    buyer->propertyOwned[index] |= propertyState;
    buyer->money -= propertyValue();
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

short int Property::propertyValue() {
    short int value;

    switch(ardupolyCore->propertyReference) 
    {   
        case 'A':
            value = 60;
            break;
        case 'B':
            value = 60;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 100;
            break;
        case 'E':
            value = 120;
            break;
        case 'F':
            value = 140;
            break;
        case 'G':
            value = 140;
            break;
        case 'H':
            value = 140;
            break;
        case 'I':
            value = 180;
            break;
        case 'J':
            value = 180;
            break;
        case 'K':
            value = 200;
            break;
        case 'L':
            value = 220;
            break;
        case 'M':
            value = 220;
            break;
        case 'N':
            value = 240;
            break;
        case 'O':
            value = 260;
            break;
        case 'P':
            value = 260;
            break;
        case 'Q':
            value = 280;
            break;
        case 'R':
            value = 300;
            break;
        case 'S':
            value = 300;
            break;
        case 'T':
            value = 320;
            break;
        case 'U':
            value = 350;
            break;
        case 'W':
            value = 400;
            break;
    }

    return value;
}

Property::~Property() {}