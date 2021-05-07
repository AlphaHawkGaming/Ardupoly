//declaration file
//variable needed for the player entity
#include <avr/pgmspace.h>

int car;
int ship;
int plane;
int copter; 

int carPos;
int shipPos;
int planePos;
int copterPos;

int nop;

class Game{                                               //Game class that manages all the core functions and game data
  public:
    Game(){
        for(int i=0; i<36; i++){
          propertyState[i] = 0;
        }
    }
  
    ~Game(){}
  
    String playerPlace;
    String currentPlayer = "Car";
    String activePlayers[4];
    const String allPlayers[4] PROGMEM = {"Car","Ship","Plane","Copter"};
    String propertyOwners[36]; 
    
    int currentPosition;
    int propertyState[36];
    const int propertyPrice[36] PROGMEM = {0,60,0,60,0,100,100,0,120,0,140,0,140,140,180,180,0,200,0,220,0,220,240,260,260,0,280,0,300,0,300,320,0,350,0,400};

    void switchPlayerPlaces();
    void moveToNextPlayer();
    void buyProperty();
    bool placeCheck();
    void propertyRent();
    void auction();
    void incrementPosition(int &incrementVal);
    
};

//Utility functions

void clearBuffer();
