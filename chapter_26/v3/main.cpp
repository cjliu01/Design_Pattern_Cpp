#include <iostream>
#include <memory>
#include <string>
#include <map>

using namespace std;

class User
{
public:
    User(const string& value): name(value) {} 
    string getName() const { return name; } 
private:
    string name;
};

class WebSite
{
public:
    virtual void use(const User& user) = 0;
    virtual ~WebSite() = default;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use(const User& user) { cout << "网站分类: " << name << "用户: " << user.getName() << endl; }
private:
    string name;
};

class WebSiteFactory
{
public:
    shared_ptr<WebSite> getWebSiteCategory(const string& key) 
    { 
        auto it = flyweights.find(key);
        if (it == flyweights.end())
            flyweights[key] = make_shared<ConcreteWebSite>(key); 
        return flyweights[key];   
    }
    int getWebSiteCount() { return flyweights.size(); }

private:
    map<string, shared_ptr<WebSite>> flyweights;
};

int main()
{
    WebSiteFactory f;
    shared_ptr<WebSite> fx = f.getWebSiteCategory(string("产品展示"));
    fx->use(User(string("小菜")));
    shared_ptr<WebSite> fy = f.getWebSiteCategory(string("产品展示"));
    fy->use(User(string("大鸟")));
    shared_ptr<WebSite> fz = f.getWebSiteCategory(string("产品展示"));
    fz->use(User(string("娇娇")));

    shared_ptr<WebSite> fl = f.getWebSiteCategory(string("博客"));
    fl->use(User(string("老顽童")));
    shared_ptr<WebSite> fm = f.getWebSiteCategory(string("博客"));
    fm->use(User(string("桃谷六仙")));
    shared_ptr<WebSite> fn = f.getWebSiteCategory(string("博客"));
    fn->use(User(string("南海鳄神")));

    cout << "网站分类总数为:" << f.getWebSiteCount() << endl;
    return 0;
}