#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Player
{
public:
    Player(const string& name): name(name) {}
    virtual void attack() = 0;
    virtual void defence() = 0;
    virtual ~Player() = default;
protected:
    string name;
};

class Forwards: public Player
{
public:
    Forwards(const string& name): Player(name) {}
    void attack() override { cout << "Ç°·æ " << name << " ½ø¹¥ " << endl; }
    void defence() override { cout << "Ç°·æ " << name << " ·ÀÊØ " << endl; }
};

class Center: public Player
{
public:
    Center(const string& name): Player(name) {}
    void attack() override { cout << "ÖÐ·æ " << name << " ½ø¹¥ " << endl; }
    void defence() override { cout << "ÖÐ·æ " << name << " ·ÀÊØ " << endl; }
};

class Guards: public Player
{
public:
    Guards(const string& name): Player(name) {}
    void attack() override { cout << "ºóÎÀ " << name << " ½ø¹¥ " << endl; }
    void defence() override { cout << "ºóÎÀ " << name << " ½ø¹¥ " << endl; }
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
    void attack() override { foreignCenter.jingong(); }
    void defence() override { foreignCenter.fangshou(); }

private:
    ForeignCenter foreignCenter;
};

int main()
{
    shared_ptr<Player> forwards = make_shared<Forwards>("°ÍµÙ¶û");
    forwards->attack();
    shared_ptr<Player> guards = make_shared<Guards>("Âó¿Ë¸ñÀ×µÏ");
    guards->defence(); 
    shared_ptr<Player> center = make_shared<Translator>("Ò¦Ã÷");

    center->attack();
    center->defence();

    return 0;
}