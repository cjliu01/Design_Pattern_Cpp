#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;
class Visitor
{
public:
    virtual void visitConcreteElementA(ConcreteElementA& concreteElementA) = 0;
    virtual void visitConcreteElementB(ConcreteElementB& concreteElementB) = 0;
    virtual string getClassName() = 0;
    virtual ~Visitor() = default;
};

class Element 
{
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual string getClassName() = 0;
    virtual ~Element() = default;
};

class ConcreteElementA: public Element
{
public:
    void accept(Visitor& visitor) override { visitor.visitConcreteElementA(*this); }
    string getClassName() override { return string("ConcreteElementA"); }
};

class ConcreteElementB: public Element
{
public:
    void accept(Visitor& visitor) override { visitor.visitConcreteElementB(*this); }
    string getClassName() override { return string("ConcreteElementB"); }
};

class ConcreteVisitor1: public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA& concreteElementA) override { cout << concreteElementA.getClassName() << "被" << getClassName() << "访问" << endl; }
    void visitConcreteElementB(ConcreteElementB& concreteElementB) override { cout << concreteElementB.getClassName() << "被" << getClassName() << "访问" << endl; }
    
    string getClassName() override { return string("ConcreteVisitor1"); }
};

class ConcreteVisitor2: public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA& concreteElementA) override { cout << concreteElementA.getClassName() << "被" << getClassName() << "访问" << endl; }
    void visitConcreteElementB(ConcreteElementB& concreteElementB) override { cout << concreteElementB.getClassName() << "被" << getClassName() << "访问" << endl; }
    
    string getClassName() override { return string("ConcreteVisitor2"); }
};

class ObjectStructure
{
public:
    void attach(shared_ptr<Element> element) { elements.push_back(element); }
    void detach(shared_ptr<Element> element) 
    {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end())
            elements.erase(it);
        else
            cout << "not found" << endl;
    }

    void accept(Visitor& visitor)
    {
        for (int i = 0; i < elements.size(); ++i)
            elements[i]->accept(visitor);
    }

private:
    vector<shared_ptr<Element>> elements;
};

int main()
{
    ObjectStructure o;
    o.attach(make_shared<ConcreteElementA>());
    o.attach(make_shared<ConcreteElementB>());

    ConcreteVisitor1 v1;
    ConcreteVisitor2 v2;
    
    o.accept(v1);
    o.accept(v2);
    return 0;
}