#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Context
{
public:
    string getInput() { return input; }
    void setInput(const string& s) { input = s; }
    string getOutput() { return output; }
    void setOutput(const string& s) { output = s; }
private:
    string input;
    string output;
};

class AbstractExpression
{
public:
    virtual void interpret(const Context& context) = 0;
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
    vector<AbstractExpression *> ls;
    ls.push_back(new TerminalExpression());
    ls.push_back(new NonterminalExpression());
    ls.push_back(new TerminalExpression());
    ls.push_back(new NonterminalExpression());

    for (int i = 0; i < ls.size(); ++i)
        ls[i]->interpret(context);
    
    for (int i = 0; i < ls.size(); ++i)
        delete ls[i];

    return 0;
}