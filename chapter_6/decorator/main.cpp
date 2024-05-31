#include<iostream>
#include<string>

using namespace std;

class Character
{
public:
    virtual void show() = 0; 
};

class Person: public Character
{
public:
    Person(const string& name): name(name) {}
    void show() { cout << "装扮的" + name; }

private: 
    string name;
};

class Finery: public Character
{
public:
    Finery(): component(0) {}
    void decorate(Character* component) { this->component = component; }
    void show()
    {
        if(this->component != 0)
            this->component->show();
    }
protected:
    Character* component;
};

class Tshirts: public Finery
{
public:
    void show() 
    { 
        cout << "Tshirts"; 
        Finery::show();
    }
};

class BigTrouser: public Finery
{
public:
    void show()
    {
        cout << "BigTrouser";
        Finery::show();
    }
};

class Sneakers: public Finery
{
public:
    void show()
    {
        cout << "Sneakers";
        Finery::show();
    }
};

class LeatherShoes: public Finery
{
public:
    void show()
    {        
        cout << "LeatherShoes";
        Finery::show();
    }
};

class Tie: public Finery
{
public:
    void show() 
    {
        cout << "Tie";
        Finery::show();
    }
};

class Suit: public Finery
{
public:
    void show()
    {
        cout << "Suit";
        Finery::show();
    }
};

class Strawhat: public Finery
{
public:
    void show()
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