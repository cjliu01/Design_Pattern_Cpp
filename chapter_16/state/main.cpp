#include<iostream>

using namespace std;

class Context;
class State
{
public:
    State(const string& className=string("")): className(className) {}
    virtual void Handle(Context& context) = 0;
    string getClassName() { return className; }
protected:
    string className;  
};

class ConcreteStateA: public State
{
public:
    ConcreteStateA(const string& className=string("ConcreteStateA")): State(className) {}
    void Handle(Context& context);

};

class ConcreteStateB: public State
{
public: 
    ConcreteStateB(const string& className=string("ConcreteStateB")): State(className) {}
    void Handle(Context& context);
};

class Context
{
public:
    Context(State* state_=0): state(state_) {}
    State* getState() { return state; }
    void setState(State* state_) 
    {
        //·ÀÖ¹ÄÚ´æÐ¹Â©
        delete state;
        state = nullptr;
        state = state_;
        cout << "µ±Ç°×´Ì¬" << state->getClassName() << endl;
    }
    void request()
    {
        state->Handle(*this);
    }
    ~Context() { delete state; }
private:
    State *state;
};

void ConcreteStateA::Handle(Context& context)
{
    context.setState(new ConcreteStateB);
}

void ConcreteStateB::Handle(Context& context)
{
    context.setState(new ConcreteStateA);
}

int main()
{
    Context c(new ConcreteStateA);

    c.request();
    c.request();
    c.request();
}