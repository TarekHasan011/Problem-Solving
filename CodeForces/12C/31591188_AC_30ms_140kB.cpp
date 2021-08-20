#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan


    int n,m; cin >> n >> m;
    vector< int > price(n);
    for(int &i : price) cin >> i;
    sort(price.begin(),price.end());

    map< string , int > mp;
    for(int i=0;i<m;i++)
    {
        string temp; cin >> temp;
        mp[temp]++;
    }
    vector< int > item;
    for(auto x: mp)
    {
        item.push_back(x.second);
    }
    sort(item.begin(),item.end(),greater< int>());

    int minimum_cost = 0;
    int it = 0;
    for(int x : item)
    {
        minimum_cost+=(price[it++]*x);
    }
    int maximum_cost = 0;
    it = price.size()-1;
    for(int x : item)
    {
        maximum_cost+=(price[it--]*x);
    }
    cout << minimum_cost << " " << maximum_cost << "\n";

    return 0;
}
