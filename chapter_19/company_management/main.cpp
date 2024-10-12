#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Company
{
public:
    Company(const string& name): name(name) {}
    virtual void add(shared_ptr<Company> c) = 0;
    virtual void remove(shared_ptr<Company> c) = 0;
    virtual void display(int depth) = 0;
    virtual void lineOfDuty() = 0; 
    virtual ~Company() = default;
protected:
    string name;
};

class ConcreteCompany: public Company
{
public:
    ConcreteCompany(const string& name): Company(name) {} 
    void add(shared_ptr<Company> c) override { childen.push_back(c); }
    void remove(shared_ptr<Company> c) override
    {
        auto it = find(childen.begin(), childen.end(), c);
        if (it != childen.end())
            childen.erase(it);
        else
            cout << "not found" << endl;   
    } 

    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->display(depth + 2);
    } 

    void lineOfDuty() override
    {
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->lineOfDuty();
    }
private:
    vector<shared_ptr<Company>> childen;
};

class HRDepartment: public Company
{
public:
    HRDepartment(const string& name): Company(name) {}
    void add(shared_ptr<Company> c) override { ; }
    void remove(shared_ptr<Company> c) override { ; }
    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty() override
    {
        cout << name << " 员工招聘培训管理" << endl;
    }
};


class FinanceDepartment: public Company
{
public:
    FinanceDepartment(const string& name): Company(name) {}
    void add(shared_ptr<Company> c) override { ; }
    void remove(shared_ptr<Company> c) override { ; }
    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty() override
    {
        cout << name << " 公司财务收支管理" << endl;
    }
};


int main()
{
    ConcreteCompany root("北京总公司");
    root.add(make_shared<HRDepartment>("总公司人力资源部"));
    root.add(make_shared<FinanceDepartment>("总公司财务部"));

    shared_ptr<Company> comp = make_shared<ConcreteCompany>("上海华东分公司");
    comp->add(make_shared<HRDepartment>("华东分公司人力资源部"));
    comp->add(make_shared<FinanceDepartment>("华东分公司财务部"));
    root.add(comp);

    shared_ptr<Company> comp2 = make_shared<ConcreteCompany>("南京办事处");
    comp2->add(make_shared<HRDepartment>("南京办事处人力资源部"));
    comp2->add(make_shared<FinanceDepartment>("南京办事处资源部"));
    comp->add(comp2);

    shared_ptr<Company> comp3 = make_shared<ConcreteCompany>("杭州办事处");
    comp3->add(make_shared<HRDepartment>("杭州办事处人力资源部"));
    comp3->add(make_shared<FinanceDepartment>("杭州办事处财务部"));
    comp->add(comp3);

    cout << "结构图: " << endl;
    root.display(1);
    cout << "职责: " << endl;
    root.lineOfDuty();

    return 0;
}