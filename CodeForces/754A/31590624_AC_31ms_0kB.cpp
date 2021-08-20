#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n; cin >> n;
    vector< pair< int , int > > result;
    int current = 0;
    for(int i=0;i<n;i++)
    {
        int temp; cin >> temp;
        if(temp!=0)
        {
            result.push_back({current+1,i+1});
            current = i+1;
        }
    }

    if(result.size()==0)
        cout << "NO\n";
    else
    {
        if(result[result.size()-1].second!=n)
        {
            result[result.size()-1].second = n;
        }
        cout << "YES\n";
        cout << result.size() << "\n";
        for(pair< int , int > x : result)
            cout << x.first << " " << x.second << "\n";
    }
    return 0;

}
