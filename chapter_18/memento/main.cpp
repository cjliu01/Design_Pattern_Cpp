#include<iostream>
#include<string>

using namespace std;

class Memento
{
public:
    Memento(const string& s=string("")) : state(s) {}
    string getState() const { return state; }
    void setState(const string& value) { state = value; }

private:
    string state;
};

class Originator
{
public:
    string getState() { return state; }
    void setState(const string& s)  { this->state = s; }
    void show() { cout << "State" << state << endl;}

    Memento createMemento() { return Memento(state); }
    void recoveryMemento(const Memento& memento) { setState(memento.getState()); }
private:
    string state;
};

class Caretaker
{
public:
    Memento getMemento() { return memento; }
    void setMemento(const Memento& m) { memento = m; }
private:
    Memento memento;
};

int main()
{
    Originator o;
    o.setState(string("On"));
    o.show();

    Caretaker c;
    c.setMemento(o.createMemento());

    o.setState(string("Off"));
    o.show();

    o.recoveryMemento(c.getMemento());
    o.show();
    return 0;
}