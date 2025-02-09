#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(76);

    for(auto itr = v.begin(); itr != v.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    
    sort(v.begin(), v.end());

    for(auto itr = v.begin(); itr != v.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}