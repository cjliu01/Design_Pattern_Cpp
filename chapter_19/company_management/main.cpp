#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Company
{
public:
    Company(const string& name): name(name) {}
    virtual void add(Company* c) = 0;
    virtual void remove(Company* c) = 0;
    virtual void display(int depth) = 0;

    virtual void lineOfDuty() = 0; 
protected:
    string name;
};

class ConcreteCompany: public Company
{
public:
    ConcreteCompany(const string& name): Company(name) {} 
    void add(Company *c) { childen.push_back(c); }
    void remove(Company *c) 
    {
        for (vector<Company *>::iterator it = childen.begin(); it != childen.end(); ++it)
        {
            if (*it == c)
            {
                delete c;    
                childen.erase(it);
            }
        }
    } 
    void display(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->display(depth + 2);
    } 
    void lineOfDuty() 
    {
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->lineOfDuty();
    }
    ~ConcreteCompany() 
    {
        for (int i = 0; i < childen.size(); ++i)
            delete childen[i];
    }

private:
    vector<Company *> childen;
};

class HRDepartment: public Company
{
public:
    HRDepartment(const string& name): Company(name) {}
    void add(Company *c) { ; }
    void remove(Company *c) { ; }
    void display(int depth) 
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty()
    {
        cout << name << " 员工招聘培训管理" << endl;
    }
};


class FinanceDepartment: public Company
{
public:
    FinanceDepartment(const string& name): Company(name) {}
    void add(Company *c) { ; }
    void remove(Company * c) { ; }
    void display(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
    }
    void lineOfDuty()
    {
        cout << name << " 公司财务收支管理" << endl;
    }
};


int main()
{
    ConcreteCompany root(string("北京总公司"));
    root.add(new HRDepartment(string("总公司人力资源部")));
    root.add(new FinanceDepartment(string("总公司财务部")));

    ConcreteCompany *comp = new ConcreteCompany(string("上海华东分公司"));
    comp->add(new HRDepartment(string("华东分公司人力资源部")));
    comp->add(new FinanceDepartment(string("华东分公司财务部")));
    root.add(comp);

    ConcreteCompany *comp2 = new ConcreteCompany(string("南京办事处"));
    comp2->add(new HRDepartment(string("南京办事处人力资源部")));
    comp2->add(new FinanceDepartment(string("南京办事处资源部")));
    comp->add(comp2);

    ConcreteCompany *comp3 = new ConcreteCompany(string("杭州办事处"));
    comp3->add(new HRDepartment(string("杭州办事处人力资源部")));
    comp3->add(new FinanceDepartment(string("杭州办事处财务部")));
    comp->add(comp3);

    cout << "结构图: " << endl;
    root.display(1);
    cout << "职责: " << endl;
    root.lineOfDuty();

    return 0;
}