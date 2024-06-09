#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Observer;

class Subject
{
public:
    string name;
    Subject(const string& name): name(name) {}
    void attach(Observer& observer);
    void detach(Observer& observer);
    void notifyEmployee();
    string getAction() { return action; }
    void setAction(const string& value) { this->action = value; }
private:
    vector<Observer *> observers;
    string action;
};

class Boss: public Subject
{
public:
    Boss(const string& name): Subject(name) {}
};


class Secretary: public Subject
{
public:
    Secretary(const string& name): Subject(name) {}
};

class Observer
{
public:
    Observer(const string& name, Subject& sub): name(name), sub(sub) {}
    virtual void update() = 0;
    bool operator==(const Observer& rhs) { return (this->name == rhs.name) && (this->sub.name == rhs.sub.name); }
    bool operator!=(const Observer& rhs) { return !(*this == rhs); }
protected:
    string name;
    Subject &sub;
};

void Subject::attach(Observer& observer)
{
    observers.push_back(&observer);
}

void Subject::detach(Observer& observer)
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

void Subject::notifyEmployee()
{
    for (int i = 0; i < observers.size(); ++i)
    {
        observers[i]->update();
    }
}

class StockObserver: public Observer
{
public:
    StockObserver(const string& name, Subject& sub): Observer(name, sub) {}
    void update() { cout << sub.name << ":" << sub.getAction() << "! " << name << ",请关闭股票行情,赶紧工作。" << endl; }
};

class NBAObserver: public Observer
{
public:
    NBAObserver(const string& name, Subject& sub): Observer(name, sub) {}
    void update() { cout << sub.name << ":" << sub.getAction() << "! " << name << ",请关闭NBA直播,赶紧工作。" << endl; }
};

int main()
{
    Boss boss(string("胡汉三"));

    StockObserver employee1(string("魏关姹"), boss);
    StockObserver employee2(string("易管查"), boss);
    NBAObserver employee3(string("兰秋幂"), boss);

    boss.attach(employee1);
    boss.attach(employee2);
    boss.attach(employee3);

    boss.detach(employee2);

    boss.setAction(string("我胡汉三回来了"));
    boss.notifyEmployee();

    return 0;
}
