#include <iostream>
#include <string>

using namespace std;

class RoleStateMemento
{
public:
    RoleStateMemento(int vitality=0, int attack=0, int defense=0): vitality(vitality), attack(attack), defense(defense) {}

    int getVitality() const { return vitality; }
    void setVitality(int value) { vitality = value; }
    int getAttack() const { return attack; }
    void setAttack(int value) { attack = value; }
    int getDefense() const { return defense; }
    void setDefense(int value) { defense = value; }

private:
    int vitality;
    int attack;
    int defense;
};

class GameRole
{
public:
    int getVitality() { return vitality; }
    void setVitality(int value) { vitality = value; }
    int getAttack() { return attack; }
    void setAttack(int value) { attack = value; }
    int getDefense() { return defense; }
    void setDefense(int value) { defense = value; }
    void displayState()
    {
        cout << "角色当前状态";
        cout << "体力: " << vitality << endl;
        cout << "攻击力: " << attack << endl;
        cout << "防御力: " << defense << endl;
    }
    void getInitState()
    {
        vitality = 100;
        attack = 100;
        defense = 100;
    }
    void fight()
    {
        vitality = 0;
        attack = 0;
        defense = 0;
    }

    RoleStateMemento saveState() { return RoleStateMemento(vitality, attack, defense); }
    void recoveryState(const RoleStateMemento& memento)
    {
        setVitality(memento.getVitality());
        setAttack(memento.getAttack());
        setDefense(memento.getDefense());
    }
    
private:
    int vitality;
    int attack;
    int defense;
};

class RoleStateCaretaker
{
public:
    void setRoleStateMemento(const RoleStateMemento& memento_) { memento = memento_; }
    RoleStateMemento getRoleStateMemento() { return memento; }
private:
    RoleStateMemento memento;
};

int main()
{
    GameRole role;
    role.getInitState();
    role.displayState();

    RoleStateCaretaker stateCaretaker;
    stateCaretaker.setRoleStateMemento(role.saveState());

    role.fight();
    role.displayState();

    role.recoveryState(stateCaretaker.getRoleStateMemento());
    role.displayState();

    return 0;
}