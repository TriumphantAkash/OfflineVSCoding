//SEQUENCE CONTAINERS IMPLEMENT DATA STRUCTURES THAT CAN BE ACCESSED SEQUENTIALLY
#include<iostream>
#include<list>
#include<deque>
using namespace std;

/*
1) ARRAY CLASS
Advantages over C style arrays
    -> Knows its own size
    -> less chances of Array being decayed into a pointer
    -> Array classes are generally more efficient, light-weight and reliable
*/
void ArrayExperiments()
{
    array<int,6> ar = {1,2,3,4,5,6};
    cout<<ar[1]<<endl;
    cout<<ar.at(2)<<endl;
    cout<<ar.end()<<endl;
    cout<<ar.begin()<<endl;
    cout<<get<0>(ar)<<endl;
    cout<<ar.back()<<endl;
    cout<<"data() is : "<<ar.data()<<endl;
    cout<<ar.max_size()<<endl;
    cout<<"printing all elements now"<<endl;
    for(auto x:ar)
    {
        cout<<x<<endl;
    }

    ar.fill(0);
    cout<<"printing all elements after filling with zero"<<endl;
    for(auto x:ar)
    {
        cout<<x<<endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
2) VECTOR CLASS
    -> same as dynamic array with ability to resize itself automatically if needed
    -> uses CONTUGUOUS MEMORY like arrays so can be accessed using iterators
    -> insert/delete at end is constant time
    -> insert/delete anywhere else is linear time (COSTLY)
*/
void printVector(vector<int> *v)
{
    cout<<"printing vector elements: "<<endl;
    for(auto itr = v->begin(); itr != v->end(); itr++)
    {
        cout<<*itr<<endl;
    }
}

void fillVector(vector<int> *vPtr)
{
    cout<<"Filling vector..."<<endl;
    for(int i = 0; i<6;i++)
    {
        vPtr->push_back(i);
    }
}

void printVectorProperties(vector<int> *vPtr)
{
    cout<<"printing vector properties"<<endl;
    cout<<"Size : "<<vPtr->size()<<endl;
    cout<<"Capacity : "<<vPtr->capacity()<<endl;
    cout<<"Max_size : "<<vPtr->max_size()<<endl;
}

//see how capacity changes once size exceeds current capacity
void changeCapacityDemo(vector<int> *vPtr)
{
    printVectorProperties(vPtr);
    vPtr->push_back(12);
    vPtr->push_back(24);
    vPtr->push_back(36);
    printVectorProperties(vPtr);
}


void VectorExperiments(vector<int> *vPtr)
{
    fillVector(vPtr);
    printVector(vPtr);
    //changeCapacityDemo(vPtr);

    vPtr->resize(10, 157);
    
    //below with resize the vector to 0 sized
    vPtr->resize(0);
    printVector(vPtr);

    //ASIGN: assigns new values to vector elements by replaceing old ones. It can also change the size if needed
    //assign (size, value)
    vPtr->assign(7, 100);
    printVector(vPtr);

    vPtr->resize(0);
    //initialize vector with a set of values
    vPtr->assign({100,200,300});
    printVector(vPtr);

    vPtr->resize(0);
    int arr[] = {3,2,5};
    //initialize vector with an array
    vPtr->assign(arr, arr+4);
    printVector(vPtr);

    //SHRINK_TO_FIT()
    //Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
    printVectorProperties(vPtr);
    vPtr->shrink_to_fit();
    printVectorProperties(vPtr);

    //EMPTY()
    //checks if the vector is empty
    (vPtr->empty())?(cout<<"vector empty"):(cout<<"vector not empty");

    printVector(vPtr);
    vPtr->pop_back();
    printVector(vPtr);

    //reserve(n) – Requests that the vector capacity be at least enough to contain n elements
    vPtr->reserve(10);
    printVectorProperties(vPtr);



    
}

//MODIFIERS
void VectorModifiers()
{

//1) assign(SIZE, VALUE) - assigns new VALUE to the vector elements by replacing old ones, performed on SIZE number of elements
//2) push_back(value) - push element into a vector from the back
//3) pop_back() - pop or remove element from a vector from the back
//4) insert(ITERATOR, VALUE) - insert VALUE at position pointed by ITERATOR 
//5) erase(ITERATOR) - remove element from position pointed by ITERATOR and adjust rest of the elements
//6) swap()
//7) clear() - removes all elements of vector, making it size 0
//8) emplace(ITERATOR, VALUE) - inserts VALUE at position pointed by ITERATOR
//9) emplace_back(VALUE) - same as push_back() except the fact that it doesnt use auxilory memory for temporary variable


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
3) LIST CLASS
    -> NON-CONTIGUOUS MEMORY
    -> SLOW TRAVERSAL as compated to VECTOR/ARRAY
    -> FASTER INSERTION and DELETION as compated to VECTOR/ARRAY
    -> LIST (doubly linked list), FORWARD_LIST (singly linked list)
*/

void ListInit(list<int> *lPtr)
{
    cout<<"initializing the list.."<<endl;
    for(int i = 0;i<5;i++)
    {
        lPtr->push_back(i);
    }
}

void PrintList(list<int> *lPtr)
{
    cout<<"printing the list.."<<endl;
    for(auto itr = lPtr->begin(); itr != lPtr->end(); itr++)
    {
        cout<<*itr<<endl;
    }
}

void PrintListReverse(list<int> *lPtr)
{
    cout<<"printing list in reverse.."<<endl;
    auto itr = lPtr->rbegin();
    while(itr != lPtr->rend()) 
    {
        cout<<*itr<<endl;
        ++itr;
    }
}

void ListExperiments(list<int> *lPtr)
{
    ListInit(lPtr);
    PrintList(lPtr);
    lPtr->insert(lPtr->begin(), -1);
    lPtr->push_front(-2);
    
    PrintList(lPtr);
    //to be continued....
    //pop_front()
    lPtr->pop_front();
    PrintList(lPtr);

    //pop_back()
    lPtr->pop_back();
    PrintList(lPtr);
    PrintListReverse(lPtr);
    
    //insert()
    lPtr->insert(lPtr->begin(), 25);
    PrintList(lPtr);

    //erase()
    lPtr->erase(lPtr->begin());
    PrintList(lPtr);

    //assign()
    //lPtr->assign({23,23,23});
    //PrintList(lPtr);
    
    //reverse()
    lPtr->reverse();
    PrintList(lPtr);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
4) DEQUE CLASS (Double Ended Queue)
    -> SIMILAR to VECTORS but MORE EFFICIENT for insertion and deletion of elements
    -> CONTIGUOUS MEMORY is NOT GURANTEED
    -> SPECIAL QUEUE that allows INSERTION and DELETION on BOTH ENDS
    -> same functions as vectors + addional funcs for PUSH and POP operation on BOTH ENDS
    -> Accessing Elements O(1)
    -> Insert/delete element O(N)
    -> Insert/delete at any end O(1)
*/

void PrintDEQueue(deque<int> *deq)
{
    auto itr = deq->begin();
    cout<<"Printing DEQueue elements: "<<endl;
    for(;itr!=deq->end();itr++)
    {
        cout<<*itr<<endl;
    }
}

void DEqueExperiments(deque<int> *deqPtr)
{
    deqPtr->assign({1,2,3,4,5});
    PrintDEQueue(deqPtr);

    deqPtr->push_back(6);
    deqPtr->push_front(-1);
    PrintDEQueue(deqPtr);

    deqPtr->pop_back();
    deqPtr->pop_front();

    PrintDEQueue(deqPtr);
}

int main()
{
    //ArrayExperiments();
    vector<int> v;
    //VectorExperiments(&v);

    list<int> l;
    //ListExperiments(&l);

    deque<int> deq;
    DEqueExperiments(&deq);
    return 0;
}