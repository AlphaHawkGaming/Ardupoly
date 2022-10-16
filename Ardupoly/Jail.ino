void Ardupoly::jail() 
{
    if(currentPlayer->jailBailChances <= 3) {
        Serial.print("Wanna get out of jail? Bail chances left - ");
        Serial.println(currentPlayer->jailBailChances);
        Serial.println(" - Pay 100 to the bank (1)");
        Serial.println(" - Roll a double (2)");

        Utility::clearBuffer();
        while(Serial.available() == 0) {}

        uint8_t choice = Serial.parseInt();

        if(choice == 1) {
            currentPlayer->money -= 100;
            currentPlayer->jailBailChances = 5;
            Serial.println("See ya later jail!");
        }
        else if(choice == 2) {
            String tmp = "";
            uint8_t diceVal = rollDice(tmp);

            if(diceVal == 0) {
                currentPlayer->jailBailChances = 5;
                Serial.println("Yee-haw! You got out of jail!");
            }
            else {
                Serial.println("You didn't roll a double");

                if(currentPlayer->jailBailChances == 0) {
                    Serial.println("You are now forced to pay 100 to get out of jail");
                    currentPlayer->money -= 100;
                    currentPlayer->jailBailChances = 5;
                }
            }
        }
    }
    else {
        Serial.println("Phew! that's bad!");
    }

    currentPlayer->jailBailChances--;
}