#include<bits/stdc++.h>
using namespace std;
bool possible(string a, string b, string c)
{
    map< char , int > mp;
    for(char x : c)
        mp[x]++;
    for(char x : a)
    {
        if(mp[x]>0)
            mp[x]--;
        else
            return false;
    }
    for(char x : b)
    {
        if(mp[x]>0)
            mp[x]--;
        else
            return false;
    }

    for(auto x : mp)
    {
        if(x.second!=0)
            return false;
    }
    return true;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan

    string a,b,c;
    cin >> a >> b >> c;
    cout << (possible(a,b,c)? "YES" : "NO") << endl;

    return 0;
}
