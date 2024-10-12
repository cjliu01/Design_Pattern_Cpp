#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(const string& name): name(name) {}

    void wearTShirts() { cout << "大T恤"; }
    void wearBigTrouser() { cout << "垮裤"; }
    void wearSneakers() { cout << "球鞋"; }
    void wearSuit() { cout << "西装"; }
    void wearTie() { cout << "领带"; }
    void wearLeatherShoes() { cout << "皮鞋"; }
    void show() { cout << "装扮的" << name << endl; }

private:
    string name;
};


int main()
{
    Person xc("小菜");
    cout << "第一种装扮: ";
    xc.wearTShirts();
    xc.wearBigTrouser();
    xc.wearSneakers();
    xc.show();

    cout << "第二种装扮: ";
    xc.wearSuit();
    xc.wearTie();
    xc.wearLeatherShoes();
    xc.show();

    return 0;
}