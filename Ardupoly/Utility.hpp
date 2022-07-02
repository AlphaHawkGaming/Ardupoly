
class Utility 
{
public:
    static void clearBuffer() {
        while(Serial.available())
            Serial.read();
    }
private:
    Utility();
    ~Utility();
};