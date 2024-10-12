#include <iostream>
#include <memory>

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
    Command(const Barbecuer& receiver): receiver(receiver) {}
    virtual void excuteCommand() = 0;
    virtual ~Command() = default;
protected:
    Barbecuer receiver;
};

class BakeMuttonCommand: public Command
{
public:
    BakeMuttonCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() override { receiver.bakeMutton(); }
};

class BakeChickenWingCommand: public Command
{
public:
    BakeChickenWingCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() override { receiver.bakeChickenWing();}
};

class Waiter
{
public:
    Waiter(): command(nullptr) {}
    void setOrder(Command* c) { command = c; }
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