#include<iostream>

using namespace std;

class HandsetBrand
{
public:
    virtual void run() = 0;  
};

class HandsetBrandN: public HandsetBrand {};

class HandsetBrandM: public HandsetBrand {};

class HansetBrandMGame: public HandsetBrandM
{
public:
    void run() { cout << "运行M品牌手机游戏" << endl; }
};

class HandsetBrandNGame: public HandsetBrandN
{
public:
    void run() { cout << "运行N品牌手机游戏" << endl; }
};

class HandsetBrandMAddressList: public HandsetBrandM
{
public:
    void run() { cout << "运行M品牌手机通讯录" << endl; }
};

class HandsetBrandNAddressList: public HandsetBrandN
{
public:
    void run() { cout << "运行N品牌手机通讯录" << endl; }
};

int main()
{
    HandsetBrand *db = nullptr;
    db = new HandsetBrandMAddressList();
    db->run();

    db = new HansetBrandMGame();
    db->run();

    db = new HandsetBrandNAddressList();
    db->run();

    db = new HandsetBrandNGame();
    db->run();

    delete db;
    return 0;
}