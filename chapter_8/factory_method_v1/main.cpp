#include<iostream>
#include<string>

using namespace std;

class Operation
{
public:
    virtual double getResult(double numberA, double numberB) = 0;
};

class Add: public Operation
{
public:
    double getResult(double numberA, double numberB) { return numberA + numberB; }
};

class Sub: public Operation
{
public:
    double getResult(double numberA, double numberB) { return numberA - numberB; }
};

class Mul: public Operation
{
public:
    double getResult(double numberA, double numberB) { return numberA * numberB; }
};

class Div: public Operation
{
public:
    double getResult(double numberA, double numberB) 
    {
        if (numberB == 0)
        {
            cerr << "除数不能为0" << endl;
            throw runtime_error("除数不能为0");
        }
        return numberA / numberB;
    }
};

class Factory
{
public:
    virtual Operation* createOperation() = 0;
};

class AddFactory: public Factory
{
public: 
    Operation* createOperation() { return new Add(); }
};

class SubFactory: public Factory
{
public:
    Operation* createOperation() { return new Sub(); }
};

class MulFactory: public Factory
{
public:
    Operation* createOperation() { return new Mul(); }
};

class DivFactory: public Factory
{
public:
    Operation* createOperation() { return new Div(); }
};

class OperationFactory
{
public:
    static Operation* createOperate(char operate)
    {
        Operation *oper = 0;
        Factory *factory = 0;
        switch(operate)
        {
            case '+': factory = new AddFactory(); break;
            case '-': factory = new SubFactory(); break;
            case '*': factory = new MulFactory(); break;
            case '/': factory = new DivFactory(); break;
        }
        oper = factory->createOperation();
        delete factory;
        return oper;
    }
    
};


int main()
{
    double numberA, numberB;
    char operation;
    cout << "请输入数字A ";
    cin >> numberA;
    cout << "请输入数字B ";
    cin >> numberB;
    cout << "请输入操作符(+, -, *, /):";
    cin >> operation;
    Operation *oper = OperationFactory::createOperate(operation);
    if (oper != 0)
    {
        double result = oper->getResult(numberA, numberB);
        cout << "计算结果=" << result;
        delete oper;
        oper = 0;
    }
    return 0;
}