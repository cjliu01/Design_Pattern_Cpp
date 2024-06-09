#include<iostream>

using namespace std;

class PersonBuilder
{
public:
    void build()
    {
        cout << "����" << person() << "�˵�ͷ" << endl;
        cout << "����" << person() << "�˵�����" << endl;
        cout << "����" << person() << "�˵�����" << endl;
        cout << "����" << person() << "�˵�����" << endl;
        cout << "����" << person() << "�˵����" << endl;
        cout << "����" << person() << "�˵��ҽ�" << endl;
    }
protected:
    virtual string person() = 0;
};
class PersonThinBuilder: public PersonBuilder
{
protected: 
    string person() { return string("��"); }
};

class PersonFatBuilder: public PersonBuilder
{
protected: 
    string person() { return string("��"); }
};

int main()
{
    PersonFatBuilder gFat;
    gFat.build();

    PersonThinBuilder gThin;
    gThin.build();
    return 0;
}