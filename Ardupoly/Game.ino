
void Ardupoly::runGame() {
    for(int i = 0; i < numberOfPlayers; i++) {
        Serial.print("| " + gameObjects[i]);
        Serial.print(": ");

        if(players[i].inDebt()) {
            Serial.print(" 0, Debt: ");
            Serial.println(-1 * players[i].money);
        }
        else {
            Serial.print(players[i].money);
            Serial.println(", Debt: 0");
        }
    }

    currentPlayer->position += rollDice(gameObjects[playerIndex]);

    if(currentPlayer->position > 35) {
        currentPlayer->position -= 36;
        currentPlayer->money += 200;
    }

    String tmp;
    getPlaceName(tmp);

    Serial.println("You landed on " + tmp.substring(0, (tmp.length() - 1)));

    propertyReference = (tmp.substring(tmp.length() - 1))[0];
    propertyReference -= 65;

    parsePlayerPlace();
    
    if(playerIndex == (numberOfPlayers - 1)) {
        playerIndex = 0;
    }
    else {
        playerIndex++;
    }

    currentPlayer = &(players[playerIndex]);
}

