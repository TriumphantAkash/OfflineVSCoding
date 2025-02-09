//Template is mechanism in STL that allows passing the data type to a function as an argument
//so that same code/function could be used for different data types
//SOURCE CODE contains FUNCTION/CLASS
//COMPILED CODE contains multiple copies of the same function/class
//Examples of function templates are sort(), max(), min(), printArray()

#include<iostream>

using namespace std;
template <typename T>
T myMax(T x, T y)
{
    return (x>y)?x:y;
}

//bubble sort using template
template <typename T1>
void bubbleSort(T1 a[], int len)
{
    int temp = 0;
    for(int i = len-1; i>0; i--)
    {
        for(int j = 0; j< i;j++)
        {
            if(a[j] > a[j+1])
            {
                //swap
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
template <typename T1>
void showList(T1 a[], int len)
{
    for(int l = 0;l < len;l++)
    {
        cout<<a[l]<<endl;
    }
}

/*
int main()
{
    cout<<myMax<int>(3,7)<<endl;
    cout<<myMax<char>('g','e')<<endl;
    cout<<myMax<double>(7.0, 8.5)<<endl;
    int a[5] = {2,1,5,4,3};
    bubbleSort(a, 5);
    showList(a, 5);
    cout<<a[0]<<endl;
    return 0;
}
*/

//CLASS TEMPLATES
/*
Class templates like functions templates, class templates are useful when a class defines something that is
independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, Etc.
*/

template <typename T> class Array
{
private:
    T* ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i<size;i++)
        ptr[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}