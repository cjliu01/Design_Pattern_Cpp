#include <iostream>
#include <string>
#include <memory>

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
    virtual ~Finery() = default;
};

class TShirt: public Finery
{
public:
    void show() override { cout << "TShirt "; }
};

class BigTrouser: public Finery
{
public:
    void show() override { cout << "BigTrouser "; }
};

class Sneakers: public Finery
{
public:
    void show() override { cout << "Sneakers "; }
};

class Suit: public Finery
{
public:
    void show() override { cout << "Suit "; }
};

class Tie: public Finery
{
public:
    void show() override { cout << "Tie "; }
};

class LeatherShoes: public Finery
{
public:
    void show() override { cout << "LeatherShoes "; }
};

int main()
{
    Person xc("小菜");

    cout << "第一种装扮: ";
    shared_ptr<Finery> dtx(new TShirt());
    shared_ptr<Finery>  kk(new BigTrouser());
    shared_ptr<Finery> pqx(new Sneakers());

    dtx->show();
    kk->show();
    pqx->show();
    xc.show();

    cout << "\n第二种装扮: ";
    shared_ptr<Finery> xz(new Suit());
    shared_ptr<Finery> ld(new Tie());
    shared_ptr<Finery> px(new LeatherShoes());

    xz->show();
    ld->show();
    px->show();
    xc.show();

    return 0;
}
