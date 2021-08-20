#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    int n; cin >> n;
    if(n%2==0 && n!=2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
