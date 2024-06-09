#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Observer;

class Secretary
{
public:
    Secretary(const string& name): name(name) {}
    void attach(Observer &observer);
    void detach(Observer &observer);
    void notifyEmployee();
    string getAction() { return action; } 
    void setAction(const string &value) { action = value; }
    string name;
private:
    vector<Observer *> observers;
    string action;
};

class Observer
{
public:
    Observer(const string& nmae, Secretary& secretary): name(nmae), sub(secretary) {}
    virtual void update() = 0;
    bool operator==(const Observer& rhs) { return (this->name == rhs.name) && (this->sub.name == rhs.sub.name); }
    bool operator!=(const Observer& rhs) { return !(*this == rhs); }
protected:
    string name;
    Secretary &sub;
};

class StockObserver: public Observer
{
public:
    StockObserver(const string& name, Secretary& sub): Observer(name, sub) {}
    void update() { cout << sub.name << ":" << sub.getAction() << "! " << name << ",请关闭股票行情,赶紧工作。" << endl; }
};

class NBAObserver: public Observer
{
public:
    NBAObserver(const string& name, Secretary& sub): Observer(name, sub) {}
    void update() { cout << sub.name << ":" << sub.getAction() << "! " << name << ",请关闭NBA直播,赶紧工作。" << endl; }
};

void Secretary::attach(Observer &observer)
{
    observers.push_back(&observer);
}

void Secretary::detach(Observer &observer)
{
    for (auto iter = observers.begin(); iter != observers.end(); ++iter)
    {
        if (*(*iter) == observer)
        {
            observers.erase(iter);
            break;
        }
    }
}

void Secretary::notifyEmployee()
{
    for (int i = 0; i < observers.size(); ++i)
        observers[i]->update();
}

int main()
{
    Secretary secretary1(string("童子喆"));

    StockObserver employee1(string("魏关姹"), secretary1);
    NBAObserver employee2(string("易管查"), secretary1);

    secretary1.attach(employee1);
    secretary1.attach(employee2);

    secretary1.setAction(string("老板回来了"));
    secretary1.notifyEmployee();
    return 0;
}