#include<iostream>

using namespace std;

class UnitedNations;
class Country
{
public:
    Country(UnitedNations* unitedNations=nullptr): unitedNations(unitedNations) {}
    virtual string getClassName() = 0;
protected:
    UnitedNations* unitedNations;
};

class UnitedNations
{
public:
    virtual void declare(const string& message, Country& country) = 0;
};

class USA: public Country
{
public:
    USA(UnitedNations* unitedNations): Country(unitedNations) {}

    void declare(const string& message) { unitedNations->declare(message, *this);}
    void getMessage(const string& message) { cout << "美国获得对方信息" << message << endl; }

    string getClassName() { return string("USA"); }
};

class Iraq: public Country
{
public:
    Iraq(UnitedNations* unitedNations): Country(unitedNations) {}

    void declare(const string& message) { unitedNations->declare(message, *this); }
    void getMessage(const string& message) { cout << "伊拉克获得对方信息" << message << endl; }

    string getClassName() { return string("Iraq"); }
};

class UnitedNationsSecurityCouncil: public UnitedNations
{
public:
    UnitedNationsSecurityCouncil(): countryUSA(nullptr), countryIraq(nullptr) {}
    void setUSA(USA& value) { countryUSA = value; }
    void setIraq(Iraq& value) { countryIraq = value; }

    void declare(const string& message, Country& country)
    {
        if (country.getClassName() == countryUSA.getClassName())
            countryIraq.getMessage(message);
        else
            countryUSA.getMessage(message);
    }
private:
    USA countryUSA;
    Iraq countryIraq;
};

int main()
{
    UnitedNationsSecurityCouncil UNSC;
    USA c1(&UNSC);
    Iraq c2(&UNSC);

    UNSC.setUSA(c1);
    UNSC.setIraq(c2);

    c1.declare(string("不准研制核武器,否则就要发动战争!"));
    c2.declare(string("我们没有核武器,也不怕侵略。"));

    return 0;
}