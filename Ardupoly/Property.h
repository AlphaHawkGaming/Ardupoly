
class Property
{
public:
    Property(Ardupoly* ardupolyCore);
    ~Property(); 
private:
    void propertyAuction(); 
    void propertyBuy(Ardupoly::player* buyer);
    uint8_t propertyOwner();
    short int propertyValue();

    uint8_t index;
    uint8_t propertyState;
    uint8_t exponent;

    Ardupoly* ardupolyCore;
};
