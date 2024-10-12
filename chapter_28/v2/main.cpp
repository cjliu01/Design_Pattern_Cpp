#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Action;
class Person
{
public:
    virtual void accept(Action* visitor) = 0;
    virtual string getClassName() = 0;
    virtual ~Person() = default;
};

class Man: public Person
{
public:
    void accept(Action* visitor) override;
    string getClassName() override { return string("Man"); }
};

class Woman: public Person
{
public:
    void accept(Action* visitor) override;
    string getClassName() override { return string("Woman");}
};

class Action
{
public:
    virtual void getManConclusion(Man &man) = 0;
    virtual void getWomanConclusion(Woman &woman) = 0;
    virtual string getClassName() = 0;
    virtual ~Action() = default;
};

void Man::accept(Action* visitor) 
{
    visitor->getManConclusion(*this);
}

void Woman::accept(Action* visitor) 
{
    visitor->getWomanConclusion(*this);
}

class Success: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "时，背后多半有一个伟大的女人。" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "时，背后大多有一个不成功的男人。" << endl; }
    string getClassName() override { return string("成功"); }
};

class Failing: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "时，闷头喝酒，谁也不用劝。" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "时，眼泪汪汪，谁也劝不了。" << endl; }
    string getClassName() override { return string("失败"); }
};

class Amativeness: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "时，凡事不懂也要装懂。" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "时，遇事懂也装作不懂。" << endl; }
    string getClassName() override { return string("恋爱"); }
};

class Marriage: public Action
{
public:
    void getManConclusion(Man &man) override { cout << man.getClassName() << " " << getClassName() << "时，感慨道：恋爱游戏终结时，'有妻徒刑'遥无期。" << endl; }
    void getWomanConclusion(Woman &woman) override { cout << woman.getClassName() << " " << getClassName() << "时，欣慰曰：爱情长跑路漫漫，婚姻保险保平安。" << endl; }
    string getClassName() override { return string("结婚"); }
};

class ObjectStructure
{
public:
    void attach(shared_ptr<Person> element) { elements.push_back(element); }
    void detach(shared_ptr<Person> element) 
    {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end())
            elements.erase(it);
        else
            cout << "not found" << endl;
    }

    void display(Action *vistor)
    {
        for (int i = 0; i < elements.size(); ++i)
            elements[i]->accept(vistor);
    }

private:
    vector<shared_ptr<Person>> elements;

};

int main()
{
    ObjectStructure o;
    o.attach(make_shared<Man>());
    o.attach(make_shared<Woman>());

    Success v1;
    o.display(&v1);

    Failing v2;
    o.display(&v2);

    Amativeness v3;
    o.display(&v3);

    Marriage v4;
    o.display(&v4);
    return 0;
}