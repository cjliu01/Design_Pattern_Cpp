#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;

class Singleton
{
private:
    static unique_ptr<Singleton> instance;
    static mutex mtx;

    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton &&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton &&) = delete;

public:
    static Singleton* getInstance()
    {
        lock_guard<mutex> lock(mtx);
        if (instance.get() == nullptr)
            instance.reset(new Singleton);
        return instance.get();
    }   
};
unique_ptr<Singleton> Singleton::instance;
mutex Singleton::mtx;

void testSingleton(int id)
{
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    if (singleton1 == singleton2)
        cout << "两个对象是相同的实例" << endl;
    cout << "Thread " << id << " is using the singleton." << endl;
}

int main()
{
    thread t1(testSingleton, 1);
    thread t2(testSingleton, 2);
    thread t3(testSingleton, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}