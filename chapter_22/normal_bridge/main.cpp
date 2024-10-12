#include <iostream>
#include <memory>

using namespace std;

class Implementor
{
public:
    virtual void operation() = 0;
    virtual ~Implementor() = default;
};

class ConcreteImplementorA: public Implementor
{
public:
    void operation() override { cout << "具体实现A的方法执行" << endl; }
};

class ConcreteImplementorB: public Implementor
{
public:
    void operation() override { cout << "具体实现B的方法执行" << endl; }
};

class Abstraction
{
public:
    void setImplementor(Implementor* ip) 
    { 
        implementor.reset(ip);
    }
    virtual void operation() = 0;
    virtual ~Abstraction() = default;
protected:
    shared_ptr<Implementor> implementor;
};

class RefinedAbstraction: public Abstraction
{
public:
    void operation() override 
    {
        cout << "具体的Abstraction" << endl;
        implementor->operation();
    }
};

int main()
{
    shared_ptr<Abstraction> ab = make_shared<RefinedAbstraction>();
    ab->setImplementor(new ConcreteImplementorA());
    ab->operation();

    ab->setImplementor(new ConcreteImplementorB());
    ab->operation();

    return 0;
}