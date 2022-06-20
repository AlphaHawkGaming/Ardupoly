class Ardupoly
{
       
public:
     Ardupoly();
    ~Ardupoly(); 
private:
    struct player
    {
        uint32_t money = 1500;
        uint8_t position = 0;
    };

    char numberOfPlayers;
    player players[4];
};