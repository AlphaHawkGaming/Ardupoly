void Game::switchPlayerPlaces(){
  switch(currentPosition){
    case 1:
         playerPlace = "Old kent road";
         break;
    case 2:
         playerPlace = "Chance";
         break;
    case 3:
         playerPlace = "Whitechapel Road";
         break;
    case 4:
         playerPlace = "Chance";
         break;
    case 5:
         playerPlace = "The Angel, Islington";
         break;
    case 6:
         playerPlace = "Euston Road";
         break;
    case 7:
         playerPlace = "Auction";
         break;
    case 8:
         playerPlace = "Pentonville Road";
         break;
    case 9:
         playerPlace = "Just Visiting";
         break;
    case 10:
         playerPlace = "Pall Mall";
         break;
    case 11:
         playerPlace = "Chance";
         break;
    case 12:
         playerPlace = "Whitehall";
         break;
    case 13:
         playerPlace = "Northumberland Avenue";
         break;
    case 14:
         playerPlace = "Bow Street";
         break; 
    case 15:
         playerPlace = "Marlborough Street";
         break;
    case 16:
         playerPlace = "Auction";
         break;
    case 17:
         playerPlace = "Vine Street";
         break;
    case 18:
         playerPlace = "Free Parking";
         break;
    case 19:
         playerPlace = "Strand";
         break;
    case 20:
         playerPlace = "Chance";
         break;
    case 21:
         playerPlace = "Fleet Street";
         break;
    case 22:
         playerPlace = "Trafalgar Square";
         break;
    case 23:
         playerPlace = "Leicester Square";
         break;
    case 24:
         playerPlace = "Coventry Street";
         break;
    case 25:
         playerPlace = "Auction";
         break;
    case 26:
         playerPlace = "Picadilly";
         break;
    case 27:
         playerPlace = "Jail";
         break;
    case 28:
         playerPlace = "Regent Street";
         break;
    case 29:
         playerPlace = "Chance";
         break;
    case 30:
         playerPlace = "Oxford Street";
         break;             
    case 31:
         playerPlace = "Bond Street";
         break; 
    case 32:
         playerPlace = "Chance";
         break;
    case 33:
         playerPlace = "Park Lane";
         break;
    case 34:
         playerPlace = "Auction";
         break;
    case 35:
         playerPlace = "Mayfair";
         break;
    default:
          playerPlace = "Start";
          currentPosition = 0;
          
          if(currentPlayer == 'c'){
            car += 200;
            carPos = 0;
          }
          else if(currentPlayer == 's'){
            ship += 200;
            shipPos = 0;
          }
          else if(currentPlayer == 'p'){
            plane += 200;
            planePos = 0;
          }
          else if(currentPlayer == 'o'){
            copter += 200;
            copterPos = 0;
          }
          break;
  }
}

void Game::moveToNextPlayer(){
  if(nop == 2){
    if(currentPlayer == 'c'){
      currentPlayer = 's';
    }
    else if(currentPlayer == 's'){
      currentPlayer = 'c';
    }
  }
  else if(nop == 3){
    if(currentPlayer == 'c'){
      currentPlayer = 's';
    }
    else if(currentPlayer == 's'){
      currentPlayer = 'p';
    }
    else if(currentPlayer == 'p'){
      currentPlayer = 'c';
    }
  }
  else if(nop == 4){
    if(currentPlayer == 'c'){
      currentPlayer = 's';
    }
    else if(currentPlayer == 's'){
      currentPlayer = 'p';
    }
    else if(currentPlayer == 'p'){
      currentPlayer = 'o';
    }
    else if(currentPlayer == 'o'){
      currentPlayer = 'c';
    }
  }
}

void Game::buyProperty(){
  short int input;
  
  if(propertyState[currentPosition] == 0){
    Serial.println(F("Do you want to buy this property? 1 - Yes, 0 - No"));
    Serial.print(F("Price of the property: "));
    Serial.println(propertyPrice[currentPosition]);
    
    while(Serial.available() == 0){}
    input = Serial.parseInt();
    
   if(input == 1){
      Serial.print(F("Your money balance: "));

      if(currentPlayer == 'c'){
        car = car - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = 'c';
        Serial.println(car);
      }
      else if(currentPlayer == 's'){
        ship = ship - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = 's';
        Serial.println(ship);
      }
      else if(currentPlayer == 'p'){
        plane = plane - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = 'p';
        Serial.println(plane);
      }
      else if(currentPlayer == 'o'){
        copter = copter - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = 'o';
        Serial.println(copter);
      }
    }
    else{
      Serial.println("");
      Serial.println(F("Auction"));
      Serial.println(F("Warning: if no one bids within 20 seconds, the auction will end"));
      Serial.println(F("Type the values below that correspond to your player name to increase the auction bid"));
      Serial.println(F("Auction starts now!"));
      auction();
    }
    Serial.println("");
  }
  else{
    if(propertyOwners[currentPosition] == 'c'){
      Serial.println(F("This property belongs to: Car"));
    }
    else if(propertyOwners[currentPosition] == 's'){
      Serial.println(F("This property belongs to: Ship"));
    }
    else if(propertyOwners[currentPosition] == 'p'){
      Serial.println(F("This property belongs to: Plane"));
    }
    else if(propertyOwners[currentPosition] == 'o'){
      Serial.println(F("This property belongs to: Copter"));
    }
    
    if(currentPlayer == 'c'){
      propertyRent(&car);     
    }
    else if(currentPlayer == 's'){
      propertyRent(&ship);     
    }
    else if(currentPlayer == 'p'){
      propertyRent(&plane);     
    }
    else if(currentPlayer == 'o'){
      propertyRent(&copter);     
    }
    
  }
}

void Game::propertyRent(short int* renter){
  if(*renter < 70){
    Serial.println(F("You don't have enough money to pay the rent"));
    return;
  }
}

bool Game::placeCheck(){
  if(currentPosition == 18 or currentPosition == 9 or currentPosition == 0){
    return true;
  }
  else if(currentPosition == 2 or currentPosition == 4 or currentPosition == 11 or currentPosition == 20 or currentPosition == 29 or currentPosition == 32){
    return true; //remove this later
    //goto chance  
  }
  else if(currentPosition == 7 or currentPosition == 16 or currentPosition == 25 or currentPosition == 34){
    return true; //remove this later
    //goto auction                            
  }
  else if(currentPosition == 27){
    if(currentPlayer == 'c'){
      carPos = 9;
    }
    if(currentPlayer == 's'){
      shipPos = 9;
    }
    if(currentPlayer == 'p'){
      planePos = 9;
    }
    if(currentPlayer == 'o'){
      copterPos = 9;
    }
    return true;
  }
  else{
    return false;
  }
}

void Game::incrementPosition(short int &incrementVal){
  if(currentPlayer == 'c'){
    carPos += (short int) incrementVal;  
    currentPosition = carPos;
  }
  
  if(currentPlayer == 's'){
    shipPos += (short int) incrementVal;  
    currentPosition = shipPos;
  }
  
  if(currentPlayer == 'p'){
    planePos += (short int) incrementVal;  
    currentPosition = planePos;
  }
  
  if(currentPlayer == 'o'){
    copterPos += (short int) incrementVal;  
    currentPosition = copterPos;
  }
}

void Game::auction(){
  clearBuffer();

  char currentBidder;
  char auction_input;
  
  int auction_bid = 20;
  
  unsigned long auction_time;  //auction's total time is 20 seconds
  
    
    while(true){
    
    Serial.println("");
    Serial.println(F("Car → c, Ship → s, Plane → p, Copter → o"));
    Serial.print(F("current bid: "));
    Serial.println(auction_bid);

    clearBuffer();

    auction_time = 20000 + millis();
    //Serial.println(auction_time);
    
    while(Serial.available() == 0){
      unsigned long currentTime = millis();
      
      if(currentTime >= auction_time){
        Serial.println("");
        Serial.println(F("The auction ended!"));

        if(auction_bid == 20){
          Serial.println(F("Nobody won the auction"));
          return;
        }
            
        Serial.print(F("Total Bid: "));
        Serial.println(auction_bid);
        Serial.print(F("Winner of the auction is: "));

        if(currentBidder == 'c'){
          Serial.println(F("Car"));
          car -= auction_bid;
          propertyOwners[currentPosition] == 'c';
          return;
        }
        else if(currentBidder == 's'){
          Serial.println(F("Ship"));
          ship -= auction_bid;
          propertyOwners[currentPosition] == 's';
          return;
        }
        else if(currentBidder == 'p'){
          Serial.println(F("Plane"));
          plane -= auction_bid;
          propertyOwners[currentPosition] == 'p';
          return;
        }
        else if(currentBidder == 'o'){
          Serial.println(F("Copter"));
          copter -= auction_bid;
          propertyOwners[currentPosition] == 'o';
          return;
        }
      }
    }
    
    auction_input = Serial.read();
    
    if(auction_input == 'c' or auction_input == 'C'){
      auction_bid += 20;
      currentBidder = 'c';
    }
    else if(auction_input == 's' or auction_input == 'S'){
      auction_bid += 20;
      currentBidder = 's';
    }
    else if(auction_input == 'p' or auction_input == 'P'){
      auction_bid += 20;
      currentBidder = 'p';
    }
    else if(auction_input == 'o' or auction_input == 'O'){
      auction_bid += 20;
      currentBidder = 'o';
    }
    else{
      Serial.println(F("Invalid input!"));
    }
  }
}


void clearBuffer(){
  while(Serial.available())                                       //clearing the serial buffer
    Serial.read();
}
