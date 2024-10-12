#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
private:
    Singleton() {} ;
    static unique_ptr<Singleton> instance;
public:
    static Singleton* getInstance()
    {
        if (instance == nullptr)
            instance.reset(new Singleton);
        return instance.get();
    }
};
unique_ptr<Singleton> Singleton::instance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2)
        cout << "两个对象是相同的实例." << endl;
    return 0;
}