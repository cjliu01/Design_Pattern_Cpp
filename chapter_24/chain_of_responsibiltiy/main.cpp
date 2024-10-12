#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Handler
{
public:
    void setSuccessor(shared_ptr<Handler> s) { successor = s; }
    virtual string getClassName() const = 0;
    virtual void handleRequest(int request) = 0;
    virtual ~Handler() = default;
protected:
    shared_ptr<Handler> successor;
};

class ConcreteHandler1: public Handler
{
public:
    string getClassName() const override { return string("ConcreteHandler1"); }
    void handleRequest(int request) override
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
    string getClassName() const override { return string("ConcreteHandler2"); }
    void handleRequest(int request) override
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
    string getClassName() const override{ return string("ConcreteHandler3"); }
    void handleRequest(int request) override
    {
        if (request >= 20 && request < 30)
            cout << getClassName() << "处理请求 " << request << endl;
        else if (successor != nullptr)
            successor->handleRequest(request);
    }
};

int main()
{
    shared_ptr<Handler> h1 = make_shared<ConcreteHandler1>();
    shared_ptr<Handler> h2 = make_shared<ConcreteHandler2>();
    shared_ptr<Handler> h3 = make_shared<ConcreteHandler3>();

    h1->setSuccessor(h2);
    h2->setSuccessor(h3);

    vector<int> requests = {2, 5, 14, 22, 18, 3, 27, 20};
    for (int i = 0; i < requests.size(); ++i)
        h1->handleRequest(requests[i]);


    return 0;
}