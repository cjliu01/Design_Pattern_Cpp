#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
private:
    vector<string> parts;

public:
    void add(const string& part) { parts.push_back(part); }
    void show()
    {
        for (auto& part: parts)
            cout << part << endl;
    }

};

class Builder
{
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product getResult() = 0;
    virtual ~Builder() = default;
};

class concreteBuilder1: public Builder
{
public:
    void buildPartA() override { product.add(string("Part A")); }
    void buildPartB() override { product.add(string("Part B")); }
    Product getResult() override { return product; }
private:
    Product product;
};

class concreteBuilder2: public Builder
{
public:
    void buildPartA() override { product.add(string("Part X")); }
    void buildPartB() override { product.add(string("Part Y")); }
    Product getResult() override { return product; }
private:
    Product product;
};

class Director
{
public:
    void construct(Builder& builder)
    {
        builder.buildPartA();
        builder.buildPartB();
    }
};

int main()
{
    Director director;
    concreteBuilder1 builder1;
    concreteBuilder2 builder2;

    director.construct(builder1);
    Product product1 = builder1.getResult();
    product1.show();

    director.construct(builder2);
    Product product2 = builder2.getResult();
    product2.show();
    return 0;
}
