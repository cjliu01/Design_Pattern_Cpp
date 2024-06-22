#include<iostream>
#include<string>
#include<map>

using namespace std;

class WebSite
{
public:
    virtual void use() = 0;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use() { cout << "网站分类: " << name << endl; }
private:
    string name;
};

class WebSiteFactory
{
public:
    WebSite* getWebSiteCategory(const string& key) 
    { 
        map<string, WebSite*>::iterator it = flyweights.find(key);
        if (it == flyweights.end())
            flyweights[key] = new ConcreteWebSite(key); 
        return flyweights[key];   
    }
    ~WebSiteFactory() 
    {
        for (map<string, WebSite*>::iterator it = flyweights.begin(); it != flyweights.end(); ++it)
            delete it->second;
    }
    int getWebSiteCount() { return flyweights.size(); }
private:
    map<string, WebSite*> flyweights;
};

int main()
{
    WebSiteFactory f;
    WebSite* fx = f.getWebSiteCategory(string("产品展示"));
    fx->use();
    WebSite* fy = f.getWebSiteCategory(string("产品展示"));
    fy->use();
    WebSite* fz = f.getWebSiteCategory(string("产品展示"));
    fz->use();

    WebSite* fl = f.getWebSiteCategory(string("博客"));
    fl->use();
    WebSite* fm = f.getWebSiteCategory(string("博客"));
    fm->use();
    WebSite* fn = f.getWebSiteCategory(string("博客"));
    fn->use();

    cout << "网站分类总数为:" << f.getWebSiteCount() << endl;
    return 0;
}