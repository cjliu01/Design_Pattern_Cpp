#include <iostream>
#include <memory>
#include <string>
#include <map>

using namespace std;

class FlyWeight
{
public:
    virtual void operation(int extrinsicstate) = 0;
    virtual ~FlyWeight() = default;
};

class ConcreteFlyWeight: public FlyWeight
{
public:
    void operation(int extrinsicstate) override { cout << "具体FlyWeight: " << extrinsicstate << endl; }
};

class UnsharedConcreteFlyWeight: public FlyWeight
{
public:
    void operation(int extrinsicstate) override { cout << "不共享的具体FlyWeight" << extrinsicstate << endl; }
};

class FlyWeightFactory
{
public:
    FlyWeightFactory() 
    {
        flyweights['X'] = make_shared<ConcreteFlyWeight>();
        flyweights['Y'] = make_shared<ConcreteFlyWeight>();
        flyweights['Z'] = make_shared<ConcreteFlyWeight>();
    }

    shared_ptr<FlyWeight> getFlyWeight(char key) { return flyweights[key]; }

private:
    map<char, shared_ptr<FlyWeight>> flyweights;
};

int main()
{
    int extrinsicstate = 22;
    FlyWeightFactory f;
    shared_ptr<FlyWeight> fx = f.getFlyWeight('X');
    fx->operation(--extrinsicstate);

    shared_ptr<FlyWeight> fy = f.getFlyWeight('Y');
    fy->operation(--extrinsicstate);

    shared_ptr<FlyWeight> fz = f.getFlyWeight('Z');
    fz->operation(--extrinsicstate);

    shared_ptr<FlyWeight> uf = make_shared<UnsharedConcreteFlyWeight>();    
    uf->operation(--extrinsicstate);
   
    return 0;
}