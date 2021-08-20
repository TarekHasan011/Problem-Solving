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
        int n; cin >> n;
        string str; cin >> str >> str;

        if(count(str.begin(),str.end(),'o')>0)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;

}
