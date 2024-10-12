#include <iostream>

using namespace std;

class TestPaper
{
public:
    void testQuestion1()
    {
        cout << "杨过得到，后来给了郭靖，炼成倚天剑、屠龙刀的玄铁可能是[]\n" << 
            "a.球墨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维" << endl;
        cout << "答案: " << answer1() << endl;
    }
    void testQuestion2()
    {
        cout << "杨过、程英、陆无双铲除了情花，造成[]\n" << 
            "a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化" << endl;
        cout << "答案: " << answer2() << endl;
    }
    void testQuestion3()
    {
        cout << "蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药[]\n" << 
            "a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量的生牛奶 e.以上全不对" << endl;
        cout << "答案: " << answer3() << endl;
    }
    virtual ~TestPaper() = default;

protected:
    virtual string answer1() = 0;
    virtual string answer2() = 0;
    virtual string answer3() = 0;
};

class TestPaperA: public TestPaper
{
protected:
    string answer1() override { return string("b"); }
    string answer2() override { return string("a"); }
    string answer3() override { return string("c"); }
};

class TestPaperB: public TestPaper
{
protected:
    string answer1() override { return string("d"); }
    string answer2() override { return string("b"); }
    string answer3() override { return string("a"); }
};

int main()
{
    cout << "学生甲抄的试卷: " << endl;
    TestPaperA studentA;
    studentA.testQuestion1();
    studentA.testQuestion2();
    studentA.testQuestion3();

    cout << "学生乙抄的试卷: " << endl; 
    TestPaperB studentB;
    studentB.testQuestion1();
    studentB.testQuestion2();
    studentB.testQuestion3();

    return 0;
}