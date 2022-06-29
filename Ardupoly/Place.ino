
void Ardupoly::parsePlayerPlace() {
     if(currentPlayer->position == 2 or currentPlayer->position == 4 or currentPlayer->position == 11 or currentPlayer->position == 20 or currentPlayer->position == 29 or currentPlayer->position == 32) {
          //Chance
          return;
     }
     else if(currentPlayer->position == 7 or currentPlayer->position == 16 or currentPlayer->position == 25 or currentPlayer->position == 34) {
          //Location
          return;
     }
     else if(currentPlayer->position != 18 or currentPlayer->position != 9 or currentPlayer->position != 0) {
          Serial.println("Property Stuff");


          
     }
    
}

String Ardupoly::getPlaceName() const {
    String playerPlace;

    switch(currentPlayer->position) {
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
           playerPlace = "Location";
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
           playerPlace = "Location";
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
           playerPlace = "Location";
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
           playerPlace = "Location";
           break;
      case 35:
           playerPlace = "Mayfair";
           break;
      default:
            playerPlace = "Start";
            break;
    }

    return playerPlace;
}