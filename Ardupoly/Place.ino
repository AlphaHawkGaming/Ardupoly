
void Ardupoly::parsePlayerPlace() {
     if(currentPlayer->position == 2 or currentPlayer->position == 4 or currentPlayer->position == 11 or currentPlayer->position == 20 or currentPlayer->position == 29 or currentPlayer->position == 32) {
          //Chance 
          return;
     }
     else if(currentPlayer->position == 7 or currentPlayer->position == 16 or currentPlayer->position == 25 or currentPlayer->position == 34) {
          location();
     }
     else if(currentPlayer->position != 18 && currentPlayer->position != 9 && currentPlayer->position != 27 && currentPlayer->position != 0) {
          Property propertyEvent(this);
     }
     else if(currentPlayer->position == 27) {
          jail();
     }
}

void Ardupoly::getPlaceName(String& playerPlace) const {
     switch(currentPlayer->position) {
      case 1:
           playerPlace = "Old kent roadA";
           break;
      case 2:
           playerPlace = "Chance ";
           break;
      case 3:
           playerPlace = "Whitechapel RoadB";
           break;
      case 4:
           playerPlace = "Chance ";
           break;
      case 5:
           playerPlace = "The Angel, IslingtonC";
           break;
      case 6:
           playerPlace = "Euston RoadD";
           break;
      case 7:
           playerPlace = "Location ";
           break;
      case 8:
           playerPlace = "Pentonville RoadE";
           break;
      case 9:
           playerPlace = "Just Visiting ";
           break;
      case 10:
           playerPlace = "Pall MallF";
           break;
      case 11:
           playerPlace = "Chance ";
           break;
      case 12:
           playerPlace = "WhitehallG";
           break;
      case 13:
           playerPlace = "Northumberland AvenueH";
           break;
      case 14:
           playerPlace = "Bow StreetI";
           break; 
      case 15:
           playerPlace = "Marlborough StreetJ";
           break;
      case 16:
           playerPlace = "Location ";
           break;
      case 17:
           playerPlace = "Vine StreetK";
           break;
      case 18:
           playerPlace = "Free Parking ";
           break;
      case 19:
           playerPlace = "StrandM";
           break;
      case 20:
           playerPlace = "Chance ";
           break;
      case 21:
           playerPlace = "Fleet StreetN";
           break;
      case 22:
           playerPlace = "Trafalgar SquareO";
           break;
      case 23:
           playerPlace = "Leicester SquareP";
           break;
      case 24:
           playerPlace = "Coventry StreetQ";
           break;
      case 25:
           playerPlace = "Location ";
           break;
      case 26:
           playerPlace = "PicadillyR";
           break;
      case 27:
           playerPlace = "Jail ";
           break;
      case 28:
           playerPlace = "Regent StreetS";
           break;
      case 29:
           playerPlace = "Chance ";
           break;
      case 30:
           playerPlace = "Oxford StreetT";
           break;             
      case 31:
           playerPlace = "Bond StreetU";
           break; 
      case 32:
           playerPlace = "Chance ";
           break;
      case 33:
           playerPlace = "Park LaneV";
           break;
      case 34:
           playerPlace = "Location ";
           break;
      case 35:
           playerPlace = "MayfairW";
           break;
      default:
            playerPlace = "Start ";
            break;
    }
}