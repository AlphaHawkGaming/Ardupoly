
uint8_t Ardupoly::rollDice(String& player) {

  uint8_t diceVal1 = 0;
  uint8_t diceVal2 = 0;
  
  if(!currentPlayer->inJail()) {
    Serial.print(F("Ready to roll the dice? Press any key! It is currently "));
    Serial.println(player + "'s turn");

    while(Serial.available() == 0){}

    uint8_t doubleFlag = 0;

    while(diceVal1 == diceVal2) {
      doubleFlag++;

      if(doubleFlag == 2) {
        Serial.println(F("Rolling again as you rolled a double earlier!"));
      }
      else if(doubleFlag == 3) {
        diceVal1, diceVal2 = 0;
        break;
      }

      diceVal1 = random(1, 6);
      diceVal2 = random(1, 6);

      Serial.print(F("You rolled: "));
      Serial.print(diceVal1);
      Serial.print(", ");
      Serial.println(diceVal2);
    }
  }

  return diceVal1 + diceVal2;
}