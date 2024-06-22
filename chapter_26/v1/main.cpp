#include<iostream>
#include<string>

using namespace std;
class WebSite
{
public:
    WebSite(const string& name): name(name) {}
    void use() { cout << "网站分类: " << name << endl; }
private:
    string name;
};

int main()
{
    WebSite fx(string("产品展示"));
    fx.use();
    WebSite fy(string("产品展示"));
    fy.use();
    WebSite fz(string("产品展示"));
    fz.use();

    WebSite fl(string("博客"));
    fl.use();
    WebSite fm(string("博客"));
    fm.use();
    WebSite fn(string("博客"));
    fn.use();

    return 0;
}