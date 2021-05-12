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

     propertyRent();
  }
}

void Game::propertyRent(){
 if(currentPlayer == propertyOwners[currentPosition]){
    Serial.println(F("This is your property"));
    return;
  }
  
  short int rentLevel;
  short int rentVal;
  
  switch(currentPosition){
    case 1:
         rentLevel = getRentLevel(0);
         rentVal = propertyRents[0][rentLevel];
         break;
    case 3:
         rentLevel = getRentLevel(1);
         rentVal = propertyRents[0][rentLevel];
         break;
    case 5:
         rentLevel = getRentLevel(2);
         rentVal = propertyRents[1][rentLevel];
        break; 
    case 6:
         rentLevel = getRentLevel(3);
         rentVal = propertyRents[1][rentLevel];
         break; 
    case 8:
         rentLevel = getRentLevel(4);
         rentVal = propertyRents[2][rentLevel];
         break; 
    case 10:
         rentLevel = getRentLevel(5);
         rentVal = propertyRents[3][rentLevel];
         break;
    case 12:
         rentLevel = getRentLevel(6);
         rentVal = propertyRents[3][rentLevel];
         break;
    case 13:
         rentLevel = getRentLevel(7);
         rentVal = propertyRents[4][rentLevel]; 
         break;
    case 14:
         rentLevel = getRentLevel(8);
         rentVal = propertyRents[5][rentLevel];
         break;
    case 15:
         rentLevel = getRentLevel(9);
         rentVal = propertyRents[5][rentLevel];
         break;
    case 17:
         rentLevel = getRentLevel(10);
         rentVal = propertyRents[6][rentLevel];
         break;
    case 19:
         rentLevel = getRentLevel(11);
         rentVal = propertyRents[7][rentLevel];
         break;
    case 21:
         rentLevel = getRentLevel(12);
         rentVal = propertyRents[7][rentLevel];
         break;
    case 22:
         rentLevel = getRentLevel(13);
         rentVal = propertyRents[8][rentLevel];
         break;
    case 23:
         rentLevel = getRentLevel(14);
         rentVal = propertyRents[9][rentLevel];
         break;
    case 24:
         rentLevel = getRentLevel(15);
         rentVal = propertyRents[9][rentLevel];
         break;
    case 26:
         rentLevel = getRentLevel(16);
         rentVal = propertyRents[10][rentLevel];
         break;
    case 28:
         rentLevel = getRentLevel(17);
         rentVal = propertyRents[11][rentLevel];
         break;
    case 30:
         rentLevel = getRentLevel(18);
         rentVal = propertyRents[11][rentLevel];
         break;
    case 31:
         rentLevel = getRentLevel(19);
         rentVal = propertyRents[12][rentLevel];
         break;
    case 33:
         rentLevel = getRentLevel(20);
         rentVal = propertyRents[13][rentLevel];
         break;
    case 35:
         rentLevel = getRentLevel(21);
         rentVal = propertyRents[14][rentLevel];
         break;
  }

  if(currentPlayer == 'c'){
    car -= rentVal;
  }
  else if(currentPlayer == 's'){
    ship -= rentVal;
  }
  else if(currentPlayer == 'p'){
    plane -= rentVal;
  }
  else if(currentPlayer == 'o'){
    copter -= rentVal;
  }
  
  if(propertyOwners[currentPosition] == 'c'){
    car += rentVal;
  }
  else if(propertyOwners[currentPosition] == 's'){
    ship += rentVal;
  }
  else if(propertyOwners[currentPosition] == 'p'){
    plane += rentVal;
  }
  else if(propertyOwners[currentPosition] == 'o'){
    copter += rentVal;
  }
  
  Serial.print(F("Paid rent value of: "));
  Serial.println(rentVal);
}

short int Game::getRentLevel(short int pos){
  if(rentLevels[pos] != 5){
    rentLevels[pos] += 1;
  }
  return rentLevels[pos];
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
    return true;
  }
  else if(currentPosition == 27){
    if(currentPlayer == 'c'){
      carPos = 9;
      carJail = true;
    }
    if(currentPlayer == 's'){
      shipPos = 9;
      shipJail = true;
    }
    if(currentPlayer == 'p'){
      planePos = 9;
      planeJail = true;
    }
    if(currentPlayer == 'o'){
      copterPos = 9;
      copterJail = true;
    }
    return true;
  }
  else{
    return false;
  }
}

void Game::incrementPosition(short int &incrementVal){  
  if(currentPlayer == 'c'){
    if(!carJail){
      carPos += (short int) incrementVal;  
    }
    currentPosition = carPos;
  }
  
  if(currentPlayer == 's'){
    if(!shipJail){
      shipPos += (short int) incrementVal;  
    }
    currentPosition = shipPos;
  }
  
  if(currentPlayer == 'p'){
    if(!planeJail){
      planePos += (short int) incrementVal;  
    }
    currentPosition = planePos;
  }
  
  if(currentPlayer == 'o'){
    if(!copterJail){
      copterPos += (short int) incrementVal;  
    }
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

    auction_time = 15000 + millis();
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

   if(nop == 2){
      if(auction_input == 'c' or auction_input == 'C'){
        auction_bid += 20;
        currentBidder = 'c';
      }
      else if(auction_input == 's' or auction_input == 'S'){
        auction_bid += 20;
        currentBidder = 's';
      }
      else{
        Serial.println(F("Invalid input!"));
      }
   }
   else if(nop == 3){
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
      else{
        Serial.println(F("Invalid input!"));
      }
   }
   else{
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
}

void Game::jailCheck(short int* dice1, short int* dice2){
  switch(currentPlayer){
    case 'c':
             if(carJail == true){
              if(*dice1 == *dice2){
                carJail = false;
              }
            }
            break;
    case 's':
             if(shipJail == true){
              if(*dice1 == *dice2){
                shipJail = false;
              }
             }
             break;
    case 'p':
             if(planeJail == true){
              if(*dice1 == *dice2){
                planeJail = false;
              }
            }
            break;
    case 'o':
             if(copterJail == true){
              if(*dice1 == *dice2){
                copterJail = false;
              }
            }
            break;
  }
}

void clearBuffer(){
  while(Serial.available())                                       //clearing the serial buffer
    Serial.read();
}
