#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Colleague;
class Mediator
{
public:
    virtual void send(const string& message, Colleague& colleague) = 0;
    virtual ~Mediator() = default;
};

class Colleague
{
public:
    Colleague(Mediator* mediator=nullptr): mediator(mediator) {}
    virtual ~Colleague() = default;
protected:
    Mediator* mediator;
};

class ConcreteColleague1: public Colleague
{
public:
    ConcreteColleague1(Mediator* mediator): Colleague(mediator) {}
    void send(const string& message) { mediator->send(message, *this); }
    void notify(const string& message) { cout << "同事1得到信息: " << message << endl; }

};

class ConcreteColleague2: public Colleague
{
public:
    ConcreteColleague2(Mediator* mediator): Colleague(mediator) {}
    void send(const string& message) { mediator->send(message, *this); }
    void notify(const string& message) { cout << "同事2得到信息: " << message << endl; }

};

class ConcreteMediator: public Mediator
{
public:
    ConcreteMediator(): colleague1(nullptr), colleague2(nullptr) {} 
    void setColleague1(ConcreteColleague1& value) { colleague1 = value; }
    void setColleague2(ConcreteColleague2& value) { colleague2 = value; }
    void send(const string& message, Colleague& colleague) override
    {
        if (typeid(colleague) == typeid(ConcreteColleague1))
            colleague2.notify(message);
        else 
            colleague1.notify(message);
    }
protected:
    ConcreteColleague1 colleague1;
    ConcreteColleague2 colleague2;
};

int main()
{
    ConcreteMediator mediator;
    ConcreteColleague1 c1(&mediator);
    ConcreteColleague2 c2(&mediator);
    
    mediator.setColleague1(c1);
    mediator.setColleague2(c2);

    c1.send(string("吃过饭了嘛?"));
    c2.send(string("没有呢,你打算请客?"));
    c1.send(string("走!"));

    return 0;
}