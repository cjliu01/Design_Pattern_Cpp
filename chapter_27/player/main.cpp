#include<iostream>
#include<string>

using namespace std;

class PlayContext
{
public:
    string getPlayText() const { return text; }
    void setPlayText(const string& s) { text = s;}
private:
    string text;
};

class Expression
{
public:
    virtual void excute(char key, double value) = 0;
    void interpret(PlayContext& context)
    {
        if (context.getPlayText().length() == 0)
            return ;
        else
        {
            char playKey = context.getPlayText()[0];
            context.setPlayText(context.getPlayText().substr(2));
            double playValue = stod(context.getPlayText().substr(0, context.getPlayText().find(" ")));
            context.setPlayText(context.getPlayText().substr(context.getPlayText().find(" ") + 1));
            excute(playKey, playValue);
        }
    }
};

class Note: public Expression
{
public:
    void excute(char key, double value)
    {
        string note;
        switch (key)
        {
            case 'C': note = string("1"); break;
            case 'D': note = string("2"); break;
            case 'E': note = string("3"); break;
            case 'F': note = string("4"); break;
            case 'G': note = string("5"); break;
            case 'A': note = string("6"); break;
            case 'B': note = string("7"); break;
        }
        cout << note << " "; 
    }
};

class Scale: public Expression
{
public:
    void excute(char key, double value)
    {
        string scale;
        switch (static_cast<int>(value))
        {
            case 1: scale = string("低音"); break;
            case 2: scale = string("中音"); break;
            case 3: scale = string("高音"); break;
        }
        cout << scale << " ";
    }
};

class Speed: public Expression
{
public:
    void excute(char key, double value)
    {
        string speed;
        if (value < 500)
            speed = string("快速");
        else if (value >= 1000)
            speed = string("慢速");
        else
            speed = string("中速");
        cout << speed << " ";
    }
};

int main()
{
    PlayContext context;
    cout << "音乐—上海滩: " << endl;
    context.setPlayText(string("T 500 O 2 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3 "));
    Expression* expression = nullptr;
    while (context.getPlayText().length() > 0)
    {
        char key = context.getPlayText()[0];
        switch (key)
        {
            case 'O': expression = new Scale(); break;
            case 'C': 
            case 'D': 
            case 'E': 
            case 'F': 
            case 'G': 
            case 'A': 
            case 'B':
            case 'P': expression = new Note(); break;
            case 'T': expression = new Speed(); break;
        }
        expression->interpret(context);
        delete expression;
    }
    return 0;
}