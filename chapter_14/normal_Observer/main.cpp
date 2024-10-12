#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Observer;

class Subject
{
public:
    void detach(const Observer& observer);
    void attach(Observer& observer);
    void notifyObserver();
    void SetSubjectState(const string& state) { subjectState = state; }
    string GetSubjectState() { return subjectState; }
    virtual ~Subject() = default;
protected:
    string subjectState;
private:
    vector<Observer *> observers;
};

class Observer
{
public:
    Observer(const string& name, Subject& subject) : name(name), subject(subject) {}
    virtual void update() = 0;
    bool operator==(const Observer& rhs) { return this->name == rhs.name;}
    bool operator!=(const Observer& rhs) { return !(*this == rhs); } 
    virtual ~Observer() = default;
protected:
    string name;
    Subject &subject;
};

void Subject::detach(const Observer& observer)
{
    auto it = find(observers.begin(), observers.end(), &observer);
    if (it != observers.end())
        observers.erase(it);
    else
        cout << "未找到该观察者" << endl;
}   

void Subject::attach(Observer& observer)
{
    observers.push_back(&observer);
}

void Subject::notifyObserver()
{
    for (int i = 0; i < observers.size(); ++i)
    {
        observers[i]->update();
    }
}
class ConcreteObserver: public Observer
{
public:
    ConcreteObserver(const string& name, Subject& subject): Observer(name, subject) {}
    void update() override { cout << "观察者" << name << "的新状态是" << subject.GetSubjectState() << endl; }
};

int main()
{
    Subject subject;
    ConcreteObserver observer1(string("NameX"), subject);
    ConcreteObserver observer2(string("NameY"), subject);
    ConcreteObserver observer3(string("NameZ"), subject);
    subject.attach(observer1);
    subject.attach(observer2);
    subject.attach(observer3);
    subject.SetSubjectState(string("CBD"));

    subject.notifyObserver();

    return 0;
}