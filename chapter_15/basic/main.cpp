#include <iostream>
#include <string>

using namespace std;

class User
{
public:
    void setId(int value) { _id = value; }
    int getId() { return _id; }

    string getName() { return _name; }
    void setName(const string& value) { _name = value; }

private:
    int _id;
    string _name;
};

class SqlserverUser
{
public:
    void insert(User& user) { cout << "在SQL Server中给User表增加一条记录" << endl; }
    User getUser(int id) 
    { 
        cout << "在SQL Server中根据用户ID得到User表的一条记录" << endl; 
        return User();    
    }
};

int main()
{
    User user;
    SqlserverUser su;

    su.insert(user);
    su.getUser(1);
    return 0;
}