#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Iterator
{
public:
    virtual string first() = 0;
    virtual string next() = 0;
    virtual bool isDone() = 0;
    virtual string currentItem() = 0;
    virtual ~Iterator() = default;
};

class Aggregate
{
public:
    virtual shared_ptr<Iterator> createIterator() = 0;
    virtual ~Aggregate() = default;
protected:
    shared_ptr<Iterator> iterator;
};

class ConcreteAggregate: public Aggregate
{
public:
    shared_ptr<Iterator> createIterator(); 
    int getCount() { return items.size(); }
    void add(const string& item) { items.push_back(item); }
    string getCurrentItem(int index) { return items[index]; }
private:
    vector<string> items;
};

class ConcreteIterator: public Iterator
{
public:
    ConcreteIterator(const ConcreteAggregate& aggregate_): aggregate(aggregate_), current(0) {}
    string first() override { return aggregate.getCurrentItem(0); }
    string next() override
    {
        string ret;
        ++current;
        if (current < aggregate.getCount())
            ret = aggregate.getCurrentItem(current);
        return ret; 
    }
    bool isDone() override { return current >= aggregate.getCount(); }
    string currentItem() override { return aggregate.getCurrentItem(current); }
private:
    ConcreteAggregate aggregate;
    int current;
};

class ConcreteIteratorDesc: public Iterator
{
public:
    ConcreteIteratorDesc(const ConcreteAggregate& aggregate_): aggregate(aggregate_), current(aggregate.getCount() - 1) {}
    string first() override { return aggregate.getCurrentItem(aggregate.getCount() - 1); }
    string next() override
    {
        string ret;
        --current;
        if (current >= 0)
            ret = aggregate.getCurrentItem(current);
        return ret;
    }
    bool isDone() override { return current < 0; }
    string currentItem() override { return aggregate.getCurrentItem(current); }
private: 
    ConcreteAggregate aggregate;
    int current;
};

shared_ptr<Iterator> ConcreteAggregate::createIterator()
{
    iterator = make_shared<ConcreteIteratorDesc>(*this);
    return iterator;
}

int main()
{
    ConcreteAggregate bus;
    bus.add(string("大鸟"));
    bus.add(string("小菜"));
    bus.add(string("行李"));
    bus.add(string("老外"));
    bus.add(string("公交内部员工"));
    bus.add(string("小偷"));

    shared_ptr<Iterator> conductor = bus.createIterator();
    conductor->first();
    while (!conductor->isDone())
    {
        cout << conductor->currentItem() << ", 请买车票!" << endl;
        conductor->next();
    }
    return 0;
}