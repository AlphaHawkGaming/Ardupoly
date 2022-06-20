
Ardupoly::Ardupoly() {
    Serial.begin(115200);

    Serial.println(F("            ARDUPOLY              "));
    Serial.println(F(" __________________________________"));
    Serial.println(F("| How many people are gonna play ? |"));
    Serial.println(F("| Allowed values:  2, 3, 4         |"));

    bool initialized = false;

    while(!initialized) {
        while(Serial.available() == 0) {}
        numberOfPlayers = Serial.parseInt();

        if(numberOfPlayers > 4 || numberOfPlayers < 2) {
            Serial.println("# Invalid number of players, try again.");
        }
        else {
            initialized = true;
            for(int i = 0; i < numberOfPlayers; i++) {
                players[i] = player();
            }

            Serial.println(F("\n ------ Let The Game Begin! ------")); 
        }
    }
}

Ardupoly::~Ardupoly() 
{
    
}