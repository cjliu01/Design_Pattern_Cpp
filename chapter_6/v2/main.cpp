#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
    Person(const string& name): name(name) {}

    void show() { cout << "装扮的" << name; }
private:
    string name;
};


class Finery
{
public:
    virtual void show() = 0;
};

class TShirt: public Finery
{
public:
    void show() { cout << "TShirt "; }
};

class BigTrouser: public Finery
{
public:
    void show() { cout << "BigTrouser "; }
};

class Sneakers: public Finery
{
public:
    void show() { cout << "Sneakers "; }
};

class Suit: public Finery
{
public:
    void show() { cout << "Suit "; }
};

class Tie: public Finery
{
public:
    void show() { cout << "Tie "; }
};

class LeatherShoes: public Finery
{
public:
    void show() { cout << "LeatherShoes "; }
};

int main()
{
    Person xc("小菜");

    cout << "第一种装扮: ";
    Finery *dtx = new TShirt();
    Finery *kk = new BigTrouser();
    Finery *pqx = new Sneakers();

    dtx->show();
    kk->show();
    pqx->show();
    xc.show();

    delete dtx;
    delete kk;
    delete pqx;

    cout << "\n第二种装扮: ";
    Finery *xz = new Suit();
    Finery *ld = new Tie();
    Finery *px = new LeatherShoes();

    xz->show();
    ld->show();
    px->show();
    xc.show();

    delete xz;
    delete ld;
    delete px;

    return 0;
}
