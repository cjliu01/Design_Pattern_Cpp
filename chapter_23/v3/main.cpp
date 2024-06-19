#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class Barbecuer
{
public:
    void bakeMutton() { cout << "烤羊肉串！" << endl; }
    void bakeChickenWing() { cout << "烤鸡翅！" << endl; }
};

class Command
{
public:
    virtual void excuteCommand() = 0;
    virtual string getCommandName() = 0;
    Command(const Barbecuer& receiver): receiver(receiver) {}
protected:
    Barbecuer receiver;
};

class BakeMuttonCommand: public Command
{
public:
    BakeMuttonCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() { receiver.bakeMutton(); }
    string getCommandName() { return string("BakeMutton"); }
};

class BakeChickenWingCommand: public Command
{
public:
    BakeChickenWingCommand(const Barbecuer& receiver): Command(receiver) {}
    void excuteCommand() { receiver.bakeChickenWing();}
    string getCommandName() { return string("BakeChickenWing"); }
};

class Waiter
{
public:
    Waiter() {}
    void setOrder(Command* command) 
    { 
        if (command->getCommandName() == string("BakeChickenWing"))
            cout << "服务员: 鸡翅没有了, 请点别的烧烤." << endl;
        else
        {
            orders.push_back(command);
            cout << "增加订单: " << command->getCommandName() << " 时间: " << getNowTime() << endl; 
        }
    }
    void cancelOrder(Command* command)
    {
        for (int i = 0; i < orders.size(); ++i)
        {
            if (orders[i] == command)
            {
                orders.erase(orders.begin() + i);
                cout << "取消订单: " << command->getCommandName() << " 时间: " << getNowTime() << endl; 
                break;
            }
        }
    }
    void notifyCommand() 
    {
        for (int i = 0; i < orders.size(); ++i)
            orders[i]->excuteCommand();
    }
private:
    vector<Command*> orders;
    string getNowTime() 
    {
        time_t now = std::time(nullptr);    
        tm* local_time = std::localtime(&now);   
        ostringstream oss;  
        oss << put_time(local_time, "%Y-%m-%d %H:%M:%S"); // 格式化为"年-月-日 时:分:秒"  
        return oss.str(); 
    }
};

int main()
{
    Barbecuer boy;
    BakeChickenWingCommand bakeChickenWingCommand1(boy);
    BakeMuttonCommand bakeMuttonCommand1(boy);
    Waiter girl;

    cout << "开门营业, 顾客点菜" << endl;
    girl.setOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeMuttonCommand1); 
    girl.setOrder(&bakeMuttonCommand1);

    girl.cancelOrder(&bakeMuttonCommand1);
    girl.setOrder(&bakeChickenWingCommand1);

    cout << "点菜完毕, 通知厨房烧菜" << endl;
    girl.notifyCommand();
    return 0;
}