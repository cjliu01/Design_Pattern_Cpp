#include<iostream>
#include<string>
#include<map>

using namespace std;

class FlyWeight
{
public:
    virtual void operation(int extrinsicstate) = 0;
};

class ConcreteFlyWeight: public FlyWeight
{
public:
    void operation(int extrinsicstate) { cout << "具体FlyWeight: " << extrinsicstate << endl; }
};

class UnsharedConcreteFlyWeight: public FlyWeight
{
public:
    void operation(int extrinsicstate) { cout << "不共享的具体FlyWeight" << extrinsicstate << endl; }
};

class FlyWeightFactory
{
public:
    FlyWeightFactory() 
    {
        flyweights['X'] = new ConcreteFlyWeight();
        flyweights['Y'] = new ConcreteFlyWeight();
        flyweights['Z'] = new ConcreteFlyWeight();
    }
    FlyWeight* getFlyWeight(char key) { return flyweights[key]; }
    ~FlyWeightFactory() 
    {
        for (map<char, FlyWeight*>::iterator it = flyweights.begin(); it != flyweights.end(); ++it)
            delete it->second;
    }
private:
    map<char, FlyWeight*> flyweights;
};

int main()
{
    int extrinsicstate = 22;
    FlyWeightFactory f;
    FlyWeight* fx = f.getFlyWeight('X');
    fx->operation(--extrinsicstate);

    FlyWeight* fy = f.getFlyWeight('Y');
    fy->operation(--extrinsicstate);

    FlyWeight* fz = f.getFlyWeight('Z');
    fz->operation(--extrinsicstate);

    FlyWeight* uf = new UnsharedConcreteFlyWeight();    
    uf->operation(--extrinsicstate);
    delete uf;
}