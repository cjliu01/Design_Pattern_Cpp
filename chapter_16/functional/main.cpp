#include<iostream>

using namespace std;
int hour = 0;
bool workFinished = false;

void writeProgram()
{
    if (hour < 12) 
        cout << "当前时间" << hour << "点，上午工作，精神百倍" << endl;
    else if (hour < 13)
        cout << "当前时间" << hour << "点，饿了，午饭；犯困，午休" << endl;
    else if (hour < 17)
        cout << "当前时间" << hour << "点，下午状态还不错，继续努力" << endl;
    else    
    {
        if (workFinished)
            cout << "当前时间" << hour << "点，下班回家了" << endl;
        else
        {
            if (hour < 21)
                cout << "当前时间: " << hour << "点，加班哦，疲累之极" << endl;
            else      
                cout << "当前时间: " << hour << "点，不行了，睡着了。" << endl;
        }
    }
}

int main()
{
    hour = 9;
    writeProgram();
    hour = 10;
    writeProgram();
    hour = 12;
    writeProgram();
    hour = 13;
    writeProgram();
    hour = 14;
    writeProgram();
    hour = 17;
    writeProgram();
    
    workFinished = false;

    writeProgram();
    hour = 19;
    writeProgram();
    hour = 22;
    writeProgram();
    return 0;
}