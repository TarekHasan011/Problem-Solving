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
        string str; cin >> str;
        map< char , int > mp;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]] = i;
        }
        if(mp['c']<mp['p'] || mp['c']<mp['z'] || mp['c']<mp['e'] || mp['p']<mp['z'])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;

}
