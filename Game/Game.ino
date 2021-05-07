#include"monoMain.h"
Game game;

void setup() {
 Serial.begin(115200);          //Starting the Serial monitor
 randomSeed(analogRead(0));     //this line of code contributes in the generation of random dice value
  
  while(true){                  //entry point
      Serial.println(F("Number of players allowed: 2,3,4"));
      while(Serial.available() == 0){}
      nop = Serial.parseInt();

      if(nop > 4 or nop < 2){
        Serial.println(F("Wrong number of players"));
      }
      else{
         for(char i=0; i<nop; i++){
            game.activePlayers[i] = game.allPlayers[i];       //setting up the number of active players
         }
        break;
      }
  }
  for(char i=0; i<nop; i++){
    if(game.activePlayers[i] == "Car"){
       car = 1500;
    }
    else if(game.activePlayers[i] == "Ship"){
      ship = 1500;
    }
    else if(game.activePlayers[i] == "Plane"){
      plane = 1500;
    }
    else if(game.activePlayers[i] == "Copter"){
      copter = 1500;}
  }

Serial.println("Welcome to Ardupoly"); 
  Serial.println("");
}

void loop() {
  
   int diceVal1;
   int diceVal2;
   int diceVal;
  
  for(short int i=0; i<nop; i++){
    Serial.print(game.activePlayers[i]);
    Serial.print(": ");

    if(game.activePlayers[i] == "Car"){
      Serial.println(car);
    }
    else if(game.activePlayers[i] == "Ship"){
      Serial.println(ship);
    }  
    else if(game.activePlayers[i] == "Plane"){
      Serial.println(plane);
    }
    else if(game.activePlayers[i] == "Copter"){
      Serial.println(copter);
    }
  }

  clearBuffer();
  
  Serial.println(F(""));
  Serial.println ("Ready to roll the dice? Press any key! It is currently " + game.currentPlayer + "'s turn");        //rolling the dice
  while(Serial.available() == 0){}
  
  Serial.println("Rolling the dice... " + game.currentPlayer);
  
  Serial.println(F(""));
  
  diceVal1 = random(1, 6);                                       //random dice value generation using the random function 
  diceVal2 = random(1, 6);
  
  diceVal = diceVal1 + diceVal2;
  
  game.incrementPosition(diceVal);                               //updating the player's position in the game

  game.switchPlayerPlaces(); 
  
 
  
  Serial.print(F("Place: "));                      
  Serial.println(game.playerPlace);

  if(!(game.placeCheck())){
    clearBuffer();
    game.buyProperty();                                           //prompting the player to buy the property he landed on
                                                                  
  }

  Serial.println(F("-------------------------------"));
  game.moveToNextPlayer();                                      //updating the game 
  
 
  
}

      

      
