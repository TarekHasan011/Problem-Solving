#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifdef TarekHasan
    freopen("input.txt","r",stdin);
#endif // TarekHasan
    int n;
    cin >> n;
    map< int, int > mp;
    int four=0, two = 0, six = 0, eight = 0;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
        if(mp[temp]==2)
            two++;
        else if(mp[temp]==4)
        {
            two-=1;
            four+=1;
        }
        else if(mp[temp]==6)
        {
            four-=1;
            six+=1;
        }
        else if(mp[temp]==8)
        {
            six-=1;
            eight+=1;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if(c=='+')
        {
            int temp = x;
            mp[temp]++;
            if(mp[temp]==2)
                two++;
            else if(mp[temp]==4)
            {
                two-=1;
                four+=1;
            }
            else if(mp[temp]==6)
            {
                four-=1;
                six+=1;
            }
            else if(mp[temp]==8)
            {
                six-=1;
                eight+=1;
            }
        }
        else
        {
            int temp = x;
            if(mp[temp]==2)
                two-=1;
            else if(mp[temp]==4)
            {
                four-=1;
                two+=1;
            }
            else if(mp[temp]==6)
            {
                six-=1;
                four+=1;
            }
            else if(mp[temp]==8)
            {
                eight-=1;
                six+=1;
            }
            mp[temp]--;
        }

        if((two>=2 && four>=1) || (two>=1 && six>=1) || (four>=1 && six>=1) || (six>=2) || (four>=2) || (eight>=1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
