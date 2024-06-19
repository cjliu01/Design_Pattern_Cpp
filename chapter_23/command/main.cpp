#include<iostream>

using namespace std;

class Receiver
{
public:
    void action() { cout << "Ö´ÐÐÇëÇó£¡" << endl; }
};

class Command
{
public:
    Command(const Receiver& receiver): receiver(receiver) {}
    virtual void excuteCommand() = 0;
protected:
    Receiver receiver;
};

class ConcreteCommand: public Command
{
public:
    ConcreteCommand(const Receiver& receiver): Command(receiver) {}
    void excuteCommand() { receiver.action(); }
};

class Invoker
{
public:
    void setCommand(Command* command)  { this->command = command; }
    Invoker(): command(nullptr) {}
    ~Invoker() { command = nullptr; }
    void excuteCommand() { command->excuteCommand(); }
private:
    Command* command;
};

int main()
{
    Receiver receiver;
    ConcreteCommand command(receiver);
    Invoker invoker;
    
    invoker.setCommand(&command);
    invoker.excuteCommand();

    return 0;
}