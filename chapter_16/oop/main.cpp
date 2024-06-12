#include<iostream>

using namespace std;

class Work
{
public:
    Work(int h=0, bool w=false): hour(h), workFinished(w) {}
    int getHour() { return hour; }
    void setHour(int h) { hour = h; }
    bool getWorkFinished() { return workFinished; }
    void setWorkFinished(bool w) { workFinished = w; }
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

private:
    int hour;
    bool workFinished;
};

int main()
{
    Work emergencyProjects;
    emergencyProjects.setHour(9);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(10);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(12);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(13);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(14);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(17);

    emergencyProjects.setWorkFinished(false);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(19);
    emergencyProjects.writeProgram();
    emergencyProjects.setHour(22);
    emergencyProjects.writeProgram();
    
    return 0;
}