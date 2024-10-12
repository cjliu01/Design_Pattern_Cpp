#include <iostream>

using namespace std;

class Barbecuer
{
public:
    void bakeMutton() { cout << "¿¾ÑòÈâ´®£¡" << endl; }
    void bakeChickenWing() { cout << "¿¾¼¦³á£¡" << endl; }
};

int main()
{
    Barbecuer boy;

    boy.bakeMutton();
    boy.bakeMutton();
    boy.bakeMutton();
    boy.bakeChickenWing();
    boy.bakeMutton();
    boy.bakeMutton();
    boy.bakeChickenWing();
    return 0;
}