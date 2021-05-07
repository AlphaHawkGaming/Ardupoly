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
          if(currentPlayer == "Car"){
            car += 200;
          }
          else if(currentPlayer == "Ship"){
            ship += 200;
          }
          else if(currentPlayer == "Plane"){
            plane += 200;
          }
          else if(currentPlayer == "Copter"){
            copter += 200;
          }
          break;
  }
}

void Game::moveToNextPlayer(){
  if(nop == 2){
    if(currentPlayer == "Car"){
      currentPlayer = "Ship";
    }
    else if(currentPlayer == "Ship"){
      currentPlayer = "Car";
    }
  }
  else if(nop == 3){
    if(currentPlayer == "Car"){
      currentPlayer = "Ship";
    }
    else if(currentPlayer == "Ship"){
      currentPlayer = "Plane";
    }
    else if(currentPlayer == "Plane"){
      currentPlayer = "Car";
    }
  }
  else if(nop == 4){
    if(currentPlayer == "Car"){
      currentPlayer = "Ship";
    }
    else if(currentPlayer == "Ship"){
      currentPlayer = "Plane";
    }
    else if(currentPlayer == "Plane"){
      currentPlayer = "Copter";
    }
    else if(currentPlayer == "Copter"){
      currentPlayer == "Car";
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

      if(currentPlayer == "Car"){
        car = car - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = "Car";
        Serial.println(car);
      }
      else if(currentPlayer == "Ship"){
        ship = ship - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = "Ship";
        Serial.println(ship);
      }
      else if(currentPlayer == "Plane"){
        plane = plane - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = "Plane";
        Serial.println(plane);
      }
      else if(currentPlayer == "Copter"){
        copter = copter - propertyPrice[currentPosition];
        propertyState[currentPosition] = 1;
        propertyOwners[currentPosition] = "Copter";
        Serial.println(copter);
      }
    }
    else{
      Serial.println("");
      Serial.println("Auction");
      Serial.println("Warning: if no one bids within 20 seconds, the auction will end");
      Serial.println("Type the values below that correspond to your player name to increase the auction bid");
      Serial.println("Auction starts now!");
      auction();
    }
    Serial.println("");
  }
  else{
    Serial.print("This property belongs to: ");
    Serial.println(propertyOwners[currentPosition]);
    
    if(currentPlayer == "Car"){
      propertyRent(&car);     
    }
    else if(currentPlayer == "Ship"){
      propertyRent(&ship);     
    }
    else if(currentPlayer == "Plane"){
      propertyRent(&plane);     
    }
    else if(currentPlayer == "Copter"){
      propertyRent(&copter);     
    }
    
  }
}

void Game::propertyRent(short int* renter){
  switch(currentPosition){
    case 1:
         Serial.println(F("Paid rent value of: 70"));
         *renter -= 70;
         break;
    case 3:
         Serial.println(F("Paid rent value of: 70"));
         *renter -= 70;
         break;
    case 5:
         Serial.println(F("Paid rent value of: 80"));
         *renter -= 80;
         break;
    case 6:
         Serial.println(F("Paid rent value of: 80"));
         *renter -= 80;
         break;
    case 8:
         Serial.println(F("Paid rent value of: 100"));
         *renter -= 100;
         break;
    case 10:
         Serial.println(F("Paid rent value of: 110"));
         *renter -= 110;
         break;
    case 12:
         Serial.println(F("Paid rent value of: 110"));
         *renter -= 110;
         break;
    case 13:
         Serial.println(F("Paid rent value of: 130"));
         *renter -= 130;
         break;
    case 14:
         Serial.println(F("Paid rent value of: 140"));
         *renter -= 140;
         break; 
    case 15:
         Serial.println(F("Paid rent value of: 140"));
         *renter -= 140;
         break;
    case 17:
         Serial.println(F("Paid rent value of: 160"));
         *renter -= 160;
         break;
    case 19:
         Serial.println(F("Paid rent value of: 170"));
         *renter -= 170;
         break;
    case 21:
         Serial.println(F("Paid rent value of: 170"));
         *renter -= 170;
         break;
    case 22:
         Serial.println(F("Paid rent value of: 190"));
         *renter -= 190;
         break;
    case 23:
         Serial.println(F("Paid rent value of: 200"));
         *renter -= 200;
         break;
    case 24:
         Serial.println(F("Paid rent value of: 200"));
         *renter -= 200;
         break;
    case 26:
         Serial.println(F("Paid rent value of: 220"));
         *renter -= 220;
         break;
    case 28:
         Serial.println(F("Paid rent value of: 230"));
         *renter -= 230;
         break;
    case 30:
         Serial.println(F("Paid rent value of: 230"));
         *renter -= 230;
         break;             
    case 31:
         Serial.println(F("Paid rent value of: 250"));
         *renter -= 250;
         break;
    case 33:
         Serial.println(F("Paid rent value of: 270"));
         *renter -= 270;
         break;
    case 34:
         Serial.println(F("Paid rent value of: 300"));
         *renter -= 300;
         break;
    case 35:
         Serial.println(F("Paid rent value of: 220"));
         *renter -= 220;
         break;
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
    if(currentPlayer == "Car"){
      carPos = 9;
    }
    if(currentPlayer == "Ship"){
      shipPos = 9;
    }
    if(currentPlayer == "Plane"){
      planePos = 9;
    }
    if(currentPlayer == "Copter"){
      copterPos = 9;
    }
    return true;
  }
  else{
    return false;
  }
}

void Game::incrementPosition(int &incrementVal){
  if(currentPlayer == "Car"){
    carPos += (short int) incrementVal;  
    currentPosition = carPos;
  }
  
  if(currentPlayer == "Ship"){
    shipPos += (short int) incrementVal;  
    currentPosition = shipPos;
  }
  
  if(currentPlayer == "Plane"){
    planePos += (short int) incrementVal;  
    currentPosition = planePos;
  }
  
  if(currentPlayer == "Copter"){
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
    Serial.print("current bid: ");
    Serial.println(auction_bid);

    clearBuffer();

    auction_time = 20000 + millis();
    //Serial.println(auction_time);
    
    while(Serial.available() == 0){
      unsigned long currentTime = millis();
      
      if(currentTime >= auction_time){
        Serial.println("");
        Serial.println("The auction ended!");
        Serial.print("Total Bid: ");
        Serial.println(auction_bid);
        Serial.print("Winner of the auction is: ");

        if(currentBidder == 'c'){
          Serial.println("Car");
          car -= auction_bid;
          return;
        }
        else if(currentBidder == 's'){
          Serial.println("Ship");
          ship -= auction_bid;
          return;
        }
        else if(currentBidder == 'p'){
          Serial.println("Plane");
          plane -= auction_bid;
          return;
        }
        else if(currentBidder == 'o'){
          Serial.println("Copter");
          copter -= auction_bid;
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
      Serial.println("Invalid input!");
    }
  }
}


void clearBuffer(){
  while(Serial.available())                                       //clearing the serial buffer
    Serial.read();
}
