class Ardupoly
{       
public:
    void Init();
    void runGame();
private:
    void parsePlayerPlace();
    uint8_t rollDice(String& player);
    String getPlaceName() const;

    struct player
    {
        short int money = 1500;
        uint8_t position = 0;

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
    
    player players[4];
    player* currentPlayer = &(players[0]);
};