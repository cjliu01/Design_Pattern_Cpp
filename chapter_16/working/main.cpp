#include <iostream>
#include <memory>

using namespace std;

class Work;
class State
{
public:
    virtual void writeProgram(Work& w) = 0;
    virtual ~State() = default;
};


class ForenonState: public State
{
public:
    void writeProgram(Work& w) override;
};

class NoonState: public State
{
public:
    void writeProgram(Work& w) override;  
};

class AfternoonState: public State
{
public:
    void writeProgram(Work& w) override;
};

class EveningState: public State
{
public:
    void writeProgram(Work& w) override;
};

class SleepingState: public State
{
public:
    void writeProgram(Work& w) override;
};

class RestState: public State
{
public:
    void writeProgram(Work& w) override;
};

class Work
{
public:
    Work(): current(new ForenonState) {}
    void setState(State* s) { current.reset(s); }
    void writeProgram() { current->writeProgram(*this); }
    int getHour() { return hour; }
    void setHour(int value) { hour = value; }
    bool getWorkFinished() { return workFinished; }
    void setWorkFinished(bool value) { workFinished = value; }
private:
    int hour;
    bool workFinished = false;
    shared_ptr<State> current;
};


void ForenonState::writeProgram(Work& w)
{

    if (w.getHour() < 12)
        cout << "当前时间" << w.getHour() << "点 上午工作, 精神百倍" << endl;
    else
    {
        w.setState(new NoonState);
        w.writeProgram();
    }

}

void NoonState::writeProgram(Work& w)
{
    if (w.getHour() < 13)
        cout << "当前时间" << w.getHour() << "点 饿了，午饭；犯困，午休。" << endl;
    else
    {
        w.setState(new AfternoonState);
        w.writeProgram();
    }
}

void AfternoonState::writeProgram(Work& w)
{
    if (w.getHour() < 17)
        cout << "当前时间" << w.getHour() << "点 下午状态还不错，继续努力" << endl;
    else
    {
        w.setState(new EveningState);
        w.writeProgram();
    }
}

void EveningState::writeProgram(Work& w)
{
    if (w.getWorkFinished())
    {
        w.setState(new RestState);
        w.writeProgram();
    }
    else
    {
        if (w.getHour() < 21)
            cout << "当前时间" << w.getHour() << "点 加班哦，疲累之极" << endl;
        else
        {
            w.setState(new SleepingState);
            w.writeProgram();
        }
    }
}

void SleepingState::writeProgram(Work& w)
{
    cout << "当前时间" << w.getHour() << "点 不行了，睡着了。" << endl;
}

void RestState::writeProgram(Work& w)
{
    cout << "当前时间" << w.getHour() << "点 下班回家了" << endl;
}

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