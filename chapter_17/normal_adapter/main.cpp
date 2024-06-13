#include<iostream>

using namespace std;

class Target
{
public:
    virtual void request() { cout << "普通请求!" << endl; }
};

class Adaptee
{
public:
    void specificRequest() { cout << "特殊请求!" << endl; }
};

class Adapter: public Target
{
public:
    virtual void request() { adaptee.specificRequest(); }
private:
    Adaptee adaptee;
};

int main()
{
    Target* target = new Adapter;
    target->request();
    delete target;

    return 0;
}