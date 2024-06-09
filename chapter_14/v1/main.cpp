#include<iostream>
#include<string>
#include<vector>

using namespace std;

class StockObserver;

class Secretary
{
public:
    Secretary(const string& name): name(name) {}
    string getAction() { return action; }
    void setAction(const string& value) { action = value; }
    void attach(StockObserver& observer);
    void notifyEmployee();

    string name;
private:
    vector<StockObserver *> observers;
    string action;

};

class StockObserver
{
public:
    StockObserver(const string& name, Secretary& secretary): name(name), sub(secretary) {}
    void update() { cout << sub.name << ": " << sub.getAction() << "!" << name << ",请关闭股票行情,赶快工作。" << endl; }
private:
    string name;
    Secretary &sub;
};

void Secretary::attach(StockObserver& observer) { observers.push_back(&observer); }
void Secretary::notifyEmployee() 
{
    for (int i = 0; i < observers.size(); ++i)
        observers[i]->update();
}


int main()
{
    Secretary secretary1(string("童子喆"));

    StockObserver employee1(string("魏关姹"), secretary1);
    StockObserver employee2(string("易管查"), secretary1);

    secretary1.attach(employee1);
    secretary1.attach(employee2);

    secretary1.setAction(string("老板回来了"));
    secretary1.notifyEmployee();
    return 0;
}