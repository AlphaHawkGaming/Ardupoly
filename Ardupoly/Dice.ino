
uint8_t Ardupoly::rollDice(String& player) {
  uint8_t diceVal1 = 0;
  uint8_t diceVal2 = 0;
  
  if(player != "")
      Serial.println("It is currently " + player + "'s turn");
    else
      Serial.println("");

  if(!currentPlayer->inJail() || player == "") {
    Serial.print(F("Ready to roll the dice? Press any key! "));

    Utility::clearBuffer();
    while(Serial.available() == 0){}

    uint8_t doubleFlag = 0;

    while(diceVal1 == diceVal2) {
      doubleFlag++;

      if(doubleFlag == 2 && player != "") {
        Serial.println(F("Rolling again as you rolled a double earlier!"));
      }
      else if(doubleFlag == 3 || (doubleFlag == 2 && player == "")) {
        currentPlayer->position = 27;
        diceVal1 = 0;
        diceVal2 = 0;
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