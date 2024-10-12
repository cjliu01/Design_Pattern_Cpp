#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;

class WebSite
{
public:
    virtual void use() = 0;
    virtual ~WebSite() = default;
};

class ConcreteWebSite: public WebSite
{
public:
    ConcreteWebSite(const string& name): name(name) {}
    void use() override { cout << "网站分类: " << name << endl; }
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
    fx->use();
    shared_ptr<WebSite> fy = f.getWebSiteCategory(string("产品展示"));
    fy->use();
    shared_ptr<WebSite> fz = f.getWebSiteCategory(string("产品展示"));
    fz->use();

    shared_ptr<WebSite> fl = f.getWebSiteCategory(string("博客"));
    fl->use();
    shared_ptr<WebSite> fm = f.getWebSiteCategory(string("博客"));
    fm->use();
    shared_ptr<WebSite> fn = f.getWebSiteCategory(string("博客"));
    fn->use();

    cout << "网站分类总数为:" << f.getWebSiteCount() << endl;
    return 0;
}