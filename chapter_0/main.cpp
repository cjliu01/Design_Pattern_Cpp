#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Change
{
public:
    virtual string changeThing(const string &thing) = 0;
};

class Animal
{
public:
    Animal() { this->name = string("无名"); }
    Animal(const string &name) { this->name = name; }
    void setShoutNum(int num) { this->shoutNum = num; }
    int getShoutNum() { return this->shoutNum; }
    string shout() 
    {
        string result("");
        for (int i = 0; i < this->shoutNum; i++)
            result += getShoutSound();
        return "我的名字叫" + this->name + " " + result; 
    }

protected:
    string name;
    int shoutNum = 3;
    virtual string getShoutSound() = 0;

};

class Cat: public Animal
{
public:
    Cat(): Animal() {}
    Cat(const string &name): Animal(name) {}
    
protected:
    string getShoutSound() { return string("喵"); }
};

class Dog: public Animal
{
public:
    Dog(): Animal() {}
    Dog(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("汪"); } 
};

class Sheep: public Animal
{
public:
    Sheep(): Animal() {}
    Sheep(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("咩"); } 
};

class Cattle: public Animal
{
public:
    Cattle(): Animal() {}
    Cattle(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("哞"); } 
};

class Monkey: public Animal
{
public:
    Monkey(): Animal() {}
    Monkey(const string &name): Animal(name) {}
protected:
    string getShoutSound() { return string("呔"); } 
};

class MachineCat: public Cat, public Change
{
public:
    MachineCat(): Cat(), Change() {}
    MachineCat(const string &name): Cat(name), Change() {}
    string changeThing(const string& thing)
    {
        return shout() + string(", 我有万能的口袋, 我可变出") + thing;
    }

};

class StoneMonkey: public Monkey, public Change
{
public:
    StoneMonkey(): Monkey(), Change() {}
    StoneMonkey(const string &name): Monkey(name), Change() {}
    string changeThing(const string& thing)
    {
        return shout() + string(", 我有万能的口袋, 我可变出") + thing;
    }
protected:
    string getShoutSound() { return string("俺老孙来也"); } 
};

int main()
{
    Dog dog1(string("阿毛"));
    Cattle cattle(string("小黑"));
    Cat cat1(string("小花"));
    Sheep sheep(string("娇娇"));
    Cat cat2(string("咪咪"));
    MachineCat machineCat(string("叮铛"));
    StoneMonkey stoneMonkey(string("孙悟空"));
    vector<Animal*> animals;
    animals.push_back(&dog1);
    animals.push_back(&cattle);
    animals.push_back(&cat1);
    animals.push_back(&cat2);
    animals.push_back(&sheep);
    animals.push_back(&stoneMonkey);

    for (int i = 0; i < animals.size(); i++)
        cout << (*animals[i]).shout() << endl;
    cout << machineCat.changeThing(string("各种各样的东西! ")) << endl;
    cout << stoneMonkey.changeThing(string("金箍棒! "));
    return 0;
}
