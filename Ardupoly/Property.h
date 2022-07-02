
class Property
{
public:
    Property(Ardupoly* ardupolyCore);
    ~Property(); 

    void propertyBuy();
    uint8_t propertyOwner();
private:
    uint8_t index;
    uint8_t propertyState;
    uint8_t exponent;

    Ardupoly* ardupolyCore;
};