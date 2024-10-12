#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Prototype
{
public:
    virtual shared_ptr<Prototype> clone() = 0;
    virtual ~Prototype() = default;
};

class WorkExperience
{
public:
    string getTimeArea() { return timeArea; }
    string getCompany() { return company; }
    void setTimeArea(const string& value) { this->timeArea = value; }
    void setCompany(const string& value) { this->company = value; }

private:
    string timeArea;
    string company;
};

class Resume: public Prototype
{
public:
    Resume(const string& name): name(name) {} 
    void setPersonalInfo(const string& sex, const string& age)
    {
        this->sex = sex;
        this->age = age;
    }
    void setWorkExperience(const string& timeArea, const string& company)
    {
        work.setTimeArea(timeArea);
        work.setCompany(company);
    }
    void display()
    {
        cout << name << " " << sex << " " << age << endl;
        cout << "工作经历" << work.getTimeArea() << " " << work.getCompany() << endl;
    }
    shared_ptr<Prototype> clone() override 
    {
        return make_shared<Resume>(*this);
    }
private:
    string name;
    string sex;
    string age;
    WorkExperience work;
};

int main()
{
    Resume resume1(string("大鸟"));
    resume1.setPersonalInfo(string("男"), string("29"));
    resume1.setWorkExperience(string("1998-2000"), string("XX公司"));

    shared_ptr<Resume> resume2 = dynamic_pointer_cast<Resume>(resume1.clone());
    resume2->setWorkExperience(string("1998-2006"), string("YY公司"));
    
    shared_ptr<Resume> resume3 = dynamic_pointer_cast<Resume>(resume1.clone());
    resume3->setPersonalInfo(string("男"), string("24"));
    
    resume1.display();
    resume2->display();
    resume3->display();
    return 0;
}