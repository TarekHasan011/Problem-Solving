#include<bits/stdc++.h>
using namespace std;
bool match(vector< int >&v, vector<int> &temp)
{
    for(int i=0;i<temp.size();i++)
    {
        if(v[i]!=temp[i])
            return false;
    }
    return true;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    vector< int > v0(n),v1(n),v2;
    for(int i=1;i<=n;i++) v2.push_back(i);
    for(int i=0;i<n;i++) cin >> v0[i];
    for(int i=0;i<n;i++) cin >> v1[i];

    int a,b;
    int it = 1;
    do{
        if(match(v2,v0))
            a = it;
        if(match(v2,v1))
            b = it;
        it++;

    }while(next_permutation(v2.begin(),v2.end()));
    cout << abs(a-b) << "\n";
    return 0;
}
