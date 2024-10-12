#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Component
{
public:
    Component(const string& name): name(name) {}
    virtual void add(shared_ptr<Component> c) = 0;
    virtual void remove(shared_ptr<Component> c) = 0;
    virtual void display(int depth) = 0;
    virtual ~Component() = default;

    bool operator==(const Component& c) { return name == c.name;}
    bool operator!=(const Component& c) { return !(*this == c); }
protected:
    string name;
};

class Leaf: public Component
{
public:
    Leaf(const string& name): Component(name) {}

    void add(shared_ptr<Component> c) override { cout << "Cannot add to a leaf." << endl; }
    void remove(shared_ptr<Component> c) override { cout << "Cannot remove from a leaf." << endl;}
    void display(int depth) override
    {
        for (int i = 0; i < depth; i++)
            cout << "-";
        cout << name << endl;
    }
};

class Composite: public Component
{
public:
    Composite(const string& name): Component(name) {}
    void add(shared_ptr<Component> c) override { childen.push_back(c); }
    void remove(shared_ptr<Component> c) override
    {
        auto it = find(childen.begin(), childen.end(), c);
        if (it != childen.end())
            childen.erase(it);
        else
            cout << "Component not found." << endl;
    }
    void display(int depth) override
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->display(depth + 2);
    }

private:
    vector<shared_ptr<Component>> childen;
};

int main()
{
    Composite root("root");
    root.add(make_shared<Leaf>("Leaf A"));
    root.add(make_shared<Leaf>("Leaf B"));

    shared_ptr<Component> comp = make_shared<Composite>("Composite X");
    comp->add(make_shared<Leaf>("Leaf XA"));
    comp->add(make_shared<Leaf>("Leaf XB"));
    root.add(comp);

    shared_ptr<Component> comp2 = make_shared<Composite>("Composite XY");
    comp2->add(make_shared<Leaf>("Leaf XYA"));
    comp2->add(make_shared<Leaf>("Leaf XYB"));
    comp->add(comp2);

    shared_ptr<Component> leaf = make_shared<Leaf>("Leaf C");
    root.add(leaf);

    shared_ptr<Leaf> leaf2 = make_shared<Leaf>("Leaf D");
    root.add(leaf2);
    root.remove(leaf2);

    root.display(1);
    
    return 0;
}