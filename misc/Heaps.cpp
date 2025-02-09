#include <iostream>

using namespace std;

vector<int> v;
void insertToHeap(int n)
{
    //1) Insert at the last
    v.push_back(n);
    int i = v.size() - 1;
    //2) percolate it up based on the logic: keep on swapping this with parent until parent is bigger
    while(i > 0 && v[i]>v[(i-1)/2])
    {
        swap(v[i], v[(i-1)/2]);
        i = (i-1)/2;
    }
}

int deleteFromHeap()
{
    //1) remove from the top
    int size = v.size();
    if(size == 0)
    {return -1;}

    int ret = v[0];
    int i = 0;
    //2) take the last element and put it on top
    v[i] = v[size - 1];
    v.pop_back();

    //3) percolate it down based on the logic: keep on swapping the node with the bigger child until both child are smaller than this node
    while((2*i+2) < size && v[i] < max(v[2*i+1],v[2*i+2]))
    {
        if(v[2*i+1] > v[2*i+2]){
            swap(v[i], v[2*i+1]);
            i = 2*i+1;
        }else{
            swap(v[i], v[2*i+2]);
            i = 2*i+2;
        }
    }
    return ret;
}

void printHeap()
{
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
}
int main()
{
    int heapSize = 7;
    insertToHeap(1);
    insertToHeap(5);
    insertToHeap(3);
    insertToHeap(23);
    insertToHeap(2);
    printHeap();

    cout<<"Popped Item from Heap: "<<deleteFromHeap()<<endl;

    printHeap();
    return 0;
}