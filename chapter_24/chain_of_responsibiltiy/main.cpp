#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Handler
{
public:
    void setSuccessor(Handler* successor) { this->successor = successor; }
    virtual string getClassName() = 0;
    virtual void handleRequest(int request) = 0;
    Handler(): successor(nullptr) {}
protected:
    Handler* successor;
};

class ConcreteHandler1: public Handler
{
public:
    ConcreteHandler1(): Handler() {} 
    string getClassName() { return string("ConcreteHandler1"); }
    void handleRequest(int request)
    {
        if (request >= 0 && request < 10)
            cout << getClassName() << "处理请求 " << request << endl;
        else if (successor != nullptr)
            successor->handleRequest(request);
    }
};

class ConcreteHandler2: public Handler
{
public:
    ConcreteHandler2(): Handler() {} 
    string getClassName() { return string("ConcreteHandler2"); }
    void handleRequest(int request)
    {
        if (request >= 10 && request < 20)
            cout << getClassName() << "处理请求 " << request << endl;
        else if (successor != nullptr)
            successor->handleRequest(request);
    }
};

class ConcreteHandler3: public Handler
{
public:
    string getClassName() { return string("ConcreteHandler3"); }
    void handleRequest(int request)
    {
        if (request >= 20 && request < 30)
            cout << getClassName() << "处理请求 " << request << endl;
        else if (successor != nullptr)
            successor->handleRequest(request);
    }
};

int main()
{
    Handler* h1 = new ConcreteHandler1;
    Handler* h2 = new ConcreteHandler2;
    Handler* h3 = new ConcreteHandler3;

    h1->setSuccessor(h2);
    h2->setSuccessor(h3);

    vector<int> requests = {2, 5, 14, 22, 18, 3, 27, 20};
    for (int i = 0; i < requests.size(); ++i)
        h1->handleRequest(requests[i]);

    delete h1;
    delete h2;
    delete h3;   
    return 0;
}