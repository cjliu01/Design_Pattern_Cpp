#include<iostream>

using namespace std;

class HandsetSoft
{
public:
    virtual void run() = 0;
};

class HandsetGame: public HandsetSoft
{
public:
    void run() { cout << "手机游戏" << endl; }
};

class HandsetAddressList: public HandsetSoft
{
public:
    void run() { cout << "手机通信录" << endl; }
};

class HandsetMusicPlay: public HandsetSoft
{
public:
    void run() { cout << "音乐播放" << endl; }
};

class HandsetBrand
{
public:
    void setHandsetSoft(HandsetSoft *soft) 
    {
        delete this->soft;
        this->soft = soft; 
    }
    ~HandsetBrand() { delete soft; }
    HandsetBrand(HandsetSoft *soft=nullptr): soft(soft) {} 
    virtual void run() = 0;
protected:
    HandsetSoft *soft;
};

class HandsetBrandM: public HandsetBrand
{
public:
    void run() 
    {
        cout << "品牌M" << endl;
        soft->run();
    }
};

class HandsetBrandN: public HandsetBrand
{
public:
    void run()
    {
        cout << "品牌N" << endl;
        soft->run();
    }
};

class HandsetBrandS: public HandsetBrand
{
public:
    void run()
    {
        cout << "品牌S" << endl;
        soft->run();
    }
};

int main()
{
    HandsetBrand *db = nullptr;
    db = new HandsetBrandN();
    
    db->setHandsetSoft(new HandsetGame);
    db->run();

    db->setHandsetSoft(new HandsetAddressList);
    db->run();

    delete db;
    return 0;
}