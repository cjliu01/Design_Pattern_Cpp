#include<iostream>

using namespace std;

class Barbecuer
{
public:
    void bakeMutton() { cout << "¿¾ÑòÈâ´®£¡" << endl; }
    void bakeChickenWing() { cout << "¿¾¼¦³á£¡" << endl; }
};

class Command
{
public:
    virtual void excuteCommand() = 0;
    Command(const Barbecuer& receiver): receiver(receiver) {}
protected:
    Barbecuer receiver;
};

class BakeMuttonCommand: public Command
{
public:
    BakeMuttonCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() { receiver.bakeMutton(); }
};

class BakeChickenWingCommand: public Command
{
public:
    BakeChickenWingCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() { receiver.bakeChickenWing();}
};

class Waiter
{
public:
    Waiter(): command(nullptr) {}
    void setOrder(Command* command) { this->command = command; }
    void notifyCommand() { command->excuteCommand(); }
private:
    Command* command;
};

int main()
{
    Barbecuer boy;
    BakeChickenWingCommand bakeChickenWingCommand1(boy);
    BakeMuttonCommand bakeMuttonCommand1(boy);
    Waiter girl;

    girl.setOrder(&bakeMuttonCommand1);
    girl.notifyCommand();
    girl.setOrder(&bakeMuttonCommand1);
    girl.notifyCommand();
    girl.setOrder(&bakeChickenWingCommand1);
    girl.notifyCommand();

    return 0;
}