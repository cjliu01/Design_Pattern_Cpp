#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    string getAction() const { return action; }
    void setAction(const string& action) { this->action = action; }
    virtual void getConclusion() = 0;
    virtual string getClassName() = 0;
    virtual ~Person() = default;
    
protected:
    string name;
    string action;
};

class Man: public Person
{
public:
    void getConclusion() override
    {
        if (action == string("成功"))
            cout << getClassName() << action << "时，背后多半有一个伟大的女人" << endl;
        else if (action == string("失败"))
            cout << getClassName() << action << "时，闷头喝酒，谁也不用劝。" << endl;
        else if (action == string("恋爱"))
            cout << getClassName() << action << "时，凡事不懂也要装懂。" << endl;
    }
    string getClassName() override { return string("男人"); }
};

class Woman: public Person
{
public:
    void getConclusion() override
    {
        if (action == string("成功"))
            cout << getClassName() << action << "时，背后大多有一个不成功的男人。" << endl;
        else if (action == string("失败"))
            cout << getClassName() << action << "时，眼泪汪汪，谁也劝不了。" << endl;
        else if (action == string("恋爱"))
            cout << getClassName() << action << "时，遇事懂也装作不懂。" << endl;
    }
    string getClassName() override { return string("女人"); }
};

int main()
{
    vector<shared_ptr<Person>> persons;
    shared_ptr<Person> man1 = make_shared<Man>();
    man1->setAction(string("成功"));
    persons.push_back(man1);

    shared_ptr<Person> woman1 = make_shared<Woman>();
    woman1->setAction(string("成功"));
    persons.push_back(woman1);

    shared_ptr<Person> man2 = make_shared<Man>();
    man2->setAction(string("失败"));
    persons.push_back(man2);

    shared_ptr<Person> woman2 = make_shared<Woman>();
    woman2->setAction(string("失败"));
    persons.push_back(woman2);

    shared_ptr<Person> man3 = make_shared<Man>();
    man3->setAction(string("恋爱"));
    persons.push_back(man3);

    shared_ptr<Person> woman3 = make_shared<Woman>();
    woman3->setAction(string("恋爱"));
    persons.push_back(woman3);

    for (auto person: persons)
        person->getConclusion();
    return 0;
}