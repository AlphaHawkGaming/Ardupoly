class Ardupoly
{       
public:
    void Init();
    void runGame();
private:
    struct player;
    
    void parsePlayerPlace();
    void getPlaceName(String& playerPlace) const;

    void propertyEvent();
    uint8_t propertyOwner(uint8_t& index, uint8_t& exponent);

    uint8_t rollDice(String& player);

    struct player
    {
        short int money = 1500;
        uint8_t position = 0;
        uint8_t propertyOwned[3] = { 0, 0, 0 };

        bool inDebt() {
            if(money < 0)
                return true;
            else
                return false;
        }

        bool inJail() {
            if(position == 27)
                return true;
            else
                return false;
        }
    };

    uint8_t numberOfPlayers;
    char propertyReference;
    
    player players[4];
    player* currentPlayer = &(players[0]);
    String gameObjects[4] = { "Car", "Ship", "Plane", "Copter" };
};