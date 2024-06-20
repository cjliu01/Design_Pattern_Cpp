#include<iostream>
#include<string>
using namespace std;

class Request
{
public:
    string getRequestType() { return requestType; }
    void setRequestType(const string& requestType) { this->requestType = requestType; }
    string getRequestContent() { return requestContent; }
    void setRequestContent(const string& requestContent) { this->requestContent = requestContent; }
    int getNumber() { return number; }
    void setNumber(int number) { this->number = number; }

private:
    string requestType;
    string requestContent;
    int number;
};

class Manager
{
public:
    Manager(const string& name): name(name) {}
    void getResult(const string& mangerLevel, Request& request)
    {
        if (mangerLevel == string("经理"))
        {
            if (request.getRequestType() == string("请假") && request.getNumber() <= 2)
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "天, 被批准" << endl;
            else
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "天, 我无权处理" << endl; 
        }     
        else if (mangerLevel == string("总监"))
        {
            if (request.getRequestType() == string("请假") && request.getNumber() <= 5)
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "天, 被批准" << endl;
            else
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "天, 我无权处理" << endl; 
        }
        else if (mangerLevel == string("总经理"))
        {
            if (request.getRequestType() == string("请假"))
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "天, 被批准" << endl;
            else if (request.getRequestType() == string("加薪") && request.getNumber() <= 5000)
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "元, 被批准" << endl; 
            else if (request.getRequestType() == string("加薪") && request.getNumber() > 5000)
                cout << name << ":" << request.getRequestContent() << " 数量:" << request.getNumber() << "元, 再说吧" << endl; 
        }
    }
protected:
    string name;
};

int main()
{
    Manager manager(string("金利"));
    Manager director(string("宗剑"));
    Manager generalManager(string("钟精励"));

    Request request;
    request.setRequestType(string("加薪"));
    request.setRequestContent(string("小菜请求加薪"));
    request.setNumber(10000);

    manager.getResult(string("经理"), request);
    director.getResult(string("总监"), request);
    generalManager.getResult(string("总经理"), request);

    Request request2;
    request2.setRequestType(string("请假"));
    request2.setRequestContent(string("小菜请假"));
    request2.setNumber(3);

    manager.getResult(string("经理"), request2);
    director.getResult(string("总监"), request2);
    generalManager.getResult(string("总经理"), request2);
    return 0;
}