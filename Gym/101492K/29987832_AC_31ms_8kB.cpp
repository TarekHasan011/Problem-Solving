#include<bits/stdc++.h>
using namespace std;
long long int answer(long long int n)
{
    vector< long long int > v;
    v.push_back(1);
    v.push_back(3);

    for(int i=2;i<=n;i++)
        v.push_back(3+(2*(v[i-1]-1)));
    return v[n];
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    long long int n; cin >> n;
    cout << answer(n) << endl;

    return 0;
}
