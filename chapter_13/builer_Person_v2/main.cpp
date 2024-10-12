#include <iostream>

using namespace std;

class PersonBuilder
{
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildArmLeft() = 0;
    virtual void buildArmRight() = 0;
    virtual void buildLegLeft() = 0;
    virtual void buildLegRight() = 0;
    virtual ~PersonBuilder() = default;
};

class PersonThinBuilder: public PersonBuilder
{
public:
    void buildHead() override { cout << "建造瘦人的头" << endl; }
    void buildBody() override { cout << "建造瘦人的身体" << endl; }
    void buildArmLeft() override { cout << "建造瘦人的左手" << endl; }
    void buildArmRight() override { cout << "建造瘦人的右手" << endl; }
    void buildLegLeft() override { cout << "建造瘦人的左脚" << endl; }
    void buildLegRight() override { cout << "建造瘦人的右脚" << endl; }
};

class PersonFatBuilder: public PersonBuilder
{
public:
    void buildHead() override { cout << "建造胖人的头" << endl; }
    void buildBody() override { cout << "建造胖人的身体" << endl; }
    void buildArmLeft() override { cout << "建造胖人的左手" << endl; }
    void buildArmRight() override { cout << "建造胖人的右手" << endl; }
    void buildLegLeft() override { cout << "建造胖人的左脚" << endl; }
    void buildLegRight() override { cout << "建造胖人的右脚" << endl; }
};

class PersonDirector
{
public:
    PersonDirector(PersonBuilder& pb): pb(pb) {} 
    void createPerson()
    {
        pb.buildHead();
        pb.buildBody();
        pb.buildArmLeft();
        pb.buildArmRight();
        pb.buildLegLeft();
        pb.buildLegRight();
    }
private:
    PersonBuilder& pb;
};

int main()
{
    PersonThinBuilder gThin;
    PersonFatBuilder gFat;
    
    PersonDirector pdThin(gThin);
    pdThin.createPerson();

    PersonDirector pdFat(gFat);
    pdFat.createPerson();

    return 0;
}
