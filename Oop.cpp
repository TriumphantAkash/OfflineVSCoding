#include <iostream>

using namespace std;

class Parent
{
public:
    string pName;
    char pSex;
    int pAge;

protected:
    int testVar;
};

class Child : Parent
{
private:
    string NameChild;
public:
    int cAge;
    char cSex;
public:
    int protectedDemo()
    {
        testVar = 10;
        return testVar;
    }
};

int main()
{
    Child c;
    cout << c.protectedDemo()<<endl;
    return 0;
}