#include<iostream>
#include<unordered_set>
#include<map>
using namespace std;

void PrintUnorderedSet(unordered_set<int> * us)
{
    cout<<"Printing Unordered set.."<<endl;
    for(auto itr = us->begin(); itr != us->end(); ++itr)
    {
        cout<<*itr<<endl;
    }
}

void UnorderedSetExperiments(unordered_set<int> * us)
{
    us->insert(1);
    us->insert(100);
    us->insert(200);
    us->insert(150);
    us->insert(125);

    PrintUnorderedSet(us);

    unordered_set<int>::iterator itr;
    //finding an element in unordered set
    itr = us->find(126);

    (itr == us->end())?(cout<<"126 is not present"):(cout<<"126 is present");
    cout<<endl;
}

void PrintUnorderedMap(unordered_map<int, string> *umPtr)
{
    cout<<"Printing contents of unordered_map.."<<endl;
    cout<<"KEY"<<"\t"<<"VALUE"<<endl;
    for(auto itr = umPtr->begin(); itr != umPtr->end(); ++itr)
    {
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }
}

void UnorderedMapExperiments(unordered_map<int, string> *umPtr)
{
    umPtr->insert({2, "two"});
    umPtr->insert({3, "three"});
    umPtr->insert({4, "four"});

    PrintUnorderedMap(umPtr);

    //auto itr = umPtr->find(4);
    unordered_map<int, string>::iterator itr = umPtr->find(3);
    (itr == umPtr->end())?(cout<<"3 not present"):(cout<<"3 is present");
    cout<<endl;
}

int main()
{
    unordered_set<int> us;
    UnorderedSetExperiments(&us);

    //UnorderedMultiSetExperiments();

    unordered_map<int, string> um;
    um[1] = "one";
    um[23] = "twenty three";
    UnorderedMapExperiments(&um);
    
    //UnorderedMultimapExperiments();
    return 0;
}