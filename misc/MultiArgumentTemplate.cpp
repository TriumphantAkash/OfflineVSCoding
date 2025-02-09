#include <iostream>

using namespace std;

template <class T, class U> class A
{
    T x;
    U y;
    static int count;

    static void incrementCount()
    {
        count++;
    }

public:
    A()
    {
        incrementCount();
        cout<<"Constructor counter : "<<count<<endl;
    }
};

template <typename T, typename Q>
int A<T,Q>::count = 0;
int main()
{
    A<char, char> a;
    A<int, int> b;
    return 0;
}