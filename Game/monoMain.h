short int car;
short int ship;
short int plane;
short int copter;

short int carDebt;
short int shipDebt;
short int planeDebt;
short int copterDebt;

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
        for(short int i=0; i<22; i++){
          rentLevels[i] = 0;
        }
    }
  
    ~Game(){}
  
    String playerPlace;
    char currentPlayer = 'c';
    char activePlayers[4];
    const char allPlayers[4] PROGMEM = {'c','s','p','o'};
    char propertyOwners[36]; 

    bool carJail = false;
    bool shipJail = false;
    bool planeJail = false;
    bool copterJail = false;
    
    short int currentPosition;
    short int propertyState[36];
    const short int propertyPrice[36] PROGMEM = {0,60,0,60,0,100,100,0,120,0,140,0,140,140,180,180,0,200,0,220,0,220,240,260,260,0,280,0,300,0,300,320,0,350,0,400};
    const short int propertyRents[15][5] PROGMEM = {{70,130,220,370,750}, {80,140,240,410,800}, {100,160,260,440,900}, {110,180,290,460,900}, {130,200,310,490,980}, {140,210,330,520,1000}, {160,230,350,550,1100}, {170,250,380,580,1160}, {190,270,400,610,1200}, {200,280,420,640,1300}, {220,300,440,670,1340}, {230,320,460,700,1400}, {250,340,480,740,1440}, {270,360,510,740,1500}, {300,400,560,810,1600}};
    short int rentLevels[22];
    int* auction_pointer;
    
    void moveToNextPlayer();
    void buyProperty();
    bool placeCheck();
    void propertyRent();       //propertyID is the name points to the property
    void debtCheck();
    String switchPlayerPlaces(char attrib);
    void decreasePlayerMoney(short int* value, char attrib);
    bool doublesCheck(short int* val1, short int* val2);
    short int getRentLevel(short int pos);
    void auction(char auction_attrib);
    void incrementPosition(short int &incrementVal);
    void jailCheck(short int* dice1, short int* dice2);
    
};

void clearBuffer();
