#include"monoMain.h"
Game game;

void setup() {
 Serial.begin(115200);          //Starting the Serial monitor
 randomSeed(analogRead(0));     //this line of code contributes in the generation of random dice value
 randomSeed(analogRead(4));
 
  while(true){                  //entry point
      Serial.println(F("            ARDUPOLY             " ));
      Serial.println(F(" ________________________________ "));
      Serial.println(F("|Number of players allowed: 2,3,4|"));
      while(Serial.available() == 0){}
      nop = Serial.parseInt();

      if(nop > 4 or nop < 2){
        Serial.println(F("|Wrong number of players         |"));
      }
      else{
         for(short int i=0; i<nop; i++){
            game.activePlayers[i] = game.allPlayers[i];       //setting up the number of active players
         }
        break;
      }
  }
  for(short int i=0; i<nop; i++){
    if(game.activePlayers[i] == 'c'){
       car = 1500;
    }
    else if(game.activePlayers[i] == 's'){
      ship = 1500;
    }
    else if(game.activePlayers[i] == 'p'){
      plane = 1500;
    }
    else if(game.activePlayers[i] == 'o'){
      copter = 1500;
    }
  }

Serial.println(F("|      Let The Game Begin!       |")); 
Serial.println(F("|                                |"));
}

void loop() {
  
   short int diceVal1;
   short int diceVal2;
   short int diceVal;
  
  for(short int i=0; i<nop; i++){
   if(game.activePlayers[i] == 'c'){
      Serial.print(F("|Car: "));
      Serial.print(car);
      Serial.print(F(", Debt: "));
      Serial.print(carDebt);
      Serial.println(F("              |"));
      
    }
    else if(game.activePlayers[i] == 's'){
      Serial.print(F("|Ship: "));
      Serial.print(ship);
      Serial.print(F(", Debt: "));
      Serial.print(shipDebt);
      Serial.println(F("             |"));
    }  
    else if(game.activePlayers[i] == 'p'){
      Serial.print(F("|Plane: "));
      Serial.print(plane);
      Serial.print(F(", Debt: "));
      Serial.print(planeDebt);
      Serial.println(F("            |"));
    }
    else if(game.activePlayers[i] == 'o'){
      Serial.print(F("|Copter: "));
      Serial.print(copter);
      Serial.print(F(", Debt: "));
      Serial.print(copterDebt);
      Serial.println(F("           |"));
    }
  }

  clearBuffer();
  
  Serial.println(F(""));
  Serial.print(F("Ready to roll the dice? Press any key! It is currently "));        //rolling the dice

  if(game.currentPlayer == 'c'){
    Serial.println(F("Car's turn"));
  }
  else if(game.currentPlayer == 's'){
    Serial.println(F("Ship's turn"));
  }
  else if(game.currentPlayer == 'p'){
    Serial.println(F("Plane's turn"));
  }
  else if(game.currentPlayer == 'o'){
    Serial.println(F("Copter's turn"));
  }
  
  while(Serial.available() == 0){}
  
  Serial.println(F("Rolling the dice... "));
  
  Serial.println("");
  
  diceVal1 = random(1, 6);                                       //random dice value generation using the random function 
  diceVal2 = random(1, 6);
  
  diceVal = diceVal1 + diceVal2;

  Serial.print(F("DiceVals: "));                                 //temporary part
  Serial.print(diceVal1);
  Serial.print(F(", "));
  Serial.println(diceVal2);
  Serial.println(F(""));
  
  game.jailCheck(&diceVal1, &diceVal2);
  
  game.incrementPosition(diceVal);                               //updating the player's position in the game

  game.switchPlayerPlaces('p'); 
  
  Serial.print(F("Place: "));                      
  Serial.println(game.playerPlace);

  if(!(game.placeCheck())){
    clearBuffer();
    game.buyProperty();                                           //prompting the player to buy the property he landed on
  }

  game.debtCheck();
  
  Serial.println(F("-------------------------------"));
  game.moveToNextPlayer();                                      //updating the game 

  delay(10);
}

      

      
