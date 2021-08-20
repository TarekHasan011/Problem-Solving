#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int tt; cin >> tt;
    while(tt--)
    {
        int n,k; cin >> n >> k;
        vector< int > v(n);
        for(int &i : v) cin >> i;
        cout << *max_element(v.begin(),v.end())-*min_element(v.begin(),v.end()) << "\n";
    }
    return 0;

}
