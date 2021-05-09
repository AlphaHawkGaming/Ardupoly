short int car;
short int ship;
short int plane;
short int copter;

short int carPos;
short int shipPos;
short int planePos;
short int copterPos;

short int nop;

class Game{                                               //Game class that manages all the core functions and game data
  public:
    Game(){
        for(short int i=0; i<36; i++){
          propertyState[i] = 0;
        }
    }
  
    ~Game(){}
  
    String playerPlace;
    char currentPlayer = 'c';
    char activePlayers[4];
    const char allPlayers[4] PROGMEM = {'c','s','p','o'};
    char propertyOwners[36]; 
    
    short int currentPosition;
    short int propertyState[36];
    const short int propertyPrice[36] PROGMEM = {0,60,0,60,0,100,100,0,120,0,140,0,140,140,180,180,0,200,0,220,0,220,240,260,260,0,280,0,300,0,300,320,0,350,0,400};

    void switchPlayerPlaces();
    void moveToNextPlayer();
    void buyProperty();
    bool placeCheck();
    void propertyRent(short int* renter);       //propertyID is the name points to the property
    void auction();
    void incrementPosition(short int &incrementVal);
    
};

void clearBuffer();
