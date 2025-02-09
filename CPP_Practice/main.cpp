#include <iostream>
#include <memory>
#include<cmath>

using namespace std;
class MyClass
{
private:
    //char character;
    //int integer;

public:
    MyClass()
    {
        cout<<"Created MyClass object"<<endl;
    }

    ~MyClass()
    {
        cout<<"Destroyed MyClass object"<<endl;
    }

    virtual void Print()
    {
        cout<<"print"<<endl;
    }
    virtual void Print1()
    {
        cout<<"print1"<<endl;
    }

    virtual void Print2()
    {
        cout<<"print2"<<endl;
    }

    virtual void Print3()
    {
        cout<<"print3"<<endl;
    }
};

class MyChildClass:public MyClass
{
private:

public:
    void Print()
    {
        cout<<"MyChildClass Print()"<<endl;
    }

};
    bool should_i_swap(int a, int b)
    {
        string stringA = to_string(a);
        string stringB = to_string(b);

        if(stoi(stringA+stringB) > stoi(stringB+stringA))
        {return true;}
        else
        {return false;}
    }
    void largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),should_i_swap);

        for(int i=0;i<nums.size(); i++)
        {
            cout<<nums[i]<<endl;
        }
    }


int main()
{
    cout<<"Hello!"<<endl;
    MyClass * myClass1 = new MyChildClass();
    cout<<"myClass1 pointer is pointing to : "<<myClass1<<endl;
    cout<<"size of class is : "<<sizeof(MyClass)<<endl;
    cout<<"size of object is : "<<sizeof(*myClass1)<<endl;
    cout<<"size of object pointer is : "<<sizeof(myClass1)<<endl;

    cout<<"haha"<<endl;
    myClass1->Print();

    vector<int> v = {75, 234, 7568, 23,0};
    largestNumber(v);
    return 0;
}