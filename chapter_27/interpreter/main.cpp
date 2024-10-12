#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Context
{
public:
    string getInput() const { return input; }
    void setInput(const string& s) { input = s; }
    string getOutput() const { return output; }
    void setOutput(const string& s) { output = s; }
private:
    string input;
    string output;
};

class AbstractExpression
{
public:
    virtual void interpret(const Context& context) = 0;
    virtual ~AbstractExpression() = default;
};

class TerminalExpression: public AbstractExpression
{
public:
    void interpret(const Context& context) { cout << "ÖÕ¶Ë½âÊÍÆ÷" << endl; }
};

class NonterminalExpression: public AbstractExpression
{
public:
    void interpret(const Context& context) { cout << "·ÇÖÕ¶Ë½âÊÍÆ÷" << endl; }
};

int main()
{
    Context context;
    vector<shared_ptr<AbstractExpression>> ls;
    ls.emplace_back(new TerminalExpression());
    ls.emplace_back(new NonterminalExpression());
    ls.emplace_back(new TerminalExpression());
    ls.emplace_back(new NonterminalExpression());

    for (int i = 0; i < ls.size(); ++i)
        ls[i]->interpret(context);

    return 0;
}