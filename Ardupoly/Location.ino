void Ardupoly::location() {
    currentPlayer->money -= 100;

    Serial.println(F("Where do you wanna move? (enter the number to the left of the property to move to that property)"));
    Serial.println(F("1 → Old Kent Road"));
    Serial.println(F("3 → Whitechapel Road"));
    Serial.println(F("5 → The Angel Islington"));
    Serial.println(F("6 → Euston Road"));
    Serial.println(F("8 → Pentonville Road"));
    Serial.println(F("10 → Pall Mall"));
    Serial.println(F("12 → Whitehall"));
    Serial.println(F("13 → Northumberland Ave"));
    Serial.println(F("14 → Bow Street"));
    Serial.println(F("15 → Marlborough Street"));
    Serial.println(F("17 → Vine Street"));
    Serial.println(F("19 → Strand"));
    Serial.println(F("21 → Fleet Street"));
    Serial.println(F("22 → Trafalgar Square"));
    Serial.println(F("23 → Leicester Square"));
    Serial.println(F("24 → Conventry Street"));
    Serial.println(F("26 → Picadilly"));
    Serial.println(F("28 → Regent Street"));
    Serial.println(F("30 → Oxford Street"));
    Serial.println(F("31 → Bond Street"));
    Serial.println(F("33 → Park Lane"));
    Serial.println(F("35 → Mayfair"));

    bool inputFlag = false;

    while(!inputFlag)
    {
       uint8_t locationID;

       Utility::clearBuffer();
       while(Serial.available() == 0) {}

       locationID = Serial.parseInt();

       currentPlayer->position = locationID;

       String tmp;
       getPlaceName(tmp);
       propertyReference = tmp.substring(tmp.length() - 1)[0];

       if(propertyReference < 65 && propertyReference > 86) {
           Serial.println("# Invalid input!");
       }
       else {
           propertyReference -= 65;
           inputFlag = true;
       }
    }

    Serial.println(propertyReference);
    Property location(this);
}