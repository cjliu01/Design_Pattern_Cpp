#include <iostream>
#include <memory>

using namespace std;

class Context;
class State
{
public:
    State(const string& className=string("")): className(className) {}
    string getClassName() { return className; }
    virtual void Handle(Context& context) = 0;
    virtual ~State() = default;
protected:
    string className;  
};

class ConcreteStateA: public State
{
public:
    ConcreteStateA(const string& className=string("ConcreteStateA")): State(className) {}
    void Handle(Context& context) override;

};

class ConcreteStateB: public State
{
public: 
    ConcreteStateB(const string& className=string("ConcreteStateB")): State(className) {}
    void Handle(Context& context) override;
};

class Context
{
public:
    Context(State* state_=nullptr): state(state_) {}
    shared_ptr<State> getState() { return state; }
    void setState(State* state_) 
    {
        state.reset(state_);
        cout << "µ±Ç°×´Ì¬" << state->getClassName() << endl;
    }
    void request() { state->Handle(*this); }
private:
    shared_ptr<State> state;
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