
Property::Property(Ardupoly* core) 
    : ardupolyCore(core)
{
    exponent = ardupolyCore->propertyReference;

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
        
        if(gameObjectIndex != ardupolyCore->playerIndex) {
            Serial.println(ardupolyCore->gameObjects[gameObjectIndex]);
            propertyRent(gameObjectIndex);
        }
        else {
            Serial.println("you");

            if(propertyRentLevel() != 3) {
                Serial.println("Do you wanna increase the rent level? y/n");

                Utility::clearBuffer();
                while(Serial.available() == 0) {}

                String response = Serial.readString();

                if(response == "y\n") {
                    propertyRentLevel(true);
                }
            }
        }
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
        if(i == ardupolyCore->playerIndex) 
            continue;

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

        if(currentBidder > ardupolyCore->numberOfPlayers || currentBidder < 1 || currentBidder == ardupolyCore->playerIndex + 1) {
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

void Property::propertyRent(uint8_t& propertyOwnerIndex) {
    short int rentLevel = propertyRentLevel();
    short int rentPercentage = 100 + rentLevel * 10;
    short int rent = (rentPercentage / 100) * propertyValue();

    ardupolyCore->currentPlayer->money -= rent;
    ardupolyCore->players[propertyOwnerIndex].money += rent;

    Serial.print("Paid ");
    Serial.print(rent);
    Serial.println(" as rent");
}

uint8_t Property::propertyRentLevel(bool increase) {
    static uint8_t rentLevels[6] = { 0, 0, 0, 0, 0, 0 };

    index = (ardupolyCore->propertyReference / 4);

    if(index > 0)
        index++;

    exponent = ((index + 1) * 4) - (ardupolyCore->propertyReference + 1);
    exponent = 6 - (exponent * 2);

    propertyState = pow(2, exponent) + pow(2, (exponent + 1));
    propertyState &= rentLevels[index];
    propertyState = propertyState >> exponent;

    if(increase && propertyState != 3) {
        propertyState++;

        Serial.print("Increased rent level to ");
        Serial.println(propertyState + 1);

        ardupolyCore->currentPlayer->money -= 400; 

        propertyState = propertyState << exponent;
        rentLevels[index] |= propertyState;
    }

    return propertyState; 
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
        case 0:
            value = 60;
            break;
        case 1:
            value = 60;
            break;
        case 2:
            value = 100;
            break;
        case 3:
            value = 100;
            break;
        case 4:
            value = 120;
            break;
        case 5:
            value = 140;
            break;
        case 6:
            value = 140;
            break;
        case 7:
            value = 140;
            break;
        case 8:
            value = 180;
            break;
        case 9:
            value = 180;
            break;
        case 10:
            value = 200;
            break;
        case 11:
            value = 220;
            break;
        case 12:
            value = 220;
            break;
        case 13:
            value = 240;
            break;
        case 14:
            value = 260;
            break;
        case 16:
            value = 260;
            break;
        case 17:
            value = 280;
            break;
        case 18:
            value = 300;
            break;
        case 19:
            value = 300;
            break;
        case 20:
            value = 320;
            break;
        case 21:
            value = 350;
            break;
        case 22:
            value = 400;
            break;
    }

    return value;
}

Property::~Property() {}