#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    int n; cin >> n;
    vector< int > result;
    for(int i=1;n-i>=0;i++)
    {
        result.push_back(i);
        n-=i;
    }
    if(n)
        result[result.size()-1]+=n;

    cout << result.size() << "\n";
    for(int x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}
