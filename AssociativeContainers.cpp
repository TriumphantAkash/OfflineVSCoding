//ASSOCIATIVE CONTAINERS IMPLEMENT SORTED DATA STRUCTURES THAT CAN BE QUICKLY SEARCHED
// O(LOG N) complexity
//set, multiset
//map, multimap
#include<iostream>
#include<set>
#include<map>

using namespace std;

void PrintSet(set<int, greater<int> > *setPtr)
{
    cout<<"Printing set elements.."<<endl;
    for(auto itr = setPtr->begin(); itr != setPtr->end(); itr++)
    {
        cout<<*itr<<endl;
    }
}

/*
    -> each eleemnt in the set has to be unique as it's used to identify the element
    -> elements are always sorted
    -> sets follow BST implementation
    -> values are unindexed
    -> insertion/deletion/search complexity O(N)

*/
void SetExperiments(set<int, greater<int> > *setPtr)
{
    int x;
    setPtr->insert(23);
    setPtr->insert(26);
    setPtr->insert(12);
    PrintSet(setPtr);

    setPtr->insert(26);
    PrintSet(setPtr);
    cout<<"number of occurances of 12 : "<<setPtr->count(12)<<endl;
    do{
        cout<<"enter a value to find in the set..(enter 0 to exit)"<<endl;
        cin>>x;
        if(!x)
            break;
        else
            (setPtr->find(x) == setPtr->end())?(cout<<"not present"<<endl):(cout<<"present"<<endl);
    }while(1);
}

void PrintMultiSet(multiset<int> *msPtr)
{
    cout<<"Pritning Multiset Elements: "<<endl;
    multiset<int>::iterator itr = msPtr->begin();
    for(;itr!=msPtr->end();++itr)
    {
        cout<<*itr<<endl;
    }
}
void MultisetExperiments(multiset<int> *msPtr)
{
    msPtr->insert(200);
    msPtr->insert(100);
    msPtr->insert(500);
    msPtr->insert(300);
    msPtr->insert(300);

    PrintMultiSet(msPtr);
}

void PrintMap(map<string, int> *mPtr)
{
    cout<<"Printing Map Elements.."<<endl;
    map<string, int>::iterator itr = mPtr->begin();
    for(; itr !=mPtr->end(); ++itr)
    {
        cout<<"key : "<<itr->first<<endl;
        cout<<"value : "<<itr->second<<endl;
        cout<<endl;
    }
}

void MapExperiments(map<string, int> *mPtr)
{
    auto itr_tmp = mPtr->begin();
    mPtr->insert(itr_tmp, {"hundred", 100});
    mPtr->insert({ "one", 1 });
    mPtr->insert({ "two", 2 });
    mPtr->insert({"three", 3});
    mPtr->insert({"four", 4});
    mPtr->insert({"five", 5});
    //this will not be inserted and the return iterator will have a reference of existing key value pair
    mPtr->insert({"four", 6});
    PrintMap(mPtr);
    string x;

    cout<<"number of occurances of two : "<<mPtr->count("two")<<endl;

    //find demo
    itr_tmp = mPtr->find("three");
    if(itr_tmp == mPtr->end())
    {
        cout<<"three not present"<<endl;
    }
    else
    {
        cout<<"three present | key : "<<itr_tmp->first<<" and value : "<<itr_tmp->second;
    }
    
}

void PrintMultiMap(multimap<int, string> *mmPtr)
{
    multimap<int, string>::iterator itr = mmPtr->begin();
    cout<<"Printing multimap data.."<<endl;
    cout<<"KEY"<<"\t"<<"VALUE"<<endl;
    for(;itr != mmPtr->end(); ++itr)
    {
        cout<<itr->first<<"\t";
        cout<<itr->second<<endl;
    }
}

void MultimapExperiments(multimap<int, string> *mmPtr)
{
    mmPtr->insert({3, "three"});
    mmPtr->insert({5, "five"});
    mmPtr->insert({2, "two"});
    mmPtr->insert({-1, "minus one"});
    mmPtr->insert({100, "hundred"});
    mmPtr->insert({25, "twenty five"});
    mmPtr->insert({26, "twenty six"});
    mmPtr->insert({-1, "hein?"});

    PrintMultiMap(mmPtr);
}

int main()
{
    //greater<int> is used to maintain the set in decreasing order
    //set<int, greater<int> > s;
    //SetExperiments(&s);
    

    //MULTISET are SIMILAR to SET with one exception that you can store duplicates in them
    //multiset<int> ms;
    //MultisetExperiments(&ms);

    //map<string, int> m;
    //MapExperiments(&m);
    //MAP (same as set, but store a key value pair with unique keys)

    multimap<int, string> mm;
    MultimapExperiments(&mm);
    //MULTIMAP (same as multiset i.e. allows entries with duplicate keys)
    return 0;
}