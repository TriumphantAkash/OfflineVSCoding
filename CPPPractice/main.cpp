#include <iostream>
#include <memory>

using namespace std;
typedef struct MyStruct
{
    static int var1;
    int var2;
}MyStruct;

int MyStruct::var1 = 10;

class MyClass
{
public:
    MyClass()
    {
        cout<<"Created MyClass object"<<endl;
    }

    ~MyClass()
    {
        cout<<"Destroyed MyClass object"<<endl;
    }

    void Print()
    {
        cout<<"print"<<endl;
    }
};

int main()
{
    cout<<"Hello!"<<endl;
    // MyClass * myClass1 = new MyClass();
    // cout<<"myClass1 pointer is pointing to : "<<myClass1<<endl;

    // myClass1->setVars(10,20);
    // //cout<<"sum of vars is "<<myClass1->sum()<<endl;


    // cout<<"myClass1 variables addresses: "<< &(myClass1->var1)<<" and "<< &(myClass1->var2)<<endl;

    // MyClass * myClass2 = new MyClass();
    // cout<<"myClass2 pointer is pointing to : "<<myClass2<<endl;
    // cout<<"myClass2 variables addresses: "<< &(myClass2->var1)<<" and "<< &(myClass2->var2)<<endl;

    // MyStruct *str1 = new MyStruct();
    // MyStruct *str2 = new MyStruct();

    // cout<<"str1 is pointing to : "<<str1<<endl;
    // cout<<"str2 is pointing to : "<<str2<<endl;

    // cout<<"str1 variables addresses (var1 and var2)"<<&(str1->var1)<<" and "<<&(str1->var2)<<endl;
    // cout<<"str2 variables addresses (var1 and var2)"<<&(str2->var1)<<" and "<<&(str2->var2)<<endl;

    // {
    //     unique_ptr<MyClass> ptr(new MyClass());
    //     //unique_ptr<MyClass> obj = make_unique<MyClass>();
    //     ptr->Print();

    //     //can not copy this pointer into another
    //     //unique_ptr obj2 = obj;
    // }
    {
        shared_ptr<MyClass> s_ptr2 = NULL;
        cout<<s_ptr2.use_count()<<endl;
        {
            shared_ptr<MyClass> s_ptr1(new MyClass());
            cout<<s_ptr1.use_count()<<endl;
            s_ptr2 = s_ptr1;
            cout<<s_ptr1.use_count()<<endl;
        }
        cout<<s_ptr2.use_count()<<endl;
    }
    return 0;
}