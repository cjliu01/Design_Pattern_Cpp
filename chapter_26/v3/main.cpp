#include<iostream>
#include<string>
#include<map>

using namespace std;

class User
{
public:
    User(const string& value): name(value) {} 
    string getName() { return name; } 
private:
    string name;
};

class WebSite
{
public:
    virtual void use(User user) = 0;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use(User user) { cout << "网站分类: " << name << "用户: " << user.getName() << endl; }
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
    fx->use(User(string("小菜")));
    WebSite* fy = f.getWebSiteCategory(string("产品展示"));
    fy->use(User(string("大鸟")));
    WebSite* fz = f.getWebSiteCategory(string("产品展示"));
    fz->use(User(string("娇娇")));

    WebSite* fl = f.getWebSiteCategory(string("博客"));
    fl->use(User(string("老顽童")));
    WebSite* fm = f.getWebSiteCategory(string("博客"));
    fm->use(User(string("桃谷六仙")));
    WebSite* fn = f.getWebSiteCategory(string("博客"));
    fn->use(User(string("南海鳄神")));

    cout << "网站分类总数为:" << f.getWebSiteCount() << endl;
    return 0;
}