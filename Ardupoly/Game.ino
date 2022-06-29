
void Ardupoly::runGame() {

    static uint8_t playerIndex = 0;
    String gameObjects[4] = { "Car", "Ship", "Plane", "Copter" };

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

    Serial.println("You landed on " + getPlaceName());

    parsePlayerPlace();
    
    if(playerIndex == (numberOfPlayers - 1)) {
        playerIndex = 0;
    }
    else {
        playerIndex++;
        currentPlayer = &(players[playerIndex]);
    }
}