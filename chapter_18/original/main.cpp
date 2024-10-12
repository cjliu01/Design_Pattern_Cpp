#include <iostream>

using namespace std;

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

private:
    int vitality;
    int attack;
    int defense;
};

int main()
{
    GameRole role;
    role.getInitState();
    role.displayState();

    GameRole backup;
    backup.setVitality(role.getVitality());
    backup.setAttack(role.getAttack());
    backup.setDefense(role.getDefense());

    role.fight();
    role.displayState();

    role.setVitality(backup.getVitality());
    role.setAttack(backup.getAttack());
    role.setDefense(backup.getDefense());

    role.displayState();
    return 0;
}