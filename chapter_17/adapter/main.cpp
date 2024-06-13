#include<iostream>
#include<string>
using namespace std;

class Player
{
public:
    Player(const string& name): name(name) {}
    virtual void attack() = 0;
    virtual void defence() = 0;
protected:
    string name;
};

class Forwards: public Player
{
public:
    Forwards(const string& name): Player(name) {}
    void attack() { cout << "Ç°·æ " << name << " ½ø¹¥ " << endl; }
    void defence() { cout << "Ç°·æ " << name << " ·ÀÊØ " << endl; }
};

class Center: public Player
{
public:
    Center(const string& name): Player(name) {}
    void attack() { cout << "ÖÐ·æ " << name << " ½ø¹¥ " << endl; }
    void defence() { cout << "ÖÐ·æ " << name << " ·ÀÊØ " << endl; }
};

class Guards: public Player
{
public:
    Guards(const string& name): Player(name) {}
    void attack() { cout << "ºóÎÀ " << name << " ½ø¹¥ " << endl; }
    void defence() { cout << "ºóÎÀ " << name << " ½ø¹¥ " << endl; }
};

class ForeignCenter
{
public:
    string getName() { return name; }
    void setName(const string& name) { this->name = name; }
    void jingong() { cout << "Íâ¼®ÖÐ·æ " << name << " ½ø¹¥ " << endl; }
    void fangshou() { cout << "Íâ¼®ÖÐ·æ " << name << " ·ÀÊØ " << endl; }
private: 
    string name;
};

class Translator: public Player
{
public:
    Translator(const string& name): Player(name) { foreignCenter.setName(name); }
    void attack() { foreignCenter.jingong(); }
    void defence() { foreignCenter.fangshou(); }

private:
    ForeignCenter foreignCenter;
};

int main()
{
    Player* forwards = new Forwards(string("°ÍµÙ¶û"));
    forwards->attack();
    Player* guards = new Guards(string("Âó¿Ë¸ñÀ×µÏ"));
    guards->defence(); 
    Player* center = new Translator(string("Ò¦Ã÷"));

    center->attack();
    center->defence();

    delete forwards;
    delete guards;
    delete center;
    return 0;
}