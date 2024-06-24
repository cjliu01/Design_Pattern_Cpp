#include<iostream>
#include<string>
#include<vector>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;
class Visitor
{
public:
    virtual void visitConcreteElementA(ConcreteElementA& concreteElementA) = 0;
    virtual void visitConcreteElementB(ConcreteElementB& concreteElementB) = 0;
    virtual string getClassName() = 0;
};

class Element 
{
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual string getClassName() = 0;
};

class ConcreteElementA: public Element
{
public:
    void accept(Visitor& visitor) { visitor.visitConcreteElementA(*this); }
    string getClassName() { return string("ConcreteElementA"); }
};

class ConcreteElementB: public Element
{
public:
    void accept(Visitor& visitor) { visitor.visitConcreteElementB(*this); }
    string getClassName() { return string("ConcreteElementB"); }
};

class ConcreteVisitor1: public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA& concreteElementA) { cout << concreteElementA.getClassName() << "被" << getClassName() << "访问" << endl; }
    void visitConcreteElementB(ConcreteElementB& concreteElementB) { cout << concreteElementB.getClassName() << "被" << getClassName() << "访问" << endl; }
    
    string getClassName() { return string("ConcreteVisitor1"); }
};

class ConcreteVisitor2: public Visitor
{
public:
    void visitConcreteElementA(ConcreteElementA& concreteElementA) { cout << concreteElementA.getClassName() << "被" << getClassName() << "访问" << endl; }
    void visitConcreteElementB(ConcreteElementB& concreteElementB) { cout << concreteElementB.getClassName() << "被" << getClassName() << "访问" << endl; }
    
    string getClassName() { return string("ConcreteVisitor2"); }
};

class ObjectStructure
{
public:
    void attach(Element* element) { elements.push_back(element); }
    void detach(Element *element) 
    {
        for (int i = 0; i < elements.size(); ++i)
        {
            if (elements[i] == element)
            {
                delete elements[i];
                elements.erase(i + elements.begin());
                break;
            }
        }
    }

    void accept(Visitor& visitor)
    {
        for (int i = 0; i < elements.size(); ++i)
            elements[i]->accept(visitor);
    }

     ~ObjectStructure()
    {
        for (int i = 0; i < elements.size(); ++i)
            delete elements[i];
    }

private:
    vector<Element *> elements;
};

int main()
{
    ObjectStructure o;
    o.attach(new ConcreteElementA);
    o.attach(new ConcreteElementB);

    ConcreteVisitor1 v1;
    ConcreteVisitor2 v2;
    
    o.accept(v1);
    o.accept(v2);
    return 0;
}