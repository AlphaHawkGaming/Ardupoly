//definition file
//refer to monoMain.h


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
  int input;
  
  if(propertyState[currentPosition] == 0){
    Serial.println("Do you want to buy this property? 1 - Yes, 0 - No");
    Serial.print("Price of the property: ");
    Serial.println(propertyPrice[currentPosition]);
    
    while(Serial.available() == 0){}
    input = Serial.parseInt();
    
   if(input == 1){
      Serial.print("Your money balance: ");

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
      Serial.println("Auction");
      auction();
    }
    Serial.println("");
  }
  else{
    Serial.print("This property belongs to: ");
    Serial.println(propertyOwners[currentPosition]);

    //rent part come here
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
    carPos += (int) incrementVal;  
    currentPosition = carPos;
  }
  
  if(currentPlayer == "Ship"){
    shipPos += (int) incrementVal;  
    currentPosition = shipPos;
  }
  
  if(currentPlayer == "Plane"){
    planePos += (int) incrementVal;  
    currentPosition = planePos;
  }
  
  if(currentPlayer == "Copter"){
    copterPos += (int) incrementVal;  
    currentPosition = copterPos;
  }
}

void Game::auction(){
  clearBuffer();

  char currentBidder;
  char auction_input;
  
  int auction_bid = 20;
  unsigned long previousTime;
  const long auction_time = 20 * 1000;  //to get the required time

  Serial.println("Warning: if no one bids within 20 seconds, the auction will end");
  Serial.println("Type the values below that correspond to your player name to increase the auction bid");
  Serial.println("Auction starts now!");

  while(true){
    unsigned long currentTime = millis();
    
    Serial.println("Car → c, Ship → s, Plane → p, Copter → o");
    Serial.print("current bid: ");
    Serial.println(auction_bid);
    
    while(Serial.available() == 0){
      if(currentTime - previousTime  >= auction_time){
        previousTime = currentTime;

        Serial.println("The auction ended!");
        Serial.print("Winner of the auction is: ");
        Serial.println(currentBidder);

        if(currentBidder == 'c'){
          car -= auction_bid;
        }
        else if(currentBidder == 's'){
          ship -= auction_bid;
        }
        else if(currentBidder == 'p'){
          plane -= auction_bid;
        }
        else if(currentBidder == 'o'){
          copter -= auction_bid;
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
          Serial.println("Invalid input!");
          //error handling to do
          return;
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
          Serial.println("Invalid input!");
          //error handling to do
          return;
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
          Serial.println("Invalid input!");
          //error handling to do
          return;
        }
    }
  }
}

void clearBuffer(){
  while(Serial.available())                                       //clearing the serial buffer
    Serial.read();
}
