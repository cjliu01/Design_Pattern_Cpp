#include<iostream>
#include<string>

using namespace std;

class Character
{
public:
    virtual void show() = 0; 
    virtual ~Character() = default;
};

class Person: public Character
{
public:
    Person(const string& name): name(name) {}
    void show() override { cout << "装扮的" + name; }

private: 
    string name;
};

class Finery: public Character
{
public:
    Finery(): component(nullptr) {}
    void decorate(Character* component) { this->component = component; }
    void show() override
    {
        if(this->component != nullptr)
            this->component->show();
    }
protected:
    Character* component;
};

class Tshirts: public Finery
{
public:
    void show() override 
    { 
        cout << "Tshirts"; 
        Finery::show();
    }
};

class BigTrouser: public Finery
{
public:
    void show() override
    {
        cout << "BigTrouser";
        Finery::show();
    }
};

class Sneakers: public Finery
{
public:
    void show() override
    {
        cout << "Sneakers";
        Finery::show();
    }
};

class LeatherShoes: public Finery
{
public:
    void show() override
    {        
        cout << "LeatherShoes";
        Finery::show();
    }
};

class Tie: public Finery
{
public:
    void show() override
    {
        cout << "Tie";
        Finery::show();
    }
};

class Suit: public Finery
{
public:
    void show() override
    {
        cout << "Suit";
        Finery::show();
    }
};

class Strawhat: public Finery
{
public:
    void show() override
    {
        cout << "Strawhat";
        Finery::show();
    }
};

int main()
{
    Person xc("小菜");

    cout << "第一种装扮: ";
    Sneakers sneaker;
    sneaker.decorate(&xc);
    sneaker.show();
    cout << "\n";
    
    BigTrouser bigtrouser;
    bigtrouser.decorate(&sneaker);
    bigtrouser.show();

    cout << "\n";

    Tshirts tshirts;
    tshirts.decorate(&bigtrouser);
    tshirts.show();

    cout << "\n第二种装扮";
    LeatherShoes leatherShoes;
    leatherShoes.decorate(&xc);
    leatherShoes.show();

    cout << "\n";
    Tie ld;
    ld.decorate(&leatherShoes);
    ld.show();

    cout << "\n";

    Suit xz;
    xz.decorate(&ld);
    xz.show();

    cout << "\n第三种装扮\n";
    Strawhat strawhat;
    strawhat.decorate(&xz);
    strawhat.show();
}