#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Component
{
public:
    Component(const string& name): name(name) {}
    virtual void add(Component* c) = 0;
    virtual void remove(Component* c) = 0;
    virtual void display(int depth) = 0;

    bool operator==(const Component& c) { return name == c.name;}
    bool operator!=(const Component& c) { return !(*this == c); }
protected:
    string name;
};

class Leaf: public Component
{
public:
    Leaf(const string& name): Component(name) {}

    void add(Component *c) { cout << "Cannot add to a leaf." << endl; }
    void remove(Component *c) { cout << "Cannot remove from a leaf." << endl;}
    void display(int depth)
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
    void add(Component *c) { childen.push_back(c); }
    void remove(Component *c)
    {
        for (int i = 0; i < childen.size(); ++i)
        {
            if (childen[i] == c)
            {
                delete c;
                childen.erase(childen.begin() + i);
            }
        }
    }
    void display(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << name << endl;
        for (int i = 0; i < childen.size(); ++i)
            childen[i]->display(depth + 2);
    }
    ~Composite() 
    {
        for (int i = 0; i < childen.size(); ++i)
            delete childen[i];
    }
private:
    vector<Component *> childen;
};

int main()
{
    Composite root(string("root"));
    root.add(new Leaf(string("Leaf A")));
    root.add(new Leaf(string("Leaf B")));

    Composite *comp = new Composite(string("Composite X"));
    comp->add(new Leaf(string("Leaf XA")));
    comp->add(new Leaf(string("Leaf XB")));
    root.add(comp);

    Composite *comp2 = new Composite(string("Composite XY"));
    comp2->add(new Leaf(string("Leaf XYA")));
    comp2->add(new Leaf(string("Leaf XYB")));
    comp->add(comp2);

    Leaf *leaf = new Leaf(string("Leaf C"));
    root.add(leaf);

    Leaf *leaf2 = new Leaf(string("Leaf D"));
    root.add(leaf2);
    root.remove(leaf2);

    root.display(1);
    
    return 0;
}