#include <iostream>

using namespace std;

class PersonBuilder
{
public:
    void build()
    {
        cout << "建造" << person() << "人的头" << endl;
        cout << "建造" << person() << "人的身体" << endl;
        cout << "建造" << person() << "人的左手" << endl;
        cout << "建造" << person() << "人的右手" << endl;
        cout << "建造" << person() << "人的左脚" << endl;
        cout << "建造" << person() << "人的右脚" << endl;
    }

    virtual ~PersonBuilder() = default;
protected:
    virtual string person() = 0;
};
class PersonThinBuilder: public PersonBuilder
{
protected: 
    string person() override { return string("瘦"); }
};

class PersonFatBuilder: public PersonBuilder
{
protected: 
    string person() override { return string("胖"); }
};

int main()
{
    PersonFatBuilder gFat;
    gFat.build();

    PersonThinBuilder gThin;
    gThin.build();
    return 0;
}